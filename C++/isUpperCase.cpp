#include <string>
bool is_uppercase(const std::string &s) {
  int counter = 0;
  typedef std::string::size_type str_sz;
  for(str_sz i = 0; i < s.size(); ++i)
  {
    char c = s[i];
    if(islower(c)) ++counter;
  }
  return counter > 0 ? false : true;
}