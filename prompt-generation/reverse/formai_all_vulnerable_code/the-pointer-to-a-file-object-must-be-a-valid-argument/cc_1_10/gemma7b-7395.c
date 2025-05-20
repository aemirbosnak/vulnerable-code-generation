//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000

typedef struct CSVReader
{
    FILE* file;
    char** data;
    int lines;
    int columns;
} CSVReader;

CSVReader* csv_reader_init(char* filename)
{
    CSVReader* reader = malloc(sizeof(CSVReader));
    reader->file = fopen(filename, "r");
    reader->data = NULL;
    reader->lines = 0;
    reader->columns = 0;

    return reader;
}

void csv_reader_read(CSVReader* reader)
{
    char line[MAX_LINES];
    char* token;
    int i = 0;

    while (fgets(line, MAX_LINES, reader->file) != NULL)
    {
        reader->lines++;

        token = strtok(line, ",");
        while (token)
        {
            reader->columns++;
            reader->data = realloc(reader->data, reader->lines * (reader->columns + 1) * sizeof(char*));
            reader->data[reader->lines - 1][reader->columns - 1] = token;
            token = strtok(NULL, ",");
        }
    }
}

void csv_reader_close(CSVReader* reader)
{
    fclose(reader->file);
    free(reader->data);
    free(reader);
}

int main()
{
    CSVReader* reader = csv_reader_init("data.csv");
    csv_reader_read(reader);
    csv_reader_close(reader);

    return 0;
}