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


void calc_baking_time(char type, char loaf_size, char manual)
{
  int total_mins;
  int total_secs;
  
  total_mins = 0;
  total_secs = 0;
  
  if (type == 'W' || type == 'w') {
    total_mins = total_mins + 15;
    printf("Primary kneading: 15 minutes\n");
    total_mins = total_mins + 60;
    printf("Primary rising: 60 minutes\n");
    total_mins = total_mins + 18;
    printf("Secondary kneading: 18 minutes\n");
    total_mins = total_mins + 20;
    printf("Secondary rising: 20 minutes\n");
    total_secs = total_secs + 2;
    printf("Loaf shaping: 2 seconds\n");
    
    if (manual == 'N' || manual == 'n') {
      total_mins = total_mins + 75;
      printf("Final rising: 75 minutes\n");
      
      if (loaf_size == 'D' || loaf_size == 'd') {
        total_mins = total_mins + 67;
        total_secs = total_secs + 30;
        printf("Baking: 67 minutes 30 seconds\n");
      }
      else { /* single loaf */
        total_mins = total_mins + 45;
        printf("Baking: 45 minutes 0 seconds\n");
      }
      
      total_mins = total_mins + 30;
      printf("Cooling: 30 minutes\n");
    }
    else /* manual baking */
      printf("You should remove the dough for manual baking.\n");
  }
  else { /* sweet bread */
    total_mins = total_mins + 20;
    printf("Primary kneading: 20 minutes\n");
    total_mins = total_mins + 60;
    printf("Primary rising: 60 minutes\n");
    total_mins = total_mins + 33;
    printf("Secondary kneading: 33 minutes\n");
    total_mins = total_mins + 30;
    printf("Secondary rising: 30 minutes\n");
    total_secs = total_secs + 2;
    printf("Loaf shaping: 2 seconds\n");
    
    if (manual == 'N' || manual == 'n') {
      total_mins = total_mins + 75;
      printf("Final rising: 75 minutes\n");
      
      if (loaf_size == 'D' || loaf_size == 'd') {
        total_mins = total_mins + 52;
        total_secs = total_secs + 30;
        printf("Baking: 52 minutes 30 seconds\n");
      }
      else { /* single loaf */
        total_mins = total_mins + 35;
        printf("Baking: 35 minutes 0 seconds\n");
      }
      
      total_mins = total_mins + 30;
      printf("Cooling: 30 minutes\n");
    }
    else /* manual baking */
      printf("You should remove the dough for manual baking.\n");
  }
  
  printf("\nFor a total baking time of %d minutes and %d seconds.\n",
         total_mins, total_secs);
}
