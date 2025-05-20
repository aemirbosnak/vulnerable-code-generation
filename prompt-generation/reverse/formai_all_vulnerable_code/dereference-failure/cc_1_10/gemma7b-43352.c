//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSVReader
{
    FILE* file;
    char** buffer;
    int bufferSize;
    int currentPosition;
} CSVReader;

CSVReader* csvReader_init(char* filename)
{
    CSVReader* reader = malloc(sizeof(CSVReader));
    reader->file = fopen(filename, "r");
    reader->buffer = NULL;
    reader->bufferSize = 0;
    reader->currentPosition = 0;

    return reader;
}

void csvReader_readNextLine(CSVReader* reader)
{
    char* line = NULL;
    int lineLength = 0;

    if (reader->currentPosition == reader->bufferSize)
    {
        reader->bufferSize *= 2;
        reader->buffer = realloc(reader->buffer, reader->bufferSize * sizeof(char*));
    }

    line = fgets(reader->buffer[reader->currentPosition], MAX_BUFFER_SIZE, reader->file);
    reader->currentPosition++;

    if (line)
    {
        lineLength = strlen(line) + 1;
        reader->buffer[reader->currentPosition - 1] = malloc(lineLength);
        strcpy(reader->buffer[reader->currentPosition - 1], line);
    }
}

void csvReader_finalize(CSVReader* reader)
{
    fclose(reader->file);
    free(reader->buffer);
    free(reader);
}

int main()
{
    CSVReader* reader = csvReader_init("example.csv");

    while (!feof(reader->file))
    {
        csvReader_readNextLine(reader);
    }

    csvReader_finalize(reader);

    return 0;
}