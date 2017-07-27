/* clwhe */

#include <stdio.h>

#define DOLLAR_RATE 0.35

void display_instructions(double *begin_miles, double *end_miles);

int main(void)
{
  double begin_miles;
  double end_miles;
  double traveled_miles;
  double reimbursement;
  
  do {
    display_instructions(&begin_miles, &end_miles);
    
    if (end_miles >= begin_miles) {
      traveled_miles = end_miles - begin_miles;
      reimbursement = traveled_miles * DOLLAR_RATE;
    }
    else  /* end_miles < begin_miles */
      printf("Invalid odometer reading input!\n");
  } while (end_miles < begin_miles);
  
  printf("You traveled %.1f miles. At $.35 per mile,\n", traveled_miles);
  printf("your reimbursement is $%.2f.\n", reimbursement);
  
  return 0;
}


void display_instructions(double *begin_miles, double *end_miles);
{
  printf("MILEAGE REIMBURSEMENT CALCULATOR\n");
  printf("Enter beginning odometer reading=> ");
  scanf("%lf", begin_miles);
  printf("Enter ending odometer reading=> ");
  scanf("%lf", end_miles);
}
