//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: romantic
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

CSVReader *CSVReader_init(int rows, int cols)
{
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->data = malloc(sizeof(char *) * rows);
    for (int r = 0; r < rows; r++)
        reader->data[r] = malloc(sizeof(char) * cols);
    reader->rows = rows;
    reader->cols = cols;

    return reader;
}

void CSVReader_free(CSVReader *reader)
{
    for (int r = 0; r < reader->rows; r++)
        free(reader->data[r]);
    free(reader->data);
    free(reader);
}

int CSVReader_get_value(CSVReader *reader, int row, int col)
{
    return atoi(reader->data[row][col]);
}

int main()
{
    CSVReader *reader = CSVReader_init(5, 3);

    reader->data[0][0] = "John";
    reader->data[0][1] = "Doe";
    reader->data[0][2] = 25;

    reader->data[1][0] = "Jane";
    reader->data[1][1] = "Doe";
    reader->data[1][2] = 30;

    reader->data[2][0] = "Peter";
    reader->data[2][1] = "Pan";
    reader->data[2][2] = 35;

    reader->data[3][0] = "Mary";
    reader->data[3][1] = "Jane";
    reader->data[3][2] = 40;

    reader->data[4][0] = "Bob";
    reader->data[4][1] = "Green";
    reader->data[4][2] = 45;

    for (int r = 0; r < reader->rows; r++)
    {
        for (int c = 0; c < reader->cols; c++)
        {
            printf("%s, ", CSVReader_get_value(reader, r, c));
        }
        printf("\n");
    }

    CSVReader_free(reader);

    return 0;
}