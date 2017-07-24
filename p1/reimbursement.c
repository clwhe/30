/* clwhe */

#include <stdio.h>

#define DOLLAR_RATE 0.35

int main(void)
{
  double begin_miles;
  double end_miles;
  double traveled_miles;
  double reimbursement;
  
  printf("MILEAGE REIMBURSEMENT CALCULATOR\n");
  printf("Enter beginning odometer reading=> ");
  scanf("%lf", &begin_miles);
  printf("Enter ending odometer reading=> ");
  scanf("%lf", &end_miles);
  
  traveled_miles = end_miles - begin_miles;
  reimbursement = traveled_miles * DOLLAR_RATE;
  
  printf("You traveled %.1f miles. At $.35 per mile,\n", traveled_miles);
  printf("your reimbursement is $%.2f.\n", reimbursement);
  
  return 0;
}
