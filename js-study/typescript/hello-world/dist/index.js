"use strict";
var _a;
console.log('Hello World');
let age = 20;
if (age < 50)
    age += 10;
console.log(age);
let sales = 123456789;
let course = 'TypeScript';
let is_published = true;
let level;
level = 1;
level = 'a';
function render(document) {
    console.log(document);
}
let numbers = [1, 2, 3];
numbers.forEach(n => n.toString);
let user = [1, 'hi'];
const small = 1;
const medium = 2;
const large = 3;
var Size;
(function (Size) {
    Size[Size["Small"] = 1] = "Small";
    Size[Size["Medium"] = 2] = "Medium";
    Size[Size["Large"] = 3] = "Large";
})(Size || (Size = {}));
;
let mySize = Size.Medium;
console.log(mySize);
function calculateTax(income, taxYear = 2022) {
    if ((taxYear || 2022) < 2002)
        return income * 1.2;
    return income * 1.3;
}
console.log(calculateTax(100).toString());
let employee = {
    id: 1,
    name: '',
    retire: (date) => {
        console.log(date);
    }
};
employee.name = 'hi';
function kgToLbs(weight) {
    if (typeof weight === 'number') {
        return weight * 2.2;
    }
    else {
        return parseInt(weight) * 5.5;
    }
}
console.log(kgToLbs(10), kgToLbs('10kg'));
let textBox = {
    drag: () => { },
    resize: () => { }
};
let quantity = 100;
function greet(name) {
    if (name)
        console.log(name.toUpperCase());
    else
        console.log('Hola!');
}
greet(null);
function getCustomer(id) {
    return id === 0 ? null : { birthday: new Date() };
}
let customer = getCustomer(1);
console.log((_a = customer === null || customer === void 0 ? void 0 : customer.birthday) === null || _a === void 0 ? void 0 : _a.getFullYear());
//# sourceMappingURL=index.js.map