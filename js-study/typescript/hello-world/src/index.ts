console.log('Hello World');

let age: number = 20;
if (age <50)
    age += 10;

console.log(age);


let sales: number = 123_456_789;
let course: string = 'TypeScript';
let is_published: boolean = true;

let level;

level = 1;
level = 'a';

function render(document: any){
    console.log(document);
    
}

let numbers: number[] = [1, 2, 3];

numbers.forEach(n => n.toString);



let user: [number, string] = [1, 'hi'];

const small =1;
const medium = 2;
const large = 3;

enum Size {Small = 1, Medium , Large };

let mySize: Size = Size.Medium;
console.log(mySize);


function calculateTax(income: number, taxYear: number = 2022): number {

    // let x;
    
    if ((taxYear || 2022) <2002)
        return income * 1.2;

    return income * 1.3;
    
}

console.log(calculateTax(100).toString());

type Employee = {
    readonly id: number,
    name: string,
    retire:(date: Date) => void
}

let employee: Employee = {
    id: 1, 
    name: '',
    retire:(date:Date) => {
        console.log(date);
        
    }
};

employee.name = 'hi';

