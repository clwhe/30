/* clwhe */

#include <stdio.h>
#include <math.h>

void instruct(void);
double surface_area(double radius, double height);

int main()
{
  double radius;
  double height;
  double cost_per_sq_cm;
  double surf_area;  /* surface area of one can */
  double cost_per_can;
  double total_cost;
  int quantity;
  int row;  /* row of input file */
  FILE *inp;  /* pointer to input file */
  
  instruct();
  
  inp = fopen("cans.txt", "r");
  
  for (row = 1; row <= 3; row++)
  {
    fscanf(inp, "%lf %lf", &radius, &height);
    fscanf(inp, "%lf %d", &cost_per_sq_cm, &quantity);
    
    surf_area = surface_area(radius, height);
    cost_per_can = surf_area * cost_per_sq_cm;
    total_cost = quantity * cost_per_can;
    
    printf("Each can #%d has surface area %8.3f,", row, surf_area);
    printf(" and the run will cost $%.2f.\n", total_cost);
  }  /* process file line by line for 3 can types */
  
  fclose(inp);
  
  return 0;
}  /* main() */


void instruct(void)
{
  printf("This program calculates the cost of materials for three");
  printf(" open-top cylindrical\ncontainers. It reads the radius,");
  printf(" height, cost per square centimeter, and\nquantity for");
  printf(" each container from the file cans.txt. Each line in");
  printf(" cans.txt has\nthe format: radius height ");
  printf("cost_per_sq_cm quantity.\n\n");
}  /* instruct() - displays instructions for user */


double surface_area(double radius, double height)
{
  double bottom_area;
  double side_area;
  
  bottom_area = M_PI * radius * radius;
  side_area = 2 * M_PI * radius * height;
  
  return (bottom_area + side_area);
}  /* surface_area() - calculates open-top cylinder surface area */
