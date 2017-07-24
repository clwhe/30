/* clwhe */

#include <stdio.h>

void display_instructions(char *type, char *loaf_size, char *manual);
void calc_baking_time(char type, char loaf_size, char manual);

int main(void)
{
  char type;
  char loaf_size;
  char manual;
  
  display_instructions(&type, &loaf_size, &manual);
  calc_baking_time(type, loaf_size, manual);
  printf("%c %c %c\n", type, loaf_size, manual);
  
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


void calc_baking_time(char type, char loaf_size, char manual)
{
  /* compute and print total baking time */
}
