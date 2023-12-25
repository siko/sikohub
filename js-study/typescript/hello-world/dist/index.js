"use strict";
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
function calculateTax(income, taxYear) {
    if ((taxYear || 2022) < 2002)
        return income * 1.2;
    return income * 1.3;
}
console.log(calculateTax(100).toString());
//# sourceMappingURL=index.js.map