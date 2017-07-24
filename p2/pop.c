/* clwhe */

#include <stdio.h>

#define INIT_POP 52.966   /* population in 1990 */
#define POP_GROWTH 2.184  /* growth factor */
#define INIT_YEAR 1990    /* zeroth year */

double population(int year);

int main(void)
{
  int year;
  double predicted_pop;
  FILE *outp;
  
  outp = fopen("pop.txt", "w");
  
  printf("Enter a year after 1990> ");
  scanf("%d", &year);
  
  predicted_pop = population(year);
  
  fprintf(outp, "Predicted Gotham City population for");
  fprintf(outp, " %d (in thousands): %.3f\n", year, predicted_pop);
  
  fclose(outp);
  
  return 0;
}


double population(int year)
{
  return INIT_POP + POP_GROWTH * (year - INIT_YEAR);
}
