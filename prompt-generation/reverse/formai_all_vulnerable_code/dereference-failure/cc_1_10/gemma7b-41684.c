//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a CSV reader function
void csv_reader(char *filename)
{
    // Open the file
    FILE *fp = fopen(filename, "r");

    // Check if the file is open
    if (fp == NULL)
    {
        printf("Error opening file: %s", filename);
        exit(1);
    }

    // Allocate memory for the CSV data
    char **data = NULL;
    int num_rows = 0;

    // Read the file line by line
    char line[1024];
    while (fgets(line, 1024, fp) != NULL)
    {
        // Increment the number of rows
        num_rows++;

        // Reallocate memory for the data if necessary
        if (data == NULL)
        {
            data = malloc(num_rows * sizeof(char *));
        }

        // Create a new row in the data
        data[num_rows - 1] = strdup(line);
    }

    // Close the file
    fclose(fp);

    // Print the data
    for (int i = 0; i < num_rows; i++)
    {
        printf("%s\n", data[i]);
    }

    // Free the memory
    free(data);
}

int main()
{
    // CSV reader function call
    csv_reader("data.csv");

    return 0;
}