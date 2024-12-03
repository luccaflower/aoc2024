#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 2500
int process_list(FILE *input);
void quicksort(int *arr, int low, int high);
int process_list(FILE *input) {
  int left[MAX_LEN] = {0};
  int right[MAX_LEN] = {0};
  size_t n = 0;
  while (fscanf(input, "%d %d\n", &(left[n]), &(right[n])) == 2) {
    n++;
    if (n >= MAX_LEN) {
      puts("Ran out of array lenght");
      return -1;
    }
  }
  quicksort(left, 0, n - 1);
  quicksort(right, 0, n - 1);
  int distance = 0;
  for (size_t i = 0; i < n; i++) {
    distance += abs(left[i] - right[i]);
  }
  return distance;
}

int partition(int *arr, int low, int high);
void quicksort(int *arr, int low, int high) {
  if (low >= high || low < 0)
    return;
  int p = partition(arr, low, high);
  quicksort(arr, low, p - 1);
  quicksort(arr, p + 1, high);
}
int partition(int *arr, int low, int high) {
  int pivot = arr[high];
  int i = low;
  for (int j = low; j < high; j++) {
    int current = arr[j];
    if (current >= pivot) {
      arr[j] = arr[i];
      arr[i] = current;
      i++;
    }
  }
  int temp = arr[i];
  arr[i] = arr[high];
  arr[high] = temp;
  return i;
}
