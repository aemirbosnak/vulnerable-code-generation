//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSVReader
{
    FILE *file;
    char **buffer;
    int lines;
    int currentLine;
    int columnCount;
    char **columnNames;
} CSVReader;

CSVReader *csvReader_init(const char *filename)
{
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->file = fopen(filename, "r");
    reader->buffer = NULL;
    reader->lines = 0;
    reader->currentLine = 0;
    reader->columnCount = 0;
    reader->columnNames = NULL;

    return reader;
}

void csvReader_parseLine(CSVReader *reader)
{
    char line[MAX_BUFFER_SIZE];
    fgets(line, MAX_BUFFER_SIZE, reader->file);

    // Calculate number of columns
    int columns = 0;
    char *token = strtok(line, ",");
    while (token)
    {
        columns++;
        token = strtok(NULL, ",");
    }

    // Allocate memory for column names and data
    if (reader->columnNames == NULL)
    {
        reader->columnNames = malloc(columns * sizeof(char *));
    }

    reader->columnCount = columns;

    // Parse column names
    token = strtok(line, ",");
    for (int i = 0; i < columns; i++)
    {
        reader->columnNames[i] = strdup(token);
        token = strtok(NULL, ",");
    }

    // Increment the current line
    reader->currentLine++;
}

void csvReader_close(CSVReader *reader)
{
    fclose(reader->file);
    free(reader->buffer);
    free(reader->columnNames);
    free(reader);
}

int main()
{
    CSVReader *reader = csvReader_init("example.csv");

    // Parse lines
    while (!feof(reader->file))
    {
        csvReader_parseLine(reader);
    }

    // Print column names
    for (int i = 0; i < reader->columnCount; i++)
    {
        printf("%s,", reader->columnNames[i]);
    }

    printf("\n");

    // Close the reader
    csvReader_close(reader);

    return 0;
}