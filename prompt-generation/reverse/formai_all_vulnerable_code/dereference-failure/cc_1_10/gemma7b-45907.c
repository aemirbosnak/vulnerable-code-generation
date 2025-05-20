//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSVReader
{
    FILE* file_ptr;
    char** buffer;
    int rows;
    int cols;
} CSVReader;

CSVReader* csv_reader_init(char* filename)
{
    CSVReader* reader = malloc(sizeof(CSVReader));
    reader->file_ptr = fopen(filename, "r");
    reader->buffer = NULL;
    reader->rows = 0;
    reader->cols = 0;

    return reader;
}

void csv_reader_free(CSVReader* reader)
{
    fclose(reader->file_ptr);
    free(reader->buffer);
    free(reader);
}

int csv_reader_read(CSVReader* reader)
{
    int rows = reader->rows;
    char** buffer = reader->buffer;

    if (buffer == NULL)
    {
        reader->buffer = malloc(MAX_BUFFER_SIZE * sizeof(char*));
        reader->cols = 0;
        reader->rows = 0;
    }

    char line[MAX_BUFFER_SIZE];
    int line_length = 0;
    int i = 0;

    while (fgets(line, MAX_BUFFER_SIZE, reader->file_ptr) != NULL)
    {
        line_length = strlen(line) + 1;
        buffer[rows] = malloc(line_length * sizeof(char));
        strcpy(buffer[rows], line);
        reader->rows++;
    }

    return rows;
}

int main()
{
    CSVReader* reader = csv_reader_init("data.csv");
    int num_rows = csv_reader_read(reader);
    csv_reader_free(reader);

    printf("Number of rows: %d\n", num_rows);

    return 0;
}