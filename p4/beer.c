/* clwhe */

#include <stdio.h>

#define PIELS 0
#define COORS 1
#define BUD 2
#define IRONCITY 3

int main(int argc, char *argv[])
{
  int qty[4];
  int id;
  int trans;
  int status;
  FILE *fp;

  fp = fopen(argv[1], "r");
  fscanf(fp, "%d %d %d %d",
         &qty[PIELS], &qty[COORS], &qty[BUD], &qty[IRONCITY]);

  while (status != EOF) { /* loop until EOF */
    status = fscanf(fp, " %d %d", &id, &trans);
    if(status != EOF) 
      qty[id-1] = qty[id-1] + trans; /* convert brand ID to array element
      and record transaction */
  } 
  fclose(fp);
  printf("Piels: %10d\n", qty[PIELS]);
  printf("Coors: %10d\n", qty[COORS]);
  printf("Bud: %12d\n", qty[BUD]);
  printf("Iron City: %6d\n", qty[IRONCITY]);
  return 0;
}
