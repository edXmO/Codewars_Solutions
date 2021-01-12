// # Data Reverse

// A stream of data is received and needs to be reversed.

// Each segment is 8 bits long, meaning the order of these segments needs to be reversed, for example:

// 11111111  00000000  00001111  10101010
//  (byte1)   (byte2)   (byte3)   (byte4)
// should become:

// 10101010  00001111  00000000  11111111
//  (byte4)   (byte3)   (byte2)   (byte1)

// The data is given in an array

function dataReverse(data) {
    let byteLength = 8;
    let bytes = [];
    for (let i = data.length; i > 0; i -= byteLength) {
        bytes.push(data.splice(data.length - byteLength, data.length));
    }
    let reversedData = [].concat.apply([], bytes);
    return reversedData;
}