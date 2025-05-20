//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSVReader
{
    FILE* file;
    char** buffer;
    int rows;
    int cols;
} CSVReader;

CSVReader* csv_reader_init(char* filename)
{
    CSVReader* reader = malloc(sizeof(CSVReader));

    reader->file = fopen(filename, "r");
    if (reader->file == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    reader->buffer = NULL;
    reader->rows = 0;
    reader->cols = 0;

    return reader;
}

void csv_reader_read(CSVReader* reader)
{
    char line[MAX_BUFFER_SIZE];
    char* csv_data[MAX_BUFFER_SIZE];
    int i = 0;

    while (fgets(line, MAX_BUFFER_SIZE, reader->file) != NULL)
    {
        csv_data[i++] = strdup(line);
    }

    reader->buffer = csv_data;
    reader->rows = i;
    reader->cols = 0;

    for (i = 0; csv_data[i] != NULL; i++)
    {
        char* cell = strtok(csv_data[i], ",");
        while (cell)
        {
            reader->cols++;
            cell = strtok(NULL, ",");
        }
    }
}

void csv_reader_finalize(CSVReader* reader)
{
    fclose(reader->file);
    free(reader->buffer);
    free(reader);
}

int main()
{
    CSVReader* reader = csv_reader_init("example.csv");
    csv_reader_read(reader);
    csv_reader_finalize(reader);

    return 0;
}