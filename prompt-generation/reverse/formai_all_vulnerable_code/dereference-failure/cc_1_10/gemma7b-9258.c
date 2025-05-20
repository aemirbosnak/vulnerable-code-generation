//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSVReader
{
    char **data;
    int rows;
    int cols;
} CSVReader;

CSVReader* csv_reader_init(int rows, int cols)
{
    CSVReader* reader = (CSVReader*)malloc(sizeof(CSVReader));

    reader->data = (char**)malloc(rows * sizeof(char*));
    for (int r = 0; r < rows; r++)
    {
        reader->data[r] = (char*)malloc(cols * sizeof(char));
    }

    reader->rows = rows;
    reader->cols = cols;

    return reader;
}

void csv_reader_free(CSVReader* reader)
{
    for (int r = 0; r < reader->rows; r++)
    {
        free(reader->data[r]);
    }

    free(reader->data);
    free(reader);
}

int csv_reader_get_value(CSVReader* reader, int row, int col)
{
    return reader->data[row][col];
}

int main()
{
    CSVReader* reader = csv_reader_init(5, 3);

    reader->data[0][0] = 10;
    reader->data[0][1] = 20;
    reader->data[0][2] = 30;

    reader->data[1][0] = 40;
    reader->data[1][1] = 50;
    reader->data[1][2] = 60;

    for (int r = 0; r < reader->rows; r++)
    {
        for (int c = 0; c < reader->cols; c++)
        {
            printf("%d ", csv_reader_get_value(reader, r, c));
        }

        printf("\n");
    }

    csv_reader_free(reader);

    return 0;
}