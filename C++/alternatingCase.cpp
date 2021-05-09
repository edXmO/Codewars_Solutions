string to_alternating_case(const string str)
{
	typedef std::string::size_type str_sz;
  std::string reversed = "";
  for(str_sz i = 0; i < str.size(); ++i)
  {
    char c = str[i];
    isupper(c) ? reversed.push_back(tolower(c)) : reversed.push_back(toupper(c));
  }
  return reversed;
}