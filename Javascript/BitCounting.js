// Write a function that takes an integer as input, 
// and returns the number of bits that are equal to one in 
// the binary representation of that number. 
// You can guarantee that input is non-negative.

// Example: The binary representation of 1234 is 10011010010, so the function should return 5 in this case

var countBits = function (n) {
    let integer = n;
    let bit = [];
    while (integer > 0) {
        let mod = integer % 2;
        bit.push(mod);
        integer = Math.floor(integer / 2);
    }
    let binary = bit.filter(numberOfOnes => numberOfOnes === 1 ? true : false).length
    return binary
};

// (countBits(7) => 3
// (countBits(9) => 2