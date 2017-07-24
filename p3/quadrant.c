/* clwhe */

#include <stdio.h>

int main(void)
{
  double x;
  double y;
  
  printf("Please enter the x and y coordinates: ");
  scanf("%lf %lf", &x, &y);
  printf("(%.1f, %.1f) is ", x, y);
  
  if (x < 0) {
    if (y < 0)
      printf("in quadrant III\n");
    else if (y > 0)
      printf("in quadrant II\n");
    else  /* y == 0 */
      printf("on the x axis\n");
  }
  else if (x > 0) {
    if (y < 0)
      printf("in quadrant IV\n");
    else if (y > 0)
      printf("in quadrant I\n");
    else  /* y == 0 */
      printf("on the x axis\n");
  }
  else {  /* x == 0 */
    if (y == 0)
      printf("the origin\n");
    else  /* y != 0 */
      printf("on the y axis\n");
  }
  
  return 0;
}
