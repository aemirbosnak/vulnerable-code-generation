//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSVReader
{
    FILE *fp;
    char **buffer;
    int bufferSize;
    int currentLine;
    int columns;
} CSVReader;

CSVReader *csvReaderCreate(char *filename, int columns)
{
    CSVReader *reader = malloc(sizeof(CSVReader));

    reader->fp = fopen(filename, "r");
    if (reader->fp == NULL)
    {
        return NULL;
    }

    reader->bufferSize = MAX_BUFFER_SIZE;
    reader->buffer = malloc(reader->bufferSize);
    reader->currentLine = 0;
    reader->columns = columns;

    return reader;
}

void csvReaderDestroy(CSVReader *reader)
{
    fclose(reader->fp);
    free(reader->buffer);
    free(reader);
}

char **csvReaderGetLine(CSVReader *reader)
{
    char **line = NULL;

    if (reader->currentLine >= reader->bufferSize)
    {
        reader->bufferSize *= 2;
        reader->buffer = realloc(reader->buffer, reader->bufferSize);
    }

    line = reader->buffer + reader->currentLine++;

    return line;
}

int main()
{
    CSVReader *reader = csvReaderCreate("example.csv", 3);

    char **line = csvReaderGetLine(reader);

    if (line)
    {
        for (int i = 0; i < reader->columns; i++)
        {
            printf("%s,", line[i]);
        }

        printf("\n");
    }

    csvReaderDestroy(reader);

    return 0;
}