//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUCKETS 10

void bucket_sort(char **arr, int n) {
  int i, j, k, bucket_num, max_size = 0;
  char **buckets = (char **)malloc(MAX_BUCKETS * sizeof(char *));
  for (i = 0; i < MAX_BUCKETS; i++) {
    buckets[i] = (char *)malloc(sizeof(char) * n);
  }

  for (i = 0; i < n; i++) {
    bucket_num = arr[i] - 'a';
    buckets[bucket_num][max_size++] = arr[i];
  }

  k = 0;
  for (i = 0; i < MAX_BUCKETS; i++) {
    for (j = 0; j < max_size; j++) {
      arr[k++] = buckets[i][j];
    }
  }

  free(buckets);
}

int main() {
  char **arr = (char **)malloc(10 * sizeof(char *));
  arr[0] = "abc";
  arr[1] = "bcd";
  arr[2] = "cde";
  arr[3] = "def";
  arr[4] = "ghi";
  arr[5] = "bcd";
  arr[6] = "cde";
  arr[7] = "bcd";
  arr[8] = "abc";
  arr[9] = "cde";

  bucket_sort(arr, 10);

  for (int i = 0; i < 10; i++) {
    printf("%s ", arr[i]);
  }

  free(arr);

  return 0;
}