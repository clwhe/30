/* clwhe */

#include <stdio.h>

int main(void)
{
  int m;
  int n;
  int side1;
  int side2;
  int hypot;
  
  printf("Please enter two integers with the first larger than the second > ");
  scanf("%d %d", &m, &n);
  
  side1 = m * m - n * n;
  side2 = 2 * m * n;
  hypot = m * m + n * n;
  
  printf("The Pythagorean triple of %d and %d is %d, %d, and %d.\n",
         m, n, side1, side2, hypot);
         
  return 0;
}
