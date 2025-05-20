//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSVReader
{
    FILE *file;
    char **buffer;
    int bufferSize;
    int currentLine;
    int currentColumn;
} CSVReader;

CSVReader *csvReader_init(char *fileName)
{
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->file = fopen(fileName, "r");
    reader->buffer = NULL;
    reader->bufferSize = MAX_BUFFER_SIZE;
    reader->currentLine = 0;
    reader->currentColumn = 0;

    return reader;
}

void csvReader_readCSV(CSVReader *reader)
{
    char line[MAX_BUFFER_SIZE];
    getline(reader->file, line, MAX_BUFFER_SIZE);

    reader->currentLine++;

    if (reader->buffer)
    {
        free(reader->buffer);
    }

    reader->buffer = malloc(reader->bufferSize);
    strcpy(reader->buffer, line);

    reader->currentColumn = 0;
}

char *csvReader_getColumnValue(CSVReader *reader, int column)
{
    char *value = strchr(reader->buffer, ',') + 1;

    for (int i = 0; i < column; i++)
    {
        value = strchr(value, ',') + 1;
    }

    return value;
}

int main()
{
    CSVReader *reader = csvReader_init("data.csv");

    while (!feof(reader->file))
    {
        csvReader_readCSV(reader);

        char *name = csvReader_getColumnValue(reader, 0);
        char *age = csvReader_getColumnValue(reader, 1);

        printf("%s is %d years old.\n", name, atoi(age));
    }

    fclose(reader->file);
    free(reader);

    return 0;
}