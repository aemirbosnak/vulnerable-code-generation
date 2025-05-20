//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: imaginative
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

CSVReader* CSVReader_create(char* filename)
{
    CSVReader* reader = malloc(sizeof(CSVReader));
    reader->file = fopen(filename, "r");
    reader->buffer = NULL;
    reader->lines = 0;
    reader->columns = 0;
    return reader;
}

void CSVReader_destroy(CSVReader* reader)
{
    fclose(reader->file);
    free(reader->buffer);
    free(reader);
}

int CSVReader_read(CSVReader* reader)
{
    char* line = NULL;
    int line_length = 0;

    if (reader->lines == reader->columns)
    {
        reader->buffer = realloc(reader->buffer, (reader->lines + 1) * MAX_BUFFER_SIZE);
        reader->lines++;
    }

    line = fgets(reader->buffer[reader->lines - 1], MAX_BUFFER_SIZE, reader->file);

    if (!line)
    {
        return 0;
    }

    reader->lines++;
    return 1;
}

int main()
{
    CSVReader* reader = CSVReader_create("data.csv");

    while (CSVReader_read(reader))
    {
        // Process the line
        for (int i = 0; i < reader->columns; i++)
        {
            printf("%s,", reader->buffer[reader->lines - 1][i]);
        }
        printf("\n");
    }

    CSVReader_destroy(reader);

    return 0;
}