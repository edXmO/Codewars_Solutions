// Greed is a dice game played with five six-sided dice. Your mission, should
// you choose to accept it, is to score a throw according to these rules. You
// will always be given an array with five six-sided dice values.
//
//  Three 1's => 1000 points
//  Three 6's =>  600 points
//  Three 5's =>  500 points
//  Three 4's =>  400 points
//  Three 3's =>  300 points
//  Three 2's =>  200 points
//  One   1   =>  100 points
//  One   5   =>   50 point
// A single die can only be counted once in each roll. For example, a given "5"
// can only count as part of a triplet (contributing to the 500 points) or as a
// single 50 points, but not both in the same roll.
//
// Example scoring
//
//  Throw       Score
//  ---------   ------------------
//  5 1 3 4 1   250:  50 (for the 5) + 2 * 100 (for the 1s)
//  1 1 1 3 1   1100: 1000 (for three 1s) + 100 (for the other 1)
//  2 4 4 5 4   450:  400 (for three 4s) + 50 (for the 5)
// In some languages, it is possible to mutate the input to the function. This
// is something that you should never do. If you mutate the input, you will not
// be able to pass all the tests.
//

// ################################

// ### Summary
// Using an array of 5 die rolls, calculate the highest possible score. A single
// die can only be counted once for a rule in each roll.
//
// ### Observations
// - rolls are positive (no negatives or 0's)
// - counting, combinatorics formula??
// - score is 0 if the roll does not contain 1's or 5's and there are any
// combination of less than three 2, 3, 4 or 6
//    - can total sum of rolls determine existance of score????? gcd?????
// - order of dice rolls does not matter
//    - BUT if rolls are ordered we can easily check for triplets of 2,3,4,5,6
//    and 1's
// - each die can only be accounted for once
//   - mark a die as used once it's part of highest combination ???

// ##################################

// ### Example
// e.g: 5 1 3 4 1
// Decision: Find the highest possible score given the rolls
//
// Store rolls hit in associative array: {
//  1: 0,
//  2: 0,
//  3: 0,
//  4: 0,
//  5: 0,
//  6: 0,
// }
//
// What are my actions?
//
// Traverse the array, for each ith element:
//  - Populate the count for each die value

int score(const int dice[5]) {
  int score = 0;
  int counter[7] = {0, 0, 0, 0, 0, 0, 0};

  for (int i = 0; i < 5; i++) {
    counter[dice[i]]++;
  }

  for (int i = 1; i < 7; i++) {
    if (i == 1) {
      while (counter[i] > 0) {
        if (counter[i] % 3) {
          score += 1000;
        }
      }
    }
  }

  return 0; //  <----  hajime!
}
