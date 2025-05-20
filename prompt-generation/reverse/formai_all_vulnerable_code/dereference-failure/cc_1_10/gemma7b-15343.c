//Gemma-7B DATASET v1.0 Category: Recursive ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

void solveCase(char **arr, int n)
{
    if (n == 0)
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%c ", arr[i]);
    }

    printf("\n");

    solveCase(arr, n - 1);
}

int main()
{
    char **arr = malloc(10 * sizeof(char *));
    for (int i = 0; i < 10; i++)
    {
        arr[i] = malloc(20 * sizeof(char));
    }

    arr[0] = "A";
    arr[1] = "B";
    arr[2] = "C";
    arr[3] = "D";
    arr[4] = "E";
    arr[5] = "F";
    arr[6] = "G";
    arr[7] = "H";
    arr[8] = "I";
    arr[9] = "J";

    solveCase(arr, 10);

    for (int i = 0; i < 10; i++)
    {
        free(arr[i]);
    }

    free(arr);

    return 0;
}