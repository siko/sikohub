import "./App.css";

const App = () => {
  const name = "John";
  const isNameShowing = true;

  return <div className="App">Hello {isNameShowing ? name : "someone"} !</div>;
};

export default App;
