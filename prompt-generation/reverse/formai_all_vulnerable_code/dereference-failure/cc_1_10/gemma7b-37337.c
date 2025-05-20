//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSV_Reader
{
    FILE* file;
    char** buffer;
    int buffer_size;
    int current_row;
    int columns;
} CSV_Reader;

CSV_Reader* csv_reader_init(const char* filename, int columns)
{
    CSV_Reader* reader = (CSV_Reader*)malloc(sizeof(CSV_Reader));
    reader->file = fopen(filename, "r");
    reader->buffer = NULL;
    reader->buffer_size = 0;
    reader->current_row = 0;
    reader->columns = columns;

    return reader;
}

void csv_reader_read_next_row(CSV_Reader* reader)
{
    char* line = NULL;
    size_t line_size = 0;

    getline(reader->file, line, &line_size);

    if (line)
    {
        reader->buffer = realloc(reader->buffer, (reader->buffer_size + 1) * sizeof(char*));
        reader->buffer[reader->buffer_size++] = line;
    }
}

void csv_reader_close(CSV_Reader* reader)
{
    fclose(reader->file);
    free(reader->buffer);
    free(reader);
}

int main()
{
    CSV_Reader* reader = csv_reader_init("data.csv", 3);

    csv_reader_read_next_row(reader);

    for (int i = 0; i < reader->buffer_size; i++)
    {
        char** row = reader->buffer[i];

        for (int j = 0; j < reader->columns; j++)
        {
            printf("%s,", row[j]);
        }

        printf("\n");
    }

    csv_reader_close(reader);

    return 0;
}