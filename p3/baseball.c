/* clwhe */

/* test comment */

#include <stdio.h>

int main(int argc, char *argv[])
{
  int c; /* char stored as int */
  int player;
  int hits = 0;
  int at_bats = 0;
  float average;
  FILE *fp;
  
  fp = fopen(argv[1], "r");
  fscanf(fp, "%d", &player);  /* read first player number */
  while ((c = getc(fp)) != EOF) {
    if (c == ' ')
      printf("Player %d's record:", player);
    putc(c, stdout);  /* print current player record */
    if (c == '\n') {  /* print current player average then read next player */
      average = (float)hits / (float)at_bats;
      printf("Player %d's batting average: %.3f\n\n", player, average);
      fscanf(fp, "%d", &player);
      hits = 0;
      at_bats = 0;
    }
    else if (c == 'H') {
      ++hits;
      ++at_bats;
    }
    else if (c == 'O')
      ++at_bats;
  }
  fclose(fp);
  return 0;
}
