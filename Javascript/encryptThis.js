// 6Kyu
// Description:
// Encrypt this!

// You want to create secret messages which can be deciphered by the Decipher this! kata.
// Here are the conditions:

// Your message is a string containing space separated words.
// You need to encrypt each word in the message using the following rules:
// The first letter needs to be converted to its ASCII code.
// The second letter needs to be switched with the last letter
// Keepin' it simple: There are no special characters in input.

var encryptThis = function(text) {
    const encrypt = text.split(' ').map(word => {
      return word.split('').map((letter, i) => {
        let wordArr = word.split('');
        return i == 0 ? letter.charCodeAt(i) : i == 1 ? wordArr[wordArr.length - 1] : i == wordArr.length - 1 ? wordArr[1] : letter;
        }).join('')
      }).join(' ');
    return encrypt;
}
        