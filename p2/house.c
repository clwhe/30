/* clwhe */

#include <stdio.h>

void instruct_user(void);

int main(void)
{
  int init_cost;
  int fuel_cost;
  double tax_rate;
  double total_cost;
  
  instruct_user();
  
  printf("Please enter the initial cost, fuel cost, and tax rate: ");
  scanf("%d %d %lf", &init_cost, &fuel_cost, &tax_rate);
  
  total_cost = init_cost + (fuel_cost * 5) + (init_cost * tax_rate * 5);
  /* add initial cost to fuel cost for 5 years, add taxes for 5 years */
  
  printf("The total cost is $%.2f.\n", total_cost);
  
  return 0;
}


void instruct_user(void)
{
  printf("This program determines the total cost of owning a home");
  printf(" for five years.\nThe user will enter initial cost in");
  printf(" whole dollars, annual fuel costs in\nwhole dollars,");
  printf(" and the annual tax rate as a real number.\n\n");
}
