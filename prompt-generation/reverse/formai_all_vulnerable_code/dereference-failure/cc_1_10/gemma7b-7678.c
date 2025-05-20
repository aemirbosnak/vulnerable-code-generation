//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_COLS 20

int main()
{
    char **csv_data = NULL;
    int num_lines = 0;
    int num_cols = 0;
    char line[MAX_LINES];

    FILE *csv_file = fopen("data.csv", "r");
    if (csv_file == NULL)
    {
        return 1;
    }

    // Read the first line to get the number of columns
    fgets(line, MAX_LINES, csv_file);
    char *column_headers = strtok(line, ",");
    num_cols = count_columns(column_headers);

    // Allocate memory for the data
    csv_data = malloc(num_lines * sizeof(char *) + num_cols * sizeof(char *) + 1);
    if (csv_data == NULL)
    {
        return 1;
    }

    // Read the remaining lines and store the data
    while (fgets(line, MAX_LINES, csv_file) != NULL)
    {
        char *data = strtok(line, ",");
        int i = 0;
        for (i = 0; data[i] != '\0'; i++)
        {
            csv_data[num_lines][i] = data[i];
        }
        num_lines++;
    }

    // Close the file
    fclose(csv_file);

    // Print the data
    for (int i = 0; i < num_lines; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            printf("%s,", csv_data[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    free(csv_data);

    return 0;
}

int count_columns(char *headers)
{
    char *header = strtok(headers, ",");
    int num_cols = 0;
    while (header)
    {
        num_cols++;
        header = strtok(NULL, ",");
    }
    return num_cols;
}