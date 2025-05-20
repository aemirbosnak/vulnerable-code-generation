//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CSVReader
{
    FILE* file;
    char** data;
    int rows;
    int cols;
} CSVReader;

CSVReader* csv_reader_init(char* filename)
{
    CSVReader* reader = malloc(sizeof(CSVReader));
    reader->file = fopen(filename, "r");
    reader->data = NULL;
    reader->rows = 0;
    reader->cols = 0;

    return reader;
}

void csv_reader_read(CSVReader* reader)
{
    char line[1024];
    char** data = NULL;
    int i = 0;

    while (fgets(line, 1024, reader->file) != NULL)
    {
        data = realloc(data, (reader->rows + 1) * sizeof(char*));
        reader->data = data;

        reader->rows++;

        char* token = strtok(line, ",");
        while (token)
        {
            reader->cols++;
            data[reader->rows - 1] = strdup(token);
            token = strtok(NULL, ",");
        }
    }
}

void csv_reader_free(CSVReader* reader)
{
    fclose(reader->file);
    free(reader->data);
    free(reader);
}

int main()
{
    CSVReader* reader = csv_reader_init("data.csv");
    csv_reader_read(reader);
    csv_reader_free(reader);

    return 0;
}