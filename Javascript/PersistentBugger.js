// Write a function, persistence, that takes in a positive parameter num
// and returns its multiplicative persistence, 
// which is the number of times you must multiply the digits
//  in num until you reach a single digit.

function persistence(num) {
    let steps = 0;
    let integer = num.toString();
    while (integer.length > 1) {
        steps++
        let mapped = integer.split('').reduce((acc, curr) => parseInt(acc) * parseInt(curr));
        integer = mapped.toString();
    }
    return steps;
}

persistence(39) // Output '3';