/* clwhe */

#include <stdio.h>

int main(void)
{
  char grade_desired;
  double min_avg;
  double current_avg;
  double final_weight;
  double final_score;
  
  printf("Enter desired grade> ");
  scanf("%c", &grade_desired);
  printf("Enter minimum average required> ");
  scanf("%lf", &min_avg);
  printf("Enter current average in course> ");
  scanf("%lf", &current_avg);
  printf("Enter how much the final counts\n");
  printf("as a percentage of the course grade> ");
  scanf("%lf", &final_weight);
  
  final_weight = final_weight / 100;
  final_score = (min_avg - (1 - final_weight) * current_avg) / final_weight;
  
  printf("\nYou need a score of %.2f", final_score);
  printf(" on the final to get a %c.\n", grade_desired);
  
  return 0;
}
