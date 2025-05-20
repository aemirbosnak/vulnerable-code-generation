//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSVReader
{
    FILE *filePtr;
    char **buffer;
    int bufferSize;
    int currentLine;
    int currentColumn;
} CSVReader;

CSVReader *csvReader_init(const char *filename)
{
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->filePtr = fopen(filename, "r");
    reader->buffer = NULL;
    reader->bufferSize = 0;
    reader->currentLine = 0;
    reader->currentColumn = 0;

    return reader;
}

void csvReader_free(CSVReader *reader)
{
    fclose(reader->filePtr);
    free(reader->buffer);
    free(reader);
}

int csvReader_readLine(CSVReader *reader)
{
    reader->bufferSize = MAX_BUFFER_SIZE;
    reader->buffer = realloc(reader->buffer, reader->bufferSize * sizeof(char *));

    char line[MAX_BUFFER_SIZE];
    int numCols = fgets(line, MAX_BUFFER_SIZE, reader->filePtr);

    reader->currentLine++;
    reader->buffer[reader->currentLine - 1] = strdup(line);

    return numCols;
}

int csvReader_getColumn(CSVReader *reader, int column)
{
    char **line = reader->buffer[reader->currentLine - 1];
    char *columnData = strchr(line, ',') + 1;

    return atoi(columnData);
}

int main()
{
    CSVReader *reader = csvReader_init("data.csv");

    csvReader_readLine(reader);

    int numCols = csvReader_getColumn(reader, 2);

    printf("Number of columns in the second line: %d\n", numCols);

    csvReader_free(reader);

    return 0;
}