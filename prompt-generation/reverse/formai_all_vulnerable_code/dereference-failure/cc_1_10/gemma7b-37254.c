//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

void calculateWordCount(char **arr, int n)
{
    int i, j, count = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; arr[i][j] != '\0'; j++)
        {
            if (arr[i][j] == ' ' || arr[i][j] == '\t' || arr[i][j] == '\n')
            {
                count++;
            }
        }
    }
    printf("Total word count: %d\n", count);
}

int main()
{
    char **arr;
    int n, i;

    printf("Enter the number of documents: ");
    scanf("%d", &n);

    arr = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(MAX * sizeof(char));
    }

    printf("Enter the documents: ");
    for (i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }

    calculateWordCount(arr, n);

    for (i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}