// Reverse every other word in a given string,
// then return the string.
// Throw away any leading or trailing whitespace,
// while ensuring there is exactly one space between each word.
// Punctuation Punctuation marks should be treated as 
// if they are a part of the word in this kata.


function reverse(str) {
    return str.trim().split(' ').map((word, i) => {
        return i % 2 !== 0 ? word.split('').reverse().join('') : word;
    }).join(' ');
}

// reverse("Reverse this string, please!"), "Reverse siht string, !esaelp")
// reverse("I really don't like reversing strings!"),"I yllaer don't ekil reversing !sgnirts")