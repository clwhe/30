/* clwhe */

#include <stdio.h>

#define INCLUDED_MIN 600
#define FLAT_RATE 3999
#define ADD_MIN_RATE 40
#define TAX_RATE 0.0525
#define CENTS_PER_DOLLAR 100

int main(void)
{
  int weekday_min;
  int night_min;
  int weekend_min;
  int total_min;
  int rounded_avg_min_cost;
  int pretax_bill;
  int rounded_taxes;
  int total_bill;
  double avg_min_cost;
  double taxes;
  
  printf("Please enter the number of weekday minutes, night minutes: ");
  scanf("%d %d", &weekday_min, &night_min);
  printf("Please enter the number of weekend minutes: ");
  scanf("%d", &weekend_min);
  
  total_min = weekday_min + night_min + weekend_min;
  
  if (weekday_min > INCLUDED_MIN)
    pretax_bill = (weekday_min - INCLUDED_MIN) * ADD_MIN_RATE + FLAT_RATE;
  else  /* weekday_min <= 600 */
    pretax_bill = FLAT_RATE;
  
  avg_min_cost = (double)pretax_bill / (double)total_min;
  rounded_avg_min_cost = (int)(avg_min_cost + 0.5);
  
  taxes = pretax_bill * TAX_RATE;
  rounded_taxes = (int)(taxes + 0.5);
  total_bill = pretax_bill + rounded_taxes;
  
  printf("\nWeekday minutes: %d, ", weekday_min);
  printf("night minutes: %d, ", night_min);
  printf("weekend minutes: %d\n", weekend_min);
  printf("Average minute cost: ");
  printf("$%.2f\n\n", (double)rounded_avg_min_cost / CENTS_PER_DOLLAR);
  
  printf("Pretax bill: $%6.2f\n", (double)pretax_bill / CENTS_PER_DOLLAR);
  printf("Taxes:       $%6.2f\n", (double)rounded_taxes / CENTS_PER_DOLLAR);
  printf("Total bill:  $%6.2f\n", (double)total_bill / CENTS_PER_DOLLAR);
  
  return 0;
}
