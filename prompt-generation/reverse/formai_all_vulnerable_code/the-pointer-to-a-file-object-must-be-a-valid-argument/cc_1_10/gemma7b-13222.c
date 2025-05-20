//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 1024

typedef struct CSVReader
{
    FILE *fp;
    char **data;
    int num_rows, num_cols;
} CSVReader;

CSVReader *csv_reader_new(const char *filename)
{
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->fp = fopen(filename, "r");
    reader->data = NULL;
    reader->num_rows = 0;
    reader->num_cols = 0;

    return reader;
}

void csv_reader_free(CSVReader *reader)
{
    fclose(reader->fp);
    free(reader->data);
    free(reader);
}

void csv_reader_read(CSVReader *reader)
{
    char line[MAX_COLS];
    char **cols = NULL;
    int num_cols = 0;

    while (fgets(line, MAX_COLS, reader->fp) != NULL)
    {
        cols = realloc(cols, (num_cols + 1) * sizeof(char *));
        cols[num_cols++] = strdup(line);
    }

    reader->data = cols;
    reader->num_rows = num_cols;
}

int main()
{
    CSVReader *reader = csv_reader_new("data.csv");
    csv_reader_read(reader);

    for (int i = 0; i < reader->num_rows; i++)
    {
        printf("%s\n", reader->data[i]);
    }

    csv_reader_free(reader);

    return 0;
}