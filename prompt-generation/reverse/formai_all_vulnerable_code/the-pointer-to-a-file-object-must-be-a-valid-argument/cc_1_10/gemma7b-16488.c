//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct CSVReader
{
    FILE *file;
    char **buffer;
    int size, pos, lineNum;
} CSVReader;

CSVReader *csvReader_init(const char *filename)
{
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->file = fopen(filename, "r");
    reader->buffer = NULL;
    reader->size = reader->pos = reader->lineNum = 0;

    return reader;
}

void csvReader_free(CSVReader *reader)
{
    fclose(reader->file);
    free(reader->buffer);
    free(reader);
}

int csvReader_readNextLine(CSVReader *reader)
{
    if (reader->buffer)
    {
        free(reader->buffer);
        reader->buffer = NULL;
    }

    reader->size = 0;
    reader->pos = 0;
    reader->lineNum++;

    char *line = fgets(reader->buffer, BUFFER_SIZE, reader->file);

    if (!line)
    {
        return 0;
    }

    reader->buffer = line;
    reader->size = strlen(line) + 1;

    return 1;
}

char **csvReader_getCSVData(CSVReader *reader)
{
    char **data = NULL;
    int numCols = 0;

    // Count the number of columns in the line
    for (int i = 0; reader->buffer[i] != '\n'; i++)
    {
        if (reader->buffer[i] == ',')
        {
            numCols++;
        }
    }

    // Allocate memory for the data
    data = malloc((numCols + 1) * sizeof(char *));

    // Extract the data from the line
    int i = 0;
    for (int col = 0; reader->buffer[i] != '\n'; i++)
    {
        if (reader->buffer[i] == ',')
        {
            data[col] = strdup(reader->buffer + i + 1);
            col++;
        }
    }

    data[numCols] = NULL;

    return data;
}

int main()
{
    CSVReader *reader = csvReader_init("test.csv");

    while (csvReader_readNextLine(reader))
    {
        char **data = csvReader_getCSVData(reader);

        for (int i = 0; data[i] != NULL; i++)
        {
            printf("%s,", data[i]);
        }

        printf("\n");
    }

    csvReader_free(reader);

    return 0;
}