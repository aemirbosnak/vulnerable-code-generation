//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **data = NULL;
    int rows = 0, cols = 0;
    char csv_file[] = "data.csv";

    // Open the CSV file
    FILE *fp = fopen(csv_file, "r");
    if (fp == NULL)
    {
        return EXIT_FAILURE;
    }

    // Determine the number of rows and columns
    while (getline(fp, data, 0) != NULL)
    {
        rows++;
    }
    rewind(fp);

    // Allocate memory for the data
    data = malloc(rows * sizeof(char *));
    for (int r = 0; r < rows; r++)
    {
        data[r] = malloc(cols * sizeof(char));
    }

    // Read the CSV data
    while (getline(fp, data[rows - 1], 0) != NULL)
    {
        cols = 0;
        char *line = strdup(data[rows - 1]);
        char *token = strtok(line, ",");
        while (token)
        {
            strcpy(data[rows - 1][cols++], token);
            token = strtok(NULL, ",");
        }
    }

    // Close the CSV file
    fclose(fp);

    // Print the data
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            printf("%s,", data[r][c]);
        }
        printf("\n");
    }

    // Free the memory
    for (int r = 0; r < rows; r++)
    {
        free(data[r]);
    }
    free(data);

    return EXIT_SUCCESS;
}