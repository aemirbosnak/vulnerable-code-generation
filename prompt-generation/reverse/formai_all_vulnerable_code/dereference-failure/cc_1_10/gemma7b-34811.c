//Gemma-7B DATASET v1.0 Category: Data mining ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1024

int main()
{
    // Load the data
    char **data = NULL;
    data = (char **)malloc(MAX_SIZE * sizeof(char *));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        data[i] = (char *)malloc(MAX_SIZE * sizeof(char));
    }

    // Get the data from the file
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    // Read the data from the file
    int i = 0;
    while (!feof(fp))
    {
        fgets(data[i], MAX_SIZE, fp);
        i++;
    }

    // Close the file
    fclose(fp);

    // Analyze the data
    for (int i = 0; i < MAX_SIZE; i++)
    {
        // Split the data into words
        char *word = strtok(data[i], " ");

        // Count the number of words
        int num_words = 0;
        while (word)
        {
            num_words++;
            word = strtok(NULL, " ");
        }

        // Store the number of words in the data
        data[i] = (char *)realloc(data[i], (num_words + 1) * sizeof(char));
        data[i][num_words] = '\0';
    }

    // Print the data
    for (int i = 0; i < MAX_SIZE; i++)
    {
        printf("%s\n", data[i]);
    }

    // Free the memory
    for (int i = 0; i < MAX_SIZE; i++)
    {
        free(data[i]);
    }
    free(data);

    return 0;
}