/* clwhe */

#include <stdio.h>

int main(void)
{
  int kph;
  double mps;
  int dist;
  double accel;
  double time;
  
  printf("Please enter the takeoff speed of the jet in km/hr > ");
  scanf("%d", &kph);
  printf("Please enter the catapult distance in meters > ");
  scanf("%d", &dist);
  
  mps = (double)kph * 1000 / 3600;  /* convert km/hr to m/s */
  time = 2 * dist / mps;
  accel = mps / time;
  
  printf("The jet would accelerate at %.2f m/s^2 for %.2f seconds.\n",
         accel, time);
         
  return 0;
}
