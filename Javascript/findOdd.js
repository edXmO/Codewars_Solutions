//  6Kyu

// Given an array of integers, find the one that appears an odd number of times.

// There will always be only one integer that appears an odd number of times.

function findOdd(A) {
    let oddOrNot = new Object();
    A.forEach(elem => {
        if (!oddOrNot.hasOwnProperty(elem)) {
            oddOrNot[elem] = 0;
        }
        if (oddOrNot.hasOwnProperty(elem)) {
            oddOrNot[elem] += 1;
        }
    })
    for (let key in oddOrNot) {
        if (oddOrNot[key] % 2 !== 0) {
            return parseInt(key);
        }
    }
}

findOdd([20, 1, -1, 2, -2, 3, 3, 5, 5, 1, 2, 4, 20, 4, -1, -2, 5]); //5
findOdd([1, 1, 1, 1, 1, 1, 10, 1, 1, 1, 1]); // 10

