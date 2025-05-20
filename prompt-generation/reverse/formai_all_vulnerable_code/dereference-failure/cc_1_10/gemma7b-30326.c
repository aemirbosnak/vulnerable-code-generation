//Gemma-7B DATASET v1.0 Category: Data mining ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

void main()
{
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    char **arr = (char **)malloc(MAX_SIZE * sizeof(char *));
    char **ptr = (char **)malloc(MAX_SIZE * sizeof(char *));
    int **freq = (int *)malloc(MAX_SIZE * sizeof(int));

    // Read data from file
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        printf("Error reading file");
        return;
    }

    // Create an array of pointers to store the data
    for (i = 0; i < MAX_SIZE; i++)
    {
        arr[i] = (char *)malloc(MAX_SIZE * sizeof(char));
        ptr[i] = (char *)malloc(MAX_SIZE * sizeof(char));
    }

    // Store the data in the array
    k = 0;
    while (!feof(fp))
    {
        fscanf(fp, "%s", arr[k]);
        ptr[k] = arr[k];
        k++;
    }

    // Calculate the frequency of each word
    for (i = 0; i < k; i++)
    {
        l = strlen(ptr[i]);
        for (j = 0; j < l; j++)
        {
            m = ptr[i][j] - 'a';
            if (freq[m] == NULL)
            {
                freq[m] = 1;
            }
            else
            {
                freq[m]++;
            }
        }
    }

    // Print the frequency of each word
    for (i = 0; i < 26; i++)
    {
        if (freq[i] != NULL)
        {
            printf("%c: %d\n", i + 'a', freq[i]);
        }
    }

    // Free memory
    for (i = 0; i < MAX_SIZE; i++)
    {
        free(arr[i]);
        free(ptr[i]);
    }
    free(freq);
    fclose(fp);

    return;
}