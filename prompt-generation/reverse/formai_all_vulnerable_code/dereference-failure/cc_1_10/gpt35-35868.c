//FormAI DATASET v1.0 Category: Benchmarking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int *data, int count) {
  int i, j, temp;

  for (i = 0; i < count; ++i) {
    for (j = 0; j < count - 1; ++j) {
      if (data[j] > data[j + 1]) {
        temp = data[j];
        data[j] = data[j + 1];
        data[j + 1] = temp;
      }
    }
  }
}

void quick_sort(int *data, int left, int right) {
  int pivot, left_temp = left, right_temp = right, temp;

  pivot = data[(left + right) / 2];

  while (left_temp <= right_temp) {
    while (data[left_temp] < pivot)
      left_temp++;
    while (data[right_temp] > pivot)
      right_temp--;
    if (left_temp <= right_temp) {
      temp = data[left_temp];
      data[left_temp] = data[right_temp];
      data[right_temp] = temp;
      left_temp++;
      right_temp--;
    }
  }

  if (left < right_temp)
    quick_sort(data, left, right_temp);
  if (left_temp < right)
    quick_sort(data, left_temp, right);
}

void print_data(int *data, int count) {
  int i;

  for (i = 0; i < count; ++i)
    printf("%d ", data[i]);
  printf("\n");
}

void benchmark_sort(int count) {
  int i, *data = malloc(sizeof(int) * count);
  clock_t start, end;

  for (i = 0; i < count; ++i)
    data[i] = rand() % 1000000;

  printf("Sorting %d elements:\n", count);

  start = clock();
  bubble_sort(data, count);
  end = clock();
  printf("Bubble Sort: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

  start = clock();
  quick_sort(data, 0, count - 1);
  end = clock();
  printf("Quick Sort: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

  free(data);
}

int main() {
  srand(time(NULL));

  benchmark_sort(1000);
  benchmark_sort(10000);
  benchmark_sort(100000);

  return EXIT_SUCCESS;
}