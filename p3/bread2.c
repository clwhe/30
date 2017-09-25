/* clwhe */

#include <stdio.h>

void display_instructions(char *type, char *loaf_size, char *manual);
void white_bread(void);
void sweet_bread(void);
void calc_baking_time(char type, char loaf_size, char manual);

int primary_kneading_mins;
int primary_rising_mins;
int secondary_kneading_mins;
int secondary_rising_mins;
int loaf_shaping_secs;
int final_rising_mins;
int baking_mins;
int cooling_mins;

int main(void)
{
  char type;
  char loaf_size;
  char manual;
  
  display_instructions(&type, &loaf_size, &manual);
  calc_baking_time(type, loaf_size, manual);
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


void white_bread(void)
{
  primary_kneading_mins = 15;
  primary_rising_mins = 60;
  secondary_kneading_mins = 18;
  secondary_rising_mins = 20;
  loaf_shaping_secs = 2;
  final_rising_mins = 75;
  baking_mins = 45;
  cooling_mins = 30;
}


void sweet_bread(void)
{
  primary_kneading_mins = 20;
  primary_rising_mins = 60;
  secondary_kneading_mins = 33;
  secondary_rising_mins = 30;
  loaf_shaping_secs = 2;
  final_rising_mins = 75;
  baking_mins = 35;
  cooling_mins = 30;
}


void calc_baking_time(char type, char loaf_size, char manual)
{
  int total_mins;
  int total_secs;
  int baking_secs;
  
  total_mins = 0;
  total_secs = 0;
  baking_secs = 0;
  
  if (type == 'W' || type == 'w')
    white_bread();
  else if (type == 'S' || type == 's')
    sweet_bread();
  else
    printf("Invalid bread type!\n");

  if (loaf_size == 'D' || loaf_size == 'd') {
    baking_secs = baking_mins * 60;
    /* increase baking time by 50% for double loaf */
    baking_secs = baking_secs * 3;
    baking_secs = baking_secs / 2;
    /* store mins and secs separately */
    baking_mins = baking_secs / 60;
    baking_secs = baking_secs % 60;
  }
  else if (loaf_size == 'S' || loaf_size == 's')
    ;
  else
    printf("Invalid loaf size!\n");


  total_mins = total_mins + primary_kneading_mins;
  printf("Primary kneading: %d minutes\n", primary_kneading_mins);
  total_mins = total_mins + primary_rising_mins;
  printf("Primary rising: %d minutes\n", primary_rising_mins);
  total_mins = total_mins + secondary_kneading_mins;
  printf("Secondary kneading: %d minutes\n", secondary_kneading_mins);
  total_mins = total_mins + secondary_rising_mins;
  printf("Secondary rising: %d minutes\n", secondary_rising_mins);
  total_secs = total_secs + loaf_shaping_secs;
  printf("Loaf shaping: %d seconds\n", loaf_shaping_secs);
    
  if (manual == 'N' || manual == 'n') {
    total_mins = total_mins + final_rising_mins;
    printf("Final rising: %d minutes\n", final_rising_mins);
      
    total_mins = total_mins + baking_mins;
    total_secs = total_secs + baking_secs;
    printf("Baking: %d minutes %d seconds\n", baking_mins, baking_secs);
      
    total_mins = total_mins + cooling_mins;
    printf("Cooling: %d minutes\n", cooling_mins);
  }
  else if (manual == 'Y' || manual == 'y')
    printf("You should remove the dough for manual baking.\n");
  else
    printf("Invalid baking mode!\n");
  
  printf("\nFor a total baking time of %d minutes and %d seconds.\n",
         total_mins, total_secs);
}
