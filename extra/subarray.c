/* clwhe */

#include <stdio.h>

int get_sum(int list[], int i, int j);
void display_indices(int index_i, int index_j);
void display_sum(int largest);

int main()
{
  int list[] = {8, -7, 2, 2, 12, 6, -10, 2, 14, 7, -10, -1, -13, -2, 10};
  int sum;
  int largest;
  int i, j, index_i, index_j;
  int n = 15;

  sum = list[0];
  largest = list[0];
  index_i = 0;
  index_j = 0;

  for (i = 0; i <= n - 2; i++) {
    for (j = i + 1; j <= n - 1; j++) {
      sum = get_sum(list, i, j);
      if (sum > largest) {
        largest = sum;
        index_i = i;
        index_j = j;
      }
    }
  }
  display_indices(index_i, index_j);
  display_sum(largest);

  return 0;
}

int get_sum(int list[], int i, int j) {
  int temp = 0;

  while (i <= j) {
    temp = temp + list[i++];
  }
  return temp;
}

void display_indices(int index_i, int index_j) {
  printf("\nDisplaying subarray which has the largest sum:\n");
  printf("Entries between index %d and index %d inclusive\n", index_i, index_j);
}

void display_sum(int largest) {
  printf("\nsum = %d\n\n", largest); 
}
