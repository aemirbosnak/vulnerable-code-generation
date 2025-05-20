//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSVReader
{
    FILE *fp;
    char **buffer;
    int buffer_size;
    int current_row;
    int current_column;
} CSVReader;

CSVReader *csv_reader_init(char *filename)
{
    CSVReader *reader = malloc(sizeof(CSVReader));

    reader->fp = fopen(filename, "r");
    if (reader->fp == NULL)
    {
        return NULL;
    }

    reader->buffer = NULL;
    reader->buffer_size = 0;
    reader->current_row = 0;
    reader->current_column = 0;

    return reader;
}

void csv_reader_read_next_row(CSVReader *reader)
{
    char *line = NULL;
    int line_length = 0;

    getline(reader->fp, line, &line_length);

    if (line)
    {
        reader->buffer = realloc(reader->buffer, (reader->buffer_size + 1) * sizeof(char *));
        reader->buffer[reader->buffer_size++] = line;
    }

    reader->current_row++;
}

void csv_reader_close(CSVReader *reader)
{
    fclose(reader->fp);
    free(reader->buffer);
    free(reader);
}

int main()
{
    CSVReader *reader = csv_reader_init("data.csv");

    while (!feof(reader->fp))
    {
        csv_reader_read_next_row(reader);
    }

    csv_reader_close(reader);

    return 0;
}