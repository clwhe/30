/* clwhe */

#include <stdio.h>

int get_problem();
void get2_pt(int *x1, int *y1, int *x2, int *y2);
void get_pt_slope(float *m, int *x1, int *y1);
void slope_intcpt_from2_pt(int x1, int y1, int x2, int y2, float *m, float *b);
float intcpt_from_pt_slope(int x1, int y1, float m);
void display2_pt(int x1, int y1, int x2, int y2);
void display_pt_slope(int x1, int y1, float m);
void display_slope_intcpt(float m, float b);

int main()
{
  int x1, y1, x2, y2;
  float m, b;
  char run;
  int form;

  do {
    form = get_problem();

    if (form == 1) {
      get2_pt(&x1, &y1, &x2, &y2);
      display2_pt(x1, y1, x2, y2);
      slope_intcpt_from2_pt(x1, y1, x2, y2, &m, &b);
    }

    else if (form == 2) {
      get_pt_slope(&m, &x1, &y1);
      display_pt_slope(x1, y1, m);
      b = intcpt_from_pt_slope(x1, y1, m);
    }

    else {
      printf("Invalid form input!\n");
      return 1;
    }

    display_slope_intcpt(m, b);

    printf("Do another conversion (Y or N)=> ");
    scanf(" %c", &run); /* ignore previous \n input */
  } while (run == 'Y'); 

  return 0;
}


int get_problem() {
  int form;

  printf("\nSelect the form that you would like to convert to slope-intercept");
  printf(" form:\n1) Two-point form (you know two points on the line)\n");
  printf("2) Point-slope form (you know the line's slope and one point)\n=> ");
  scanf("%d", &form);
  return form;
}


void get2_pt(int *x1, int *y1, int *x2, int *y2) {
  printf("\nEnter the x-y coordinates of the first point separated by a");
  printf(" space=> ");
  scanf("%d %d", x1, y1);
  printf("Enter the x-y coordinates of the second point separated by a");
  printf(" space=> ");
  scanf("%d %d", x2, y2);
}


void get_pt_slope(float *m, int *x1, int *y1) {
  printf("\nEnter the slope=> ");
  scanf("%f", m);
  printf("Enter the x-y coordinates of the point separated by a space=> ");
  scanf("%d %d", x1, y1);
}


void slope_intcpt_from2_pt(int x1, int y1, int x2, int y2, float *m, float *b) {
  *m = ((float)y2 - (float)y1) / ((float)x2 - (float)x1);
  *b = (float)y1 - *m * x1;
}


float intcpt_from_pt_slope(int x1, int y1, float m) {
  float b;

  b = (float)y1 - m * x1;
  return b;
}


void display2_pt(int x1, int y1, int x2, int y2) {
  printf("\nTwo-point form\n");
  if (y1 >= 0)  /* prevent double minus y1 */
    printf("      (%4.2f -%5.2f)\n", (float)y2, (float)y1);
  else
    printf("      (%4.2f +%5.2f)\n", (float)y2, (float)-y1);
  printf("  m = -------------\n");
  if (x1 >= 0)  /* prevent double minus x1 */
    printf("      (%4.2f -%5.2f)\n", (float)x2, (float)x1);
  else
    printf("      (%4.2f +%5.2f)\n", (float)x2, (float)-x1);
}


void display_pt_slope(int x1, int y1, float m) {
  printf("\nPoint-slope form\n");
  if (y1 >= 0)  /* prevent double minus y1 */
    printf(" y -%5.2f", (float)y1);
  else
    printf(" y +%5.2f", (float)-y1);
  printf(" =%5.2f", m);
  if (x1 >= 0)  /* prevent double minus x1 */
    printf("(x -%5.2f)\n", (float)x1);
  else
    printf("(x +%5.2f)\n", (float)-x1);
/*  printf("  y -%5.2f =%5.2f(x -%5.2f)\n", (float)y1, m, (float)x1);  */
}


void display_slope_intcpt(float m, float b) {
  printf("\nSlope-intercept form\n");
  if (b < 0)  /* prevent double minus b */
    printf("  y =%5.2fx -%5.2f\n\n", m, -b);
  else
    printf("  y =%5.2fx +%5.2f\n", m, b);
}
