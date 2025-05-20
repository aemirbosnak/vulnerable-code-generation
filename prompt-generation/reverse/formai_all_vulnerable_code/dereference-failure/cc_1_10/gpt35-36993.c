//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

void bucketSort(float arr[], int n) {

  // Create n buckets
  int i;
  float max = arr[0];
  for (i = 1; i < n; i++) {
    if (arr[i] > max)
      max = arr[i];
  }
  max++;

  int bucket[n];
  for (i = 0; i < n; i++) {
    bucket[i] = 0;
  }

  // Store elements in respective buckets
  for (i = 0; i < n; i++) {
    int bucketIndex = n * arr[i] / max;
    bucket[bucketIndex]++;
  }

  // Sort elements in each bucket
  for (i = 0; i < n; i++) {
    int j;
    int bucketIndex = n * arr[i] / max;
    float temp = arr[i];
    int tempCount = bucket[bucketIndex] - 1;
    for (j = bucketIndex - 1; j >= 0; j--) {
      if (bucket[j] != 0) {
        if (temp < j * max / n) {
          arr[i] = j * max / n;
          bucketIndex--;
          bucket[j]--;
          break;
        }
        tempCount += bucket[j];
      }
    }
    if (j < 0) {
      tempCount++;
      arr[i] = 0;
    }
    for (j = bucketIndex + 1; j < n; j++) {
      if (bucket[j] != 0) {
        if (temp > (j + 1) * max / n) {
          arr[tempCount++] = (j + 1) * max / n;
          bucket[j]--;
        } else {
          break;
        }
      }
    }
    arr[tempCount] = temp;
    bucket[bucketIndex]--;
  }
}

int main() {

  int n;
  printf("Enter the number of elements: ");
  scanf("%d", &n);

  printf("Enter %d elements: ", n);
  float arr[n];
  int i;
  for (i = 0; i < n; i++) {
    scanf("%f", &arr[i]);
  }

  bucketSort(arr, n);

  printf("Sorted array is: ");
  for (i = 0; i < n; i++) {
    printf("%f ", arr[i]);
  }
  printf("\n");

  return 0;
}