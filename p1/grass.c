/* clwhe */

#include <stdio.h>

#define MOW_RATE 2

int main(void)
{
  int length_yard;
  int width_yard;
  int length_house;
  int width_house;
  int area_grass;
  int mins_mow;
  int secs_mow;
  int time_mow;
  
  printf("Please enter the length and width of the yard > ");
  scanf("%d %d", &length_yard, &width_yard);
  printf("Please enter the length and width of the house > ");
  scanf("%d %d", &length_house, &width_house);
  
  area_grass = (length_yard * width_yard) - (length_house * width_house);
  time_mow = area_grass / MOW_RATE;
  mins_mow = time_mow / 60;
  secs_mow = time_mow % 60;
  
  printf("%d square feet will take %d minutes and %d seconds to cut.\n",
         area_grass, mins_mow, secs_mow);
         
  return 0;
}
