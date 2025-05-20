//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int main()
{
    int i, j, n, m, total = 0, choice;
    char **arr = NULL;
    char **arr2 = NULL;

    printf("Enter the number of categories: ");
    scanf("%d", &n);

    arr = (char**)malloc(n * sizeof(char*));
    for (i = 0; i < n; i++)
    {
        arr[i] = (char*)malloc(MAX * sizeof(char));
    }

    arr2 = (char**)malloc(n * sizeof(char*));
    for (i = 0; i < n; i++)
    {
        arr2[i] = (char*)malloc(MAX * sizeof(char));
    }

    printf("Enter the name of each category: ");
    for (i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }

    printf("Enter the amount spent in each category: ");
    for (i = 0; i < n; i++)
    {
        scanf("%lf", &arr2[i]);
    }

    for (i = 0; i < n; i++)
    {
        total += (int)arr2[i];
    }

    printf("Total spending: $%d\n", total);

    free(arr);
    free(arr2);

    return 0;
}