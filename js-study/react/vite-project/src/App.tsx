import ListGroup from "./commpoents/ListGroup";

function App() {
  const items = ["New York", "San Francisco", "Tokyo", "London", "Paris"];

  return (
    <div>
      <ListGroup items={items} heading={"Cities"} />
    </div>
  );
}

export default App;
