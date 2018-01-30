/* clwhe */

#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
  int n, i;
  double sum, sum_squares, smallest, largest;
  double average, sd, value;
  FILE *fp;  /* pointer to input file */

  if (argc == 1) {
    printf("No file specified! Usage: data.out file.name \n");
    return 1;
  }
  if ((fp = fopen(argv[1], "r")) == NULL) {
    printf("data.out: can't open file\n");
    return 1;
  }

  fscanf(fp, "%d", &n);
  fscanf(fp, " %lf", &value);
  smallest = value;
  largest = value;
  sum = value;
  sum_squares = value * value;

  for (i = 2; i <= n; i++) {
    fscanf(fp, " %lf", &value);
    if (value < smallest)
      smallest = value;
    if (value > largest)
      largest = value;
    sum = sum + value;
    sum_squares = sum_squares + (value * value);
  }
  
  fclose(fp);

  average = sum / n;
  sd = sqrt((sum_squares / n) - (average * average));

  printf("Smallest: %5.2f\n", smallest);
  printf("Largest: %5.2f\n", largest);
  printf("Average: %5.2f\n", average);
  printf("Standard deviation: %6.3f\n", sd);

  return 0;
}
