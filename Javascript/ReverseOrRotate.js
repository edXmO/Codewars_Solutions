// 6kyu

// The input is a string str of digits.
//  Cut the string into chunks
//   (a chunk here is a substring of the initial string)
//    of size sz (ignore the last chunk if its size is less than sz).

// If a chunk represents an integer such as
//  the sum of the cubes of its digits is divisible by 2, 
//  reverse that chunk; otherwise rotate it to the left by one position.
//   Put together these modified chunks and return the result as a string.

// If

// sz is <= 0 or if str is empty return ""
// sz is greater (>) than the length of str it is 
// impossible to take a chunk of size sz hence return "".

function revrot(str, sz) {
    const chunks = new Array();
    let size = sz;
    if (!str) {
        return "";
    }
    for (let i = 0; i < str.length; i += sz) {
        var chunk = str.slice(i, size);
        if (!chunk.length < sz) {
            const revOrRotChunk = chunk
                .split('')
                .reduce((acc, curr) => Math.pow(parseInt(acc), 3) + Math.pow(parseInt(curr), 3));
            if (revOrRotChunk % 2 === 0) {
                if (chunk.length < 2) {
                    chunks.push(chunk);
                }
                let reversedChunk = chunk
                    .substring(chunk.length - 1)
                    + chunk.substring(1, chunk.length - 1)
                    + chunk.substring(0, 1)
                chunks.push(reversedChunk);
            } else {
                //Function to move each character one position to the left,
                let rotatedChunk = chunk.slice(1) + chunk.slice(0, 1);
                chunks.push(rotatedChunk);
            }
            size += sz;
        }
    }
    return chunks.join('');
}

// revrot("123456987654", 6);  //"234561
//         "987654"           876549"

