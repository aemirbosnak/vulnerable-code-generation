//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSVReader
{
    FILE *file;
    char **buffer;
    int buffer_size;
    int current_row;
    int current_column;
} CSVReader;

CSVReader *csv_reader_init(char *filename)
{
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->file = fopen(filename, "r");
    reader->buffer = NULL;
    reader->buffer_size = MAX_BUFFER_SIZE;
    reader->current_row = 0;
    reader->current_column = 0;

    return reader;
}

void csv_reader_read_next_row(CSVReader *reader)
{
    int num_cols = 0;
    char **row_buffer = NULL;

    // Allocate memory for the row buffer
    row_buffer = malloc(reader->buffer_size * sizeof(char *));

    // Read the next line from the file
    char line[MAX_BUFFER_SIZE];
    fgets(line, MAX_BUFFER_SIZE, reader->file);

    // Count the number of columns in the line
    char *ptr = line;
    while (ptr = strchr(ptr, ',')) {
        num_cols++;
        ptr++;
    }

    // Update the number of columns
    reader->current_column = num_cols;

    // Parse the line into columns
    int i = 0;
    char *column_buffer = strdup(line);
    reader->buffer = row_buffer;
    for (i = 0; i < num_cols; i++) {
        reader->buffer[i] = strtok(column_buffer, ",");
        column_buffer = NULL;
    }

    // Increment the row number
    reader->current_row++;

    free(row_buffer);
}

int main()
{
    CSVReader *reader = csv_reader_init("data.csv");

    // Read the next row from the CSV file
    csv_reader_read_next_row(reader);

    // Print the columns
    for (int i = 0; i < reader->current_column; i++) {
        printf("%s, ", reader->buffer[i]);
    }

    printf("\n");

    // Read the next row from the CSV file
    csv_reader_read_next_row(reader);

    // Print the columns
    for (int i = 0; i < reader->current_column; i++) {
        printf("%s, ", reader->buffer[i]);
    }

    printf("\n");

    // Free the CSV reader
    free(reader);

    return 0;
}