// 6kyu

// Prior to the development of T9 (predictive text entry) systems,
// the method to type words was called "multi-tap" and involved pressing
// a button repeatedly to cycle through the possible values.

// For example, to type a letter "R" you would press the 7 key three times
// (as the screen display for the current character cycles through P->Q->R->S->7).
// A character is "locked in" once the user presses a different key or pauses
// for a short period of time (thus, no extra button presses are required beyond
// what is needed for each letter individually). The zero key handles spaces,
// with one press of the key producing a space and two presses producing a zero.

// In order to send the message "WHERE DO U WANT 2 MEET L8R" a teen would have to
// actually do 47 button presses. No wonder they abbreviated.

// For this assignment, write a module that can calculate the amount of button
//  presses required for any phrase. Punctuation can be ignored for this exercise.
// Likewise, you can assume the phone doesn't distinguish between upper/lowercase
// characters (but you should allow your module to accept input in either for
// convenience).

// Hint: While it wouldn't take too long to hard code the amount of keypresses 
// for all 26 letters by hand, try to avoid doing so!
// (Imagine you work at a phone manufacturer who might be testing out
// different keyboard layouts, and you want to be able to test new ones rapidly.)

let firstPos = "ADGJMPTW*#1 ";
let secondPos = "BEHKNQUX0";
let thirdPos = "CFILORVY";
let fourthPos = "SZ234568";
let fifthPos = "79"
  
const KEYPRESS_PAD = (posOne, posTwo, posThree, posFour, posFifth) => {
  return [
    {1: posOne},
    {2: posTwo},
    {3: posThree},
    {4: posFour},
    {5: posFifth}
  ]
}

const pad = KEYPRESS_PAD(firstPos, secondPos, thirdPos, fourthPos, fifthPos);

function presses(phrase) {   
  let counter = phrase.split('').map(letter => {
    return pad.map((position, idx) => {
      return position[idx + 1].includes(letter.toUpperCase()) ? idx + 1 : null;
    })
  })
  .map(elem => elem.filter(strokes => strokes !== null))
  .reduce((curr, acc) => parseInt(curr) + parseInt(acc))
  return typeof counter === "object" ? counter[0] : counter;
}
