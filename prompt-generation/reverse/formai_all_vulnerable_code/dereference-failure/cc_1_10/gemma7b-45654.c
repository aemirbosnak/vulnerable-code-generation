//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: accurate
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

CSVReader *csv_reader_init(int rows, int cols)
{
    CSVReader *reader = (CSVReader *)malloc(sizeof(CSVReader));

    reader->data = (char **)malloc(rows * sizeof(char *));
    for (int r = 0; r < rows; r++)
    {
        reader->data[r] = (char *)malloc(cols * sizeof(char));
    }

    reader->rows = rows;
    reader->cols = cols;

    return reader;
}

void csv_reader_add_data(CSVReader *reader, char **data, int rows, int cols)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            reader->data[r][c] = data[r][c];
        }
    }
}

void csv_reader_print(CSVReader *reader)
{
    for (int r = 0; r < reader->rows; r++)
    {
        for (int c = 0; c < reader->cols; c++)
        {
            printf("%s,", reader->data[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    CSVReader *reader = csv_reader_init(5, 3);
    char **data = (char **)malloc(5 * sizeof(char *));
    for (int r = 0; r < 5; r++)
    {
        data[r] = (char *)malloc(3 * sizeof(char));
    }

    data[0][0] = 'a';
    data[0][1] = 'b';
    data[0][2] = 'c';
    data[1][0] = 'd';
    data[1][1] = 'e';
    data[1][2] = 'f';
    data[2][0] = 'g';
    data[2][1] = 'h';
    data[2][2] = 'i';
    data[3][0] = 'j';
    data[3][1] = 'k';
    data[3][2] = 'l';
    data[4][0] = 'm';
    data[4][1] = 'n';
    data[4][2] = 'o';

    csv_reader_add_data(reader, data, 5, 3);

    csv_reader_print(reader);

    free(reader->data);
    free(reader);

    return 0;
}