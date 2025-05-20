//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSV_Reader
{
    char **data;
    int rows;
    int cols;
} CSV_Reader;

CSV_Reader *csv_reader_init(int rows, int cols)
{
    CSV_Reader *reader = malloc(sizeof(CSV_Reader));
    reader->data = malloc(sizeof(char *) * rows);
    for (int i = 0; i < rows; i++)
    {
        reader->data[i] = malloc(sizeof(char) * cols);
    }
    reader->rows = rows;
    reader->cols = cols;
    return reader;
}

void csv_reader_add_data(CSV_Reader *reader, char **data, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            reader->data[i][j] = data[i][j];
        }
    }
}

void csv_reader_print(CSV_Reader *reader)
{
    for (int i = 0; i < reader->rows; i++)
    {
        for (int j = 0; j < reader->cols; j++)
        {
            printf("%s,", reader->data[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    CSV_Reader *reader = csv_reader_init(5, 3);
    char **data = malloc(sizeof(char *) * 5);
    for (int i = 0; i < 5; i++)
    {
        data[i] = malloc(sizeof(char) * 3);
    }
    data[0][0] = 'a';
    data[0][1] = 'b';
    data[0][2] = 'c';
    csv_reader_add_data(reader, data, 5, 3);
    csv_reader_print(reader);
    free(reader);
    free(data);
    return 0;
}