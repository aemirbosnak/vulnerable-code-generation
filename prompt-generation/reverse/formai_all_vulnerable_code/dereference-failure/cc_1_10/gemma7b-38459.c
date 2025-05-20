//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CsvReader
{
    FILE* file;
    char** buffer;
    int rows;
    int cols;
} CsvReader;

CsvReader* csv_reader_init(char* filename)
{
    CsvReader* reader = malloc(sizeof(CsvReader));
    reader->file = fopen(filename, "r");
    reader->buffer = NULL;
    reader->rows = 0;
    reader->cols = 0;

    return reader;
}

void csv_reader_read(CsvReader* reader)
{
    char* line = NULL;
    size_t line_size = 0;

    getline(&line, &line_size, reader->file);

    if (line)
    {
        reader->rows++;

        if (reader->buffer == NULL)
        {
            reader->buffer = malloc(sizeof(char*) * reader->rows);
            for (int i = 0; i < reader->rows; i++)
            {
                reader->buffer[i] = malloc(MAX_BUFFER_SIZE);
            }
        }

        strcpy(reader->buffer[reader->rows - 1], line);
        free(line);
    }
}

void csv_reader_close(CsvReader* reader)
{
    fclose(reader->file);

    for (int i = 0; i < reader->rows; i++)
    {
        free(reader->buffer[i]);
    }

    free(reader->buffer);
    free(reader);
}

int main()
{
    CsvReader* reader = csv_reader_init("data.csv");

    while (!feof(reader->file))
    {
        csv_reader_read(reader);
    }

    csv_reader_close(reader);

    return 0;
}