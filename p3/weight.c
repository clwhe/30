/* clwhe */

#include <stdio.h>

int main()
{
  int wt_lb;
  int ht_in;
  double bmi;
  
  printf("Please enter your weight in whole pounds: ");
  scanf("%d", &wt_lb);
  printf("Please enter your height in whole inches: ");
  scanf("%d", &ht_in);
  
  bmi = (double) 703 * wt_lb / (ht_in * ht_in);
  
  printf("You have a BMI of %.1f, and your weight status is ", bmi);
  
  if (bmi < 18.5)
    printf("underweight.\n");
  else if (bmi < 25.0)
    printf("normal.\n");
  else if (bmi < 30.0)
    printf("overweight.\n");
  else
    printf("obese.\n");
  
  return 0;
}  /* main() */
