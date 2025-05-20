//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void greedy_algo(int **arr, int n)
{
    int i, j, total = 0, current_size = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < current_size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        current_size++;
        total += arr[i];
    }

    printf("Total weight: %d\n", total);
}

int main()
{
    int n, i;
    scanf("Enter the number of items: ", &n);

    int **arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter the weight of item %d: ", i + 1);
        scanf("%d", &arr[i][0]);

        printf("Enter the value of item %d: ", i + 1);
        scanf("%d", &arr[i][1]);
    }

    greedy_algo(arr, n);

    return 0;
}