import ListGroup from "./commpoents/ListGroup";

function App() {
  const items = ["New York", "San Francisco", "Tokyo", "London", "Paris"];

  const handleSeclectItem = (item: string) => {
    console.log(item);
  };

  return (
    <div>
      <ListGroup
        items={items}
        heading={"Cities"}
        onSelectItem={handleSeclectItem}
      />
    </div>
  );
}

export default App;
