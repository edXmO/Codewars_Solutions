// How can you tell an extrovert from an introvert at NSA?
// Va gur ryringbef, gur rkgebireg ybbxf ng gur BGURE thl'f fubrf.
//
// I found this joke on USENET, but the punchline is scrambled. Maybe you can decipher it?
// According to Wikipedia, ROT13 is frequently used to obfuscate jokes on USENET.
//
// For this task you're only supposed to substitute characters. Not spaces, punctuation, numbers, etc.
//
// Test examples:
//
// "EBG13 rknzcyr." -> "ROT13 example."
//
// "This is my first ROT13 excercise!" -> "Guvf vf zl svefg EBG13 rkprepvfr!"
//
// ##############  Notes
//
// Encode a string according to rot13
// ROT13 ("rotate by 13 places") is a simple substitution cipher that replace a leltter with the 13th letter after it in the latin alphabet
//
// ##### Observations
// - If we want the corresponding rotated character we need to sum + 13.
// - We skip numbers
// - We need to handle uppercase and lowercase elements
// - In ASCII there's a difference of 32 between a lowercase character and it's uppercase counterpart (e.g 'a' = 97, 'A' = 65)
//
// For each ith chacracter:
//  What actions can I do?
//    - Determine if the ith element is alphanumeric
//      - True:
//        - Get the ith character of input string
//          - normalize the character to a 0-25 range (char - base)
//          - add 13 to the character
//          - mod26 - wrap if value > 26
//          - add base again to conver to ASCII value
//        - Add the rotated character to the output string
//
//      - False -> actions:
//         - copy character as is to output
//         - advance to next character
//
//   - return the rotated string

#include <ctype.h>
#include <stdio.h>
#include <string.h>

char *rot13 (char *str_out, const char *str_in)
{
  char *p_out = str_out;
  const char *p_in = str_in;

  while(*p_in != '\0') {
    if(isalpha(*p_in)) {
      char base = isupper(*p_in) ? 'A' : 'a';
      *p_out = ((*p_in - base + 13) % 26) + base;
    } else {
      // Copy nonalpha as is
      *p_out = *p_in; 
    }

    p_in++;
    p_out++;
  }

  *p_out = '\0';
  return str_out;
}
