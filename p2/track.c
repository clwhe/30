/* clwhe */

#include <stdio.h>

#define FEET_PER_MILE 5280
#define FEET_PER_KM 3282

void instruct(void);

int main()
{
  int minutes;
  double seconds;
  double total_secs;
  double fps;
  double mps;
  
  instruct();
  
  printf("Minutes for the runner: ");
  scanf("%d", &minutes);
  printf("Seconds for the runner: ");
  scanf("%lf", &seconds);
  
  total_secs = minutes * 60 + seconds;
  fps = FEET_PER_MILE / total_secs;
  mps = (double)FEET_PER_MILE / FEET_PER_KM * 1000 / total_secs;
  
  printf("That is %3.1f feet per second, and %3.2f meters per second.\n",
         fps, mps);
         
  return 0;
}  /* main() */


void instruct(void)
{
  printf("This program will ask for the minutes and seconds for the time it\n");
  printf("took for a runner to run a mile. The program will then calculate\n");
  printf("the feet per second and meters per second for that runner.\n\n");
}  /* instruct() - display instructions for user */
