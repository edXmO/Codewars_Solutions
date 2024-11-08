// Write a function that accepts a string, and returns the same string with all
// even indexed characters in each word upper cased, and all odd indexed
// characters in each word lower cased. The indexing just explained is zero
// based, so the zero-ith index is even, therefore that character should be
// upper cased and you need to start over for each word.
//
// The passed in string will only consist of alphabetical characters and
// spaces(' '). Spaces will only be present if there are multiple words. Words
// will be separated by a single space(' ').

// Examples:
// "String" => "StRiNg"
// "Weird string case" => "WeIrD StRiNg CaSe"
//

// ##### Notes
//
// #### Constraints
// - only alphabetical characters are allowed and spaces
// - spaces are only pressent in case of multi-word string
// - word's are separated by a single string
//
//
// #### Decisions
// word_index = 0
// Starting from the first characters, what are my actions
//  - take the character
//   - check character
//     - if isspace, actions:
//        - reset word_index
//        - advance character
//        - next loop
//     - if is character, actions:
//        - iseven -> toupper
//        - isodd -> tolower
//        - advance position
//        - advance character
//        - next loop
//

#include <ctype.h>
char *to_weird_case(char *string) {
  int word_index;
  word_index = 0;

  for (int pos = 0; string[pos] != '\0'; pos++) {
    if (isspace(string[pos])) {
      word_index = 0;
      continue;
    }
    if (isalpha(string[pos])) {
      if (word_index % 2 == 0) {
        string[pos] = toupper(string[pos]);
      } else {
        string[pos] = tolower(string[pos]);
      }
      word_index++;
    }
  }

  return string;
}
