// #### Description
// Write a function that accepts a string, and returns true if it is in the
// form of a valid phone number.
// Assume that any integer from 0-9 in any of the spots will produce a valid
// phone number
//
// #### Constraints
//  - every string of not exactly 14 characters is automatically invalid
//  - every valid number must start with a left parenthesis
//  - every valid number cannot contain an alphabet letter, only numbers are
//  allowed
//
// #### Observations
//
// #### Summary
// Given a string, determine if it contains a valid phone number
// Let's go through an example:
// (123) 456-7890
//
// - String starts with left paren
//   True:
//     advance until closing parenthesis
//       prefix_counter = 0
//       for each character, actions:
//         isdigit
//           True:
//             prefix_counter++;
//           False:
//             // not a valid number
//             return false
//
//      // after closing parenthesis there must be an space
//      // after space there must be exactly 3 digits
//      // after three digits there must be a dash
//      // after the dash there must be exactly four digits
//   False:
//     return false

#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool valid_phone_number(const char *number) {
  if (strlen(number) != 14)
    return false;
  if (*number != '(')
    return false;

  for (int i = 1; i <= 3; i++) {
    if (!isdigit(number[i]))
      return false;
  }

  char *next = strchr(number, ')');
  if (next == NULL || next - number != 4)
    return false;

  next++;
  if (!isspace(*next))
    return false;

  next++;
  for (int i = 0; i < 3; i++) {
    if (!isdigit(*next))
      return false;
    next++;
  }

  if (*next != '-')
    return false;

  next++;
  for (int i = 0; i < 4; i++) {
    if (!isdigit(*next))
      return false;
    next++;
  }

  return true;
}
