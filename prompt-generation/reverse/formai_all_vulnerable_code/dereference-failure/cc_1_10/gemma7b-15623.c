//Gemma-7B DATASET v1.0 Category: Data mining ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000

int main()
{
    // Allocate memory for the data
    int **data = (int **)malloc(MAX_SIZE * sizeof(int *));
    for(int i = 0; i < MAX_SIZE; i++)
    {
        data[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Read the data
    FILE *fp = fopen("data.txt", "r");
    int i = 0;
    char line[1024];
    while(fgets(line, 1024, fp) != NULL)
    {
        char *p = line;
        int n = 0;
        while(p = strchr(p, ','))
        {
            data[i][n++] = atoi(p);
            p++;
        }
        data[i][n] = atoi(p);
        i++;
    }
    fclose(fp);

    // Calculate the mean of each column
    for(int j = 0; j < MAX_SIZE; j++)
    {
        int sum = 0;
        for(int i = 0; i < MAX_SIZE; i++)
        {
            sum += data[i][j];
        }
        data[MAX_SIZE - 1][j] = sum / MAX_SIZE;
    }

    // Print the mean of each column
    for(int i = 0; i < MAX_SIZE - 1; i++)
    {
        for(int j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for(int i = 0; i < MAX_SIZE; i++)
    {
        free(data[i]);
    }
    free(data);

    return 0;
}