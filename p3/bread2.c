/* clwhe */

#include <stdio.h>

void display_instructions(char *type, char *loaf_size, char *manual);
void white_bread(int step_times[]);
void sweet_bread(int step_times[]);
void calc_baking_time(char loaf_size, char manual,
                      int step_times[]);

int main(void)
{
  char type;
  char loaf_size;
  char manual;
  int step_times[8];
  
  display_instructions(&type, &loaf_size, &manual);

  if (type == 'W' || type == 'w')
    white_bread(step_times);
  else if (type == 'S' || type == 's')
    sweet_bread(step_times);
  else
    printf("Invalid bread type!\n");

  calc_baking_time(loaf_size, manual, step_times);
  /* printf("%c %c %c\n", type, loaf_size, manual); */
  
  return 0;
}


void display_instructions(char *type, char *loaf_size, char *manual)
{
  printf("Are you making white or sweet bread (w or s)? ");
  scanf("%c", type);
  printf("Is this a single or double loaf (s or d)? ");
  scanf(" %c", loaf_size);
  printf("Are you going to bake manually (y or n)? ");
  scanf(" %c", manual);
}


void white_bread(int step_times[])
{
  step_times[0] = 15;
  step_times[1] = 60;
  step_times[2] = 18;
  step_times[3] = 20;
  step_times[4] = 2;
  step_times[5] = 75;
  step_times[6] = 45;
  step_times[7] = 30;
}


void sweet_bread(int step_times[])
{
  step_times[0] = 20;
  step_times[1] = 60;
  step_times[2] = 33;
  step_times[3] = 30;
  step_times[4] = 2;
  step_times[5] = 75;
  step_times[6] = 35;
  step_times[7] = 30;
}


void calc_baking_time(char loaf_size, char manual, int step_times[])
{
  int total_mins;
  int total_secs;
  int baking_secs;
  
  total_mins = 0;
  total_secs = 0;
  baking_secs = 0;
  
  if (loaf_size == 'D' || loaf_size == 'd') {
    baking_secs = step_times[6] * 60;
    /* increase baking time by 50% for double loaf */
    baking_secs = baking_secs * 3;
    baking_secs = baking_secs / 2;
    /* store mins and secs separately */
    step_times[6] = baking_secs / 60;
    baking_secs = baking_secs % 60;
  }
  else if (loaf_size == 'S' || loaf_size == 's')
    ;
  else
    printf("Invalid loaf size!\n");

  printf("Primary kneading: %d minutes\n", step_times[0]);
  printf("Primary rising: %d minutes\n", step_times[1]);
  printf("Secondary kneading: %d minutes\n", step_times[2]);
  printf("Secondary rising: %d minutes\n", step_times[3]);
  printf("Loaf shaping: %d seconds\n", step_times[4]);
    
  if (manual == 'N' || manual == 'n') {
    printf("Final rising: %d minutes\n", step_times[5]);
    printf("Baking: %d minutes %d seconds\n", step_times[6], baking_secs);
    printf("Cooling: %d minutes\n", step_times[7]);
  }
  else if (manual == 'Y' || manual == 'y') {
    printf("You should remove the dough for manual baking.\n");
    step_times[5] = 0;
    step_times[6] = 0;
    step_times[7] = 0;
  }
  else
    printf("Invalid baking mode!\n");
 
  total_mins = (step_times[0] + step_times[1] + step_times[2] + 
               step_times[3] + step_times[5] + step_times[6] +
               step_times[7]);
  total_secs = step_times[4] + baking_secs; 
  printf("\nFor a total baking time of %d minutes and %d seconds.\n",
         total_mins, total_secs);
}
