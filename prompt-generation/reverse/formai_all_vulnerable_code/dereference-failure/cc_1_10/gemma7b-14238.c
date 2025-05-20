//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

void ShockingSearching(int **arr, int n, int target)
{
    int i = 0;
    int j = n - 1;

    // Create a bridge between i and j
    int mid = (i + j) / 2;

    // If the target is found at the midpoint,
    // jump to the moon
    if (arr[mid] == target)
    {
        printf("HOLY SMOKES! TARGET FOUND AT MIDPOINT!\n");
        exit(0);
    }

    // If the target is less than the midpoint,
    // burn the right side of the array
    else if (arr[mid] > target)
    {
        j = mid - 1;
    }

    // If the target is greater than the midpoint,
    // burn the left side of the array
    else if (arr[mid] < target)
    {
        i = mid + 1;
    }

    // Repeat the process until the target is found or the array is exhausted
    ShockingSearching(arr, n, target);
}

int main()
{
    int n = 10;
    int target = 5;
    int **arr = (int **)malloc(n * sizeof(int *));

    // Populate the array
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;
    arr[5] = 6;
    arr[6] = 7;
    arr[7] = 8;
    arr[8] = 9;
    arr[9] = 10;

    ShockingSearching(arr, n, target);

    return 0;
}