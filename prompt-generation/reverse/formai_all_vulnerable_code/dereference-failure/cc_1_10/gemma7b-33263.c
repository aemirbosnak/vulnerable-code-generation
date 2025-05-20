//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSVReader
{
    FILE* file;
    char** buffer;
    int bufferSize;
    int currentLine;
} CSVReader;

CSVReader* CSVReader_init(char* filename)
{
    CSVReader* reader = malloc(sizeof(CSVReader));

    reader->file = fopen(filename, "r");
    reader->buffer = NULL;
    reader->bufferSize = MAX_BUFFER_SIZE;
    reader->currentLine = 0;

    return reader;
}

void CSVReader_readNextLine(CSVReader* reader)
{
    char* line = NULL;
    int lineLength = 0;

    getline(&line, &lineLength, reader->file);

    if (line)
    {
        reader->buffer = realloc(reader->buffer, (reader->currentLine + 1) * MAX_BUFFER_SIZE);
        reader->buffer[reader->currentLine++] = line;
    }
}

void CSVReader_finalize(CSVReader* reader)
{
    fclose(reader->file);
    free(reader->buffer);
    free(reader);
}

int main()
{
    CSVReader* reader = CSVReader_init("data.csv");

    while (!feof(reader->file))
    {
        CSVReader_readNextLine(reader);
    }

    CSVReader_finalize(reader);

    return 0;
}