//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
    char **data = NULL;
    int i, j, k, l, m, n = 0;
    FILE *fp;

    fp = fopen("data.csv", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    data = malloc(MAX * sizeof(char *));
    if (data == NULL)
    {
        perror("Error allocating memory");
        return 1;
    }

    l = 0;
    while (getline(fp, data[l], MAX) != NULL)
    {
        n++;
        l++;
    }

    m = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; data[i][j] != '\0'; j++)
        {
            if (data[i][j] == ',')
            {
                k = 0;
                while (data[i][j + k] != ',')
                {
                    printf("%c", data[i][j + k]);
                    k++;
                }
                printf(",");
            }
        }
        printf("\n");
    }

    free(data);
    fclose(fp);

    return 0;
}