import Button from "./commpoents/Button";

const App = () => {
  return (
    <div>
      <Button onClick={() => console.log("Clicked")}>My Button</Button>
    </div>
  );
};

export default App;
