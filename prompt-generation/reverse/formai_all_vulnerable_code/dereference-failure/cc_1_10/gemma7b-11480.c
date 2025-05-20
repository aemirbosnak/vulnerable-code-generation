//Gemma-7B DATASET v1.0 Category: Data mining ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1024

int main()
{
    char **data = NULL;
    int i, j, k, n, m;

    // Allocate memory for the data
    data = (char **)malloc(MAX_SIZE * sizeof(char *));
    for(i = 0; i < MAX_SIZE; i++)
    {
        data[i] = (char *)malloc(MAX_SIZE * sizeof(char));
    }

    // Read the data
    printf("Enter the number of records: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter the data for record %d: ", i + 1);
        scanf("%s", data[i]);
    }

    // Find the maximum length of the data
    m = 0;
    for(i = 0; i < n; i++)
    {
        if(strlen(data[i]) > m)
        {
            m = strlen(data[i]);
        }
    }

    // Print the data with the maximum length
    for(i = 0; i < n; i++)
    {
        printf("Record %d: ", i + 1);
        for(j = 0; j < m; j++)
        {
            printf("%c ", data[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for(i = 0; i < MAX_SIZE; i++)
    {
        free(data[i]);
    }
    free(data);

    return 0;
}