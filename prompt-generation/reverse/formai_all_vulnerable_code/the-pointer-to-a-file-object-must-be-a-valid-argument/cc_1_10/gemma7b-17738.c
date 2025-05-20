//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSVReader
{
    FILE* file;
    char** buffer;
    int lines;
    int columns;
} CSVReader;

CSVReader* csv_reader_init(char* filename)
{
    CSVReader* reader = malloc(sizeof(CSVReader));
    reader->file = fopen(filename, "r");
    reader->buffer = NULL;
    reader->lines = 0;
    reader->columns = 0;

    return reader;
}

void csv_reader_read(CSVReader* reader)
{
    reader->buffer = realloc(reader->buffer, (reader->lines + 1) * MAX_BUFFER_SIZE);

    char line[MAX_BUFFER_SIZE];
    fgets(line, MAX_BUFFER_SIZE, reader->file);

    reader->lines++;
    reader->buffer[reader->lines - 1] = strdup(line);

    char* column_headers[MAX_BUFFER_SIZE];
    char* current_line = reader->buffer[reader->lines - 1];
    int i = 0;
    for (column_headers[i] = strtok(current_line, ","); column_headers[i] != NULL; i++)
    {
        reader->columns++;
    }
}

void csv_reader_close(CSVReader* reader)
{
    fclose(reader->file);
    free(reader->buffer);
    free(reader);
}

int main()
{
    CSVReader* reader = csv_reader_init("data.csv");

    while (!feof(reader->file))
    {
        csv_reader_read(reader);
    }

    csv_reader_close(reader);

    return 0;
}