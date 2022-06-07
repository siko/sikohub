#[macro_use]
extern crate actix_web;

use actix_web::{
    error::{Error, InternalError, JsonPayloadError},
    middleware, web, App, HttpRequest, HttpResponse, HttpServer, Result,
};
use serde::{Deserialize, Serialize};

use std::{cell::Cell};
use std::sync::atomic::{AtomicUsize, Ordering};
use std::sync::{Arc, Mutex};

static SERVER_COUNTER: AtomicUsize = AtomicUsize::new(0);
const LOG_FORMAT: &'static str = r#""%r" %s %b "%{User-Agent}i" %D"#;

struct AppState {
    server_id: usize,
    request_count: Cell<usize>,
    messages: Arc<Mutex<Vec<String>>>,
}

pub struct MessageApp {
    port: u16,
}


#[derive(Serialize)]
struct IndexResponse {
    server_id: usize,
    request_count: usize,
    messages: Vec<String>,
}

#[derive(Deserialize)]
struct PostInput {
    message: String,
}

#[derive(Serialize)]
struct PostResponse {
    server_id: usize,
    request_count: usize,
    message: String,
}

#[derive(Serialize)]
struct PostError {
    server_id: usize,
    request_count: usize,
    error: String,    
}

#[derive(Serialize)]
struct LookupResponse {
    server_id: usize,
    request_count: usize,
    result: Option<String>,
}

impl MessageApp {

    pub fn new(port: u16) -> Self {
        MessageApp { port: port + 1 }
    }

    pub fn run(&self) -> std::io::Result<()> {
        let messages = Arc::new(Mutex::new(vec![]));
        println!("Starting http server: 127.0.0.1:{}", self.port);
        HttpServer::new(move || {
            App::new()
                .data(AppState{
                    server_id: SERVER_COUNTER.fetch_add(1, Ordering::SeqCst),
                    request_count: Cell::new(0),
                    messages: messages.clone(),
                })
                .wrap(middleware::Logger::new(LOG_FORMAT))
                .service(index)
                .service(
                    web::resource("/send")
                    .data(
                        web::JsonConfig::default().limit(4096)
                        .error_handler(post_error),
                    )
                    .route(web::post().to(post)),
                )
                .service(clear)
                .service(lookup)
                
        })
        .bind(("127.0.0.1", self.port))?
        .workers(8)
        .run()
    }
}


#[get("/")]
fn index(state: web::Data<AppState>) -> Result<web::Json<IndexResponse>>{
    // let hello = req.headers().get("hello").and_then(|v| v.to_str().ok()).unwrap_or_else(|| "world");
    // Ok(web::Json(IndexResponse {
    //     message: hello.to_owned(),
    // }))

    let request_count = state.request_count.get() + 1;
    state.request_count.set(request_count);
    let ms = state.messages.lock().unwrap();

    Ok(web::Json(IndexResponse {
        server_id: state.server_id,
        request_count,
        messages: ms.clone(),
    }))

}

fn post(msg: web::Json<PostInput>, state: web::Data<AppState>) -> Result<web::Json<PostResponse>> {
    let request_count = state.request_count.get() + 1;
    state.request_count.set(request_count);

    let mut ms = state.messages.lock().unwrap();
    ms.push(msg.message.clone());

    Ok(web::Json(PostResponse {
        server_id: state.server_id,
        request_count,
        message: msg.message.clone(),
    }))
}

#[post("/clear")]
fn clear(state: web::Data<AppState>) -> Result<web::Json<IndexResponse>>{
    let request_count = state.request_count.get() + 1;
    state.request_count.set(request_count);

    let mut ms = state.messages.lock().unwrap();
    ms.clear();

    Ok(web::Json(IndexResponse {
        server_id: state.server_id,
        request_count,
        messages: vec![],
    }))


}

fn post_error(err: JsonPayloadError, req: &HttpRequest) -> Error {
    let extns = req.extensions();
    let state = extns.get::<web::Data<AppState>>().unwrap();

    let request_count = state.request_count.get() + 1;
    state.request_count.set(request_count);

    let post_error = PostError {
        server_id: state.server_id,
        request_count,
        error: format!("{}", err),
    };

    InternalError::from_response(err, HttpResponse::BadRequest().json(post_error)).into()

}

#[get("/lookup/{index}")]
fn lookup(state: web::Data<AppState>, idx: web::Path<usize>) -> Result<web::Json<LookupResponse>> {
    let request_count = state.request_count.get() + 1;
    state.request_count.set(request_count);

    let ms = state.messages.lock().unwrap();
    let result = ms.get(idx.into_inner()).cloned();

    Ok(web::Json(LookupResponse {
        server_id: state.server_id,
        request_count,
        result,
    }))

}

