//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Declare variables
    char **csvData = NULL;
    int rows = 0;
    int cols = 0;
    char delimiter = ',';
    FILE *csvFile = NULL;

    // Open CSV file
    csvFile = fopen("my_csv_file.csv", "r");

    // Allocate memory for CSV data
    csvData = malloc(rows * sizeof(char *));

    // Read CSV data line by line
    while (fgets(csvData[rows], 1024, csvFile) != NULL)
    {
        // Increment number of rows
        rows++;

        // Split line into columns
        char *column = strtok(csvData[rows - 1], &delimiter);

        // Increment number of columns
        while (column)
        {
            cols++;
            column = strtok(NULL, &delimiter);
        }
    }

    // Close CSV file
    fclose(csvFile);

    // Print CSV data
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            printf("%s ", csvData[r][c]);
        }
        printf("\n");
    }

    // Free memory
    free(csvData);

    return 0;
}