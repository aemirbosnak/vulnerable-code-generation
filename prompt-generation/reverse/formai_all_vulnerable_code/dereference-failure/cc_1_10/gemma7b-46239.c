//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSV_Record
{
    char **columns;
    int num_columns;
    int num_rows;
} CSV_Record;

CSV_Record *read_csv(char *filename)
{
    CSV_Record *record = malloc(sizeof(CSV_Record));
    record->columns = NULL;
    record->num_columns = 0;
    record->num_rows = 0;

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        return NULL;
    }

    char buffer[MAX_BUFFER_SIZE];
    char *line = NULL;
    int line_num = 0;

    // Read line by line from the file
    while ((line = fgets(buffer, MAX_BUFFER_SIZE, file)) != NULL)
    {
        // Increment the number of rows
        record->num_rows++;

        // Split the line into columns
        char **columns = NULL;
        int num_columns = 0;
        char *column = strtok(line, ",");
        while (column)
        {
            columns = realloc(columns, (num_columns + 1) * sizeof(char *));
            columns[num_columns++] = strdup(column);
            column = strtok(NULL, ",");
        }

        // Update the number of columns
        record->num_columns = num_columns;

        // Allocate memory for the columns
        record->columns = columns;
    }

    fclose(file);

    return record;
}

int main()
{
    CSV_Record *record = read_csv("data.csv");

    // Print the number of rows and columns
    printf("Number of rows: %d\n", record->num_rows);
    printf("Number of columns: %d\n", record->num_columns);

    // Print the column headers
    for (int i = 0; i < record->num_columns; i++)
    {
        printf("%s, ", record->columns[i]);
    }

    printf("\n");

    // Print the data
    for (int i = 0; i < record->num_rows; i++)
    {
        for (int j = 0; j < record->num_columns; j++)
        {
            printf("%s, ", record->columns[j][i]);
        }

        printf("\n");
    }

    free(record);

    return 0;
}