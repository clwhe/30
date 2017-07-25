/* clwhe */

#include <stdio.h>
#include <math.h>

void instruct_user(void);
double open_cyl_area(double radius, double height);

int main(void)
{
  double radius;
  double height;
  double cost_per_sq_cm;
  double can_area;
  double cost_per_can;
  double total_cost;
  int quantity;
  int row;    /* input file line number */
  FILE *inp;  /* pointer to input file */
  
  instruct_user();
  
  inp = fopen("cans.txt", "r");
  
  for (row = 1; row <= 3; row++) {
    fscanf(inp, "%lf %lf", &radius, &height);
    fscanf(inp, "%lf %d", &cost_per_sq_cm, &quantity);
    
    can_area = open_cyl_area(radius, height);
    cost_per_can = can_area * cost_per_sq_cm;
    total_cost = quantity * cost_per_can;
    
    printf("Each can #%d has surface area %8.3f,", row, can_area);
    printf(" and the run will cost $%.2f.\n", total_cost);
  }
  
  fclose(inp);
  
  return 0;
}


void instruct_user(void)
{
  printf("This program calculates the cost of materials for three");
  printf(" open-top cylindrical\ncontainers. It reads the radius,");
  printf(" height, cost per square centimeter, and\nquantity for");
  printf(" each container from the file cans.txt. Each line in");
  printf(" cans.txt has\nthe format: radius height ");
  printf("cost_per_sq_cm quantity.\n\n");
}


double open_cyl_area(double radius, double height)
{
  double bottom_area;
  double side_area;
  
  bottom_area = M_PI * radius * radius;
  side_area = 2 * M_PI * radius * height;
  /* open-top cylinder area */
  return (bottom_area + side_area);
}
