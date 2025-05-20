//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: futuristic
#include <stdio.h>

void mergeSort(int *arr, int left, int right) {
  if (right - left <= 1) {
    return;
  }
  int mid = (left + right) / 2;
  mergeSort(arr, left, mid);
  mergeSort(arr, mid, right);
  int *tmp = (int *)malloc(sizeof(int) * (right - left));
  int i = left;
  int j = mid;
  int k = 0;
  while (i < mid && j < right) {
    if (arr[i] < arr[j]) {
      tmp[k++] = arr[i++];
    } else {
      tmp[k++] = arr[j++];
    }
  }
  while (i < mid) {
    tmp[k++] = arr[i++];
  }
  while (j < right) {
    tmp[k++] = arr[j++];
  }
  for (i = 0; i < right - left; i++) {
    arr[i + left] = tmp[i];
  }
  free(tmp);
}

void printArray(int *arr, int n) {
  printf("[");
  for (int i = 0; i < n; i++) {
    printf("%d", arr[i]);
    if (i < n - 1) {
      printf(", ");
    }
  }
  printf("]\n");
}

int main() {
  printf("Preparing to deploy the **Cybernetic Sorting Algorithm v7.5**...\n\n");
  int arr[] = {5, 3, 1, 2, 4};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("Scanning target array: ");
  printArray(arr, n);
  printf("\nCommencing sorting procedure...\n\n");
  mergeSort(arr, 0, n);
  printf("Sorting complete.\n\n");
  printf("Transmitting sorted array: ");
  printArray(arr, n);
  printf("\nMission accomplished. Algorithm terminating.\n\n");
  return 0;
}