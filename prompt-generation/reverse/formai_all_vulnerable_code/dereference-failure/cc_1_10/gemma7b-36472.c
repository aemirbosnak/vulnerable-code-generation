//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CsvReader
{
    FILE *fp;
    char **buffer;
    int bufferSize;
    int currentLine;
    char **columns;
    int columnCount;
} CsvReader;

CsvReader *createCsvReader(const char *filename)
{
    CsvReader *reader = malloc(sizeof(CsvReader));
    reader->fp = fopen(filename, "r");
    reader->buffer = NULL;
    reader->bufferSize = MAX_BUFFER_SIZE;
    reader->currentLine = 0;
    reader->columns = NULL;
    reader->columnCount = 0;

    return reader;
}

void readCsvLine(CsvReader *reader)
{
    char *line = NULL;
    size_t lineSize = 0;

    getline(&line, &lineSize, reader->fp);

    if (line)
    {
        reader->currentLine++;

        // Allocate memory for columns if needed
        if (reader->columns == NULL)
        {
            reader->columns = malloc(sizeof(char *) * reader->bufferSize);
            reader->columnCount = 0;
        }

        // Parse the line and store columns
        char *column = strtok(line, ",");
        while (column)
        {
            reader->columns[reader->columnCount++] = strdup(column);
            column = strtok(NULL, ",");
        }

        free(line);
    }
}

void destroyCsvReader(CsvReader *reader)
{
    fclose(reader->fp);
    free(reader->buffer);
    free(reader->columns);
    free(reader);
}

int main()
{
    CsvReader *reader = createCsvReader("data.csv");

    readCsvLine(reader);

    for (int i = 0; reader->columns[i] != NULL; i++)
    {
        printf("%s,", reader->columns[i]);
    }

    printf("\n");

    destroyCsvReader(reader);

    return 0;
}