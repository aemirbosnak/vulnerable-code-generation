//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void bucket_sort(int **arr, int n)
{
  int i, j, k, bucket_size, *buckets;

  buckets = malloc(n * sizeof(int));
  for (i = 0; i < n; i++)
  {
    buckets[i] = 0;
  }

  for (i = 0; i < n; i++)
  {
    buckets[*arr[i]]++;
  }

  bucket_size = buckets[0] + 1;
  for (j = 1; j < n; j++)
  {
    bucket_size = fmax(bucket_size, buckets[j] + 1);
  }

  *arr = realloc(*arr, bucket_size * sizeof(int));

  k = 0;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < buckets[*arr[i]] - 1; j++)
    {
      *arr[k++] = *arr[i];
    }
  }

  free(buckets);
}

int main()
{
  int n, i, *arr;

  printf("Enter the number of elements: ");
  scanf("%d", &n);

  arr = malloc(n * sizeof(int));

  printf("Enter the elements: ");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  bucket_sort(&arr, n);

  printf("Sorted array: ");
  for (i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }

  free(arr);

  return 0;
}