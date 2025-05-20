//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int **arr, int n, int k)
{
  int i, j, h, bucket[k], *temp = NULL;

  temp = malloc(n * sizeof(int));

  for (i = 0; i < k; i++)
    bucket[i] = 0;

  for (i = 0; i < n; i++)
  {
    h = arr[i][1] % k;
    bucket[h]++;
  }

  for (i = 0; i < k; i++)
  {
    if (bucket[i] > 0)
    {
      for (j = 0; j < bucket[i]; j++)
      {
        temp[j] = arr[i][0] + (i * k);
      }
      arr = temp;
    }
  }

  free(temp);
}

int main()
{
  int n, k, **arr = NULL;

  scanf("Enter the number of elements: ", &n);
  scanf("Enter the number of buckets: ", &k);

  arr = malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++)
    arr[i] = malloc(2 * sizeof(int));

  // Input the elements and their bucket indices
  for (int i = 0; i < n; i++)
  {
    scanf("Enter the element: ", &arr[i][0]);
    scanf("Enter the bucket index: ", &arr[i][1]);
  }

  bucket_sort(arr, n, k);

  // Print the sorted elements
  for (int i = 0; i < n; i++)
    printf("Sorted element: %d\n", arr[i][0]);

  return 0;
}