/* clwhe */

#include <stdio.h>

int main()
{
  int pollutant;
  int odometer;
  double grams_mile;
  double limit;
  
  printf("(1) Carbon monoxide\n(2) Hydrocarbons\n");
  printf("(3) Nitrogen oxides\n(4) Nonmethane hydrocarbons\n");
  printf("Enter pollutant number>> ");
  scanf("%d", &pollutant);
  printf("Enter number of grams emitted per mile>> ");
  scanf("%lf", &grams_mile);
  printf("Enter odometer reading>> ");
  scanf("%d", &odometer);
  
  if (pollutant == 1)
  {
    if (odometer <= 50000)
      limit = 3.4;
    else  /* odometer > 50000 */
      limit = 4.2;
  }
  
  else if (pollutant == 2)
  {
    if (odometer <= 50000)
      limit = 0.31;
    else  /* odometer > 50000 */
      limit = 0.39;
  }
  
  else if (pollutant == 3)
  {
    if (odometer <= 50000)
      limit = 0.4;
    else  /* odometer > 50000 */
      limit = 0.5;
  }
  
  else if (pollutant == 4)
  {
    if (odometer <= 50000)
      limit = 0.25;
    else  /* odometer > 50000 */
      limit = 0.31;
  }
  
  else  /* invalid pollutant number entered */
  {
    printf("Invalid pollutant number.\n");
    return 1;
  }
  
  if (grams_mile > limit)
    printf("Emissions exceed permitted level of %.2f grams/mile.\n", limit);
  else  /* emissions limit not exceeded */
    printf("Emissions do not exceed permitted level of %.2f grams/mile.\n",
           limit);
  
  return 0;
}  /* main() */
