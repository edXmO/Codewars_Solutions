#include <math.h>
bool isDivideBy(int number, int a, int b)
{
  return (number % abs(a) == 0 && number % abs(b) == 0) ? true : false;
}