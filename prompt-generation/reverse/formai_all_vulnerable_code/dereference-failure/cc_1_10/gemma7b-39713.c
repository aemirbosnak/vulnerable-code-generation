//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: expert-level
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
    int columnCount;
    char delimiter;
} CSVReader;

CSVReader* csvReader_init(char* filename, char delimiter)
{
    CSVReader* reader = malloc(sizeof(CSVReader));
    reader->file = fopen(filename, "r");
    reader->buffer = NULL;
    reader->bufferSize = 0;
    reader->currentLine = 0;
    reader->columnCount = 0;
    reader->delimiter = delimiter;

    return reader;
}

void csvReader_read(CSVReader* reader)
{
    char line[MAX_BUFFER_SIZE];
    char* token;

    getline(reader->file, line, MAX_BUFFER_SIZE);
    reader->currentLine++;

    reader->buffer = realloc(reader->buffer, (reader->bufferSize + 1) * sizeof(char*));
    reader->buffer[reader->bufferSize++] = strdup(line);

    token = strtok(line, ",");
    reader->columnCount = 0;
    while (token)
    {
        reader->buffer[reader->bufferSize - 1][reader->columnCount++] = strdup(token);
        token = strtok(NULL, ",");
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
    CSVReader* reader = csvReader_init("data.csv", ',');
    csvReader_read(reader);
    csvReader_finalize(reader);

    return 0;
}