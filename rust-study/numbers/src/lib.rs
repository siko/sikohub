pub fn say_hello() {
    println!("Hello,World!");
}

pub fn simple_print() {
    let numbers = [1,2,3,4,5];
    for n in numbers.iter()  {
        print!("{}",n);
    }
}

pub fn print(limit: u8) {
    let numbers = generate_sequence(limit);
    output_sequence(&numbers);
}

fn generate_sequence(limit: u8) -> Vec<u8>{
    // let mut numbers = Vec::new();
    // for n in 1..=limit  {
    //     numbers.push(n);
    // }
    // numbers

    (1..=limit).collect()
}

fn output_sequence(numbers: &[u8]) {
    for n in numbers  {
        print!("{} \n", n);
    }
}

#[test]
fn generate_sequence_should_work() {
    let result = generate_sequence(3);
    assert_eq!(result, &[1,2,3]);
}
