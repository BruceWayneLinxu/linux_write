#include "Point.h"
#include <stdio.h>
int main()
{
  point a = {5.0, 4.0}, b = {1.2, 3.4};
  float result = 0.0;
  result = distance(a, b);
  printf("distance from a to b is %f\n", result);
  return 0; 
}
