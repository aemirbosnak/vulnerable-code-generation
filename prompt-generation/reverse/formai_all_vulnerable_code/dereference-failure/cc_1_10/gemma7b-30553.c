//Gemma-7B DATASET v1.0 Category: Data mining ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main()
{
    // Allocate memory for the data
    char **data = (char **)malloc(MAX_SIZE * sizeof(char *));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        data[i] = (char *)malloc(MAX_SIZE * sizeof(char));
    }

    // Get the data
    printf("Enter data: ");
    for (int i = 0; i < MAX_SIZE; i++)
    {
        scanf("%s", data[i]);
    }

    // Create a histogram
    int **histogram = (int *)malloc(MAX_SIZE * sizeof(int *));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        histogram[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    for (int i = 0; i < MAX_SIZE; i++)
    {
        histogram[i] = 0;
    }

    for (int i = 0; i < MAX_SIZE; i++)
    {
        char *word = data[i];
        for (int j = 0; word[j] != '\0'; j++)
        {
            histogram[word[j]]++;
        }
    }

    // Print the histogram
    printf("Histogram:\n");
    for (int i = 0; i < MAX_SIZE; i++)
    {
        printf("%c: %d\n", i, histogram[i]);
    }

    // Free the memory
    for (int i = 0; i < MAX_SIZE; i++)
    {
        free(data[i]);
        free(histogram[i]);
    }
    free(data);
    free(histogram);

    return 0;
}