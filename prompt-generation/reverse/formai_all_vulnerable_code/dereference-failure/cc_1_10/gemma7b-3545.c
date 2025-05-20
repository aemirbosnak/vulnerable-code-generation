//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

int main()
{
    // Allocate memory for the CSV reader
    char **csv_reader = (char**)malloc(MAX_ROWS * sizeof(char*));
    for (int i = 0; i < MAX_ROWS; i++)
    {
        csv_reader[i] = (char*)malloc(MAX_COLS * sizeof(char));
    }

    // Read the CSV file
    FILE* csv_file = fopen("data.csv", "r");
    if (csv_file == NULL)
    {
        return 1;
    }

    // Get the number of rows and columns
    int num_rows = 0;
    char line[MAX_COLS];
    while (fgets(line, MAX_COLS, csv_file) != NULL)
    {
        num_rows++;
    }

    // Allocate memory for the header
    char **header = (char**)malloc(num_rows * sizeof(char*));
    for (int i = 0; i < num_rows; i++)
    {
        header[i] = (char*)malloc(MAX_COLS * sizeof(char));
    }

    // Read the header
    rewind(csv_file);
    int i = 0;
    while (fgets(line, MAX_COLS, csv_file) != NULL)
    {
        strcpy(header[i], line);
        i++;
    }

    // Print the header
    for (int i = 0; i < num_rows; i++)
    {
        printf("%s\n", header[i]);
    }

    // Free the memory
    for (int i = 0; i < MAX_ROWS; i++)
    {
        free(csv_reader[i]);
    }
    free(csv_reader);
    for (int i = 0; i < num_rows; i++)
    {
        free(header[i]);
    }
    free(header);

    return 0;
}