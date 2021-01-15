// The Vowel Code
// Step 1: Create a function called encode() 
// to replace all the lowercase vowels in a 
// given string with numbers according to the following pattern:

// a -> 1
// e -> 2
// i -> 3
// o -> 4
// u -> 5

// For example, encode("hello") would return "h2ll4". 
// There is no need to worry about uppercase vowels in this kata.

// Step 2: Now create a function called decode()
//  to turn the numbers back into vowels according to the same
//   pattern shown above.

function encode(string) {
    const encode = {
        a: 1,
        e: 2,
        i: 3,
        o: 4,
        u: 5
    }
    const encoded = string.split('').map(vowel => {
        return (vowel in encode) ? encode[vowel] : vowel;
    }).join('');
    return encoded;
}

function decode(string) {
    const encode = {
        1: 'a',
        2: 'e',
        3: 'i',
        4: 'o',
        5: 'u'
    }
    const decoded = string.split('').map(vowel => {
        return (vowel in encode) ? encode[vowel] : vowel;
    }).join('');
    return decoded
}