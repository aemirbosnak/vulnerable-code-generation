//Gemma-7B DATASET v1.0 Category: Data mining ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
    char **data = NULL;
    int i = 0, j = 0, k = 0, n = 0;

    // Allocate memory for the data
    data = (char **)malloc(MAX * sizeof(char *));
    for (i = 0; i < MAX; i++)
    {
        data[i] = (char *)malloc(MAX * sizeof(char));
    }

    // Read the data from the file
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        return 1;
    }
    while (fscanf(fp, "%s", data[n]) != EOF)
    {
        n++;
    }
    fclose(fp);

    // Count the number of occurrences of each word
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i != j && strcmp(data[i], data[j]) == 0)
            {
                k++;
            }
        }
        printf("%s occurs %d times\n", data[i], k);
        k = 0;
    }

    // Free the memory
    for (i = 0; i < MAX; i++)
    {
        free(data[i]);
    }
    free(data);

    return 0;
}