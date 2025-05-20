//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

void knight_sort(int **arr, int n)
{
    int i, j, k, min_index, temp;

    // Create a campfire
    printf("Gather 'round, young knight, for a tale of ancient sorting...\n");

    // Iterate over the array
    for (i = 0; i < n; i++)
    {
        min_index = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }

        // Swap elements
        temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;

        // Sing a song about the swap
        printf("Ho ho ho, the elements dance,\nFrom their old position to their new trance.\n");
    }

    // The array is sorted
    printf("Behold, my dear knight, the array is sorted in order!\n");
}

int main()
{
    int n;
    printf("How many knights are participating in this sorting tournament?\n");
    scanf("%d", &n);

    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    // Get the knights' armor
    printf("Please equip each knight with their armor:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr[i]);
    }

    knight_sort(arr, n);

    // Free the knights' armor
    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}