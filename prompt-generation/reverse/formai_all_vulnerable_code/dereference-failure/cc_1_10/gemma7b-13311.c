//Gemma-7B DATASET v1.0 Category: Data mining ; Style: expert-level
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
    printf("Enter the data (separated by commas): ");
    char input[MAX_SIZE];
    scanf("%s", input);

    // Split the data into individual records
    char *record = strtok(input, ",");
    int record_number = 0;
    while (record)
    {
        // Store the record
        strcpy(data[record_number], record);
        record_number++;

        // Get the next record
        record = strtok(NULL, ",");
    }

    // Analyze the data
    for (int i = 0; i < record_number; i++)
    {
        // Print the record
        printf("Record %d: %s\n", i + 1, data[i]);

        // Count the number of words in the record
        int num_words = 0;
        char *word = strtok(data[i], " ");
        while (word)
        {
            num_words++;
            word = strtok(NULL, " ");
        }

        // Print the number of words
        printf("Number of words in record %d: %d\n", i + 1, num_words);
    }

    // Free the memory
    for (int i = 0; i < MAX_SIZE; i++)
    {
        free(data[i]);
    }
    free(data);

    return 0;
}