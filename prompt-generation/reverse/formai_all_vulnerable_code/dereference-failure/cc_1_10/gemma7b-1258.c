//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSVReader
{
    char ***data;
    int rows;
    int cols;
} CSVReader;

CSVReader *csv_reader_init(int rows, int cols)
{
    CSVReader *reader = malloc(sizeof(CSVReader));

    reader->data = malloc(rows * sizeof(char **));
    for (int r = 0; r < rows; r++)
    {
        reader->data[r] = malloc(cols * sizeof(char *));
        for (int c = 0; c < cols; c++)
        {
            reader->data[r][c] = NULL;
        }
    }

    reader->rows = rows;
    reader->cols = cols;

    return reader;
}

void csv_reader_set_value(CSVReader *reader, int row, int col, char *value)
{
    reader->data[row][col] = strdup(value);
}

char *csv_reader_get_value(CSVReader *reader, int row, int col)
{
    return reader->data[row][col];
}

void csv_reader_free(CSVReader *reader)
{
    for (int r = 0; r < reader->rows; r++)
    {
        for (int c = 0; c < reader->cols; c++)
        {
            free(reader->data[r][c]);
        }
        free(reader->data[r]);
    }
    free(reader->data);
    free(reader);
}

int main()
{
    CSVReader *reader = csv_reader_init(5, 3);

    csv_reader_set_value(reader, 0, 0, "John Doe");
    csv_reader_set_value(reader, 1, 1, "Jane Doe");
    csv_reader_set_value(reader, 2, 2, "Peter Pan");

    char *name = csv_reader_get_value(reader, 1, 0);
    printf("Name: %s\n", name);

    csv_reader_free(reader);

    return 0;
}