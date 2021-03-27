let firstPos = "ADGJMPTW*#1 ";
let secondPos = "BEHKNQUX0";
let thirdPos = "CFILORVY";
let fourthPos = "SZ234568";
let fifthPos = "79"
  
const KEYPRESS_PAD = (posOne, posTwo, posThree, posFour, fifthPos) => {
  return [
    {1: posOne},
    {2: posTwo},
    {3: posThree},
    {4: posFour},
    {5: fifthPos}
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
