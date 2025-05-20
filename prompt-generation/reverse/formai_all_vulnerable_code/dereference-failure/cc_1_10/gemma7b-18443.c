//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: excited
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
    for (int r = 0; r < rows; r++)
    {
        reader->data[r] = malloc(sizeof(char) * cols);
    }
    reader->rows = rows;
    reader->cols = cols;
    return reader;
}

void csv_reader_free(CSV_Reader *reader)
{
    for (int r = 0; r < reader->rows; r++)
    {
        free(reader->data[r]);
    }
    free(reader->data);
    free(reader);
}

int csv_reader_get_value(CSV_Reader *reader, int row, int col)
{
    return reader->data[row][col];
}

int main()
{
    CSV_Reader *reader = csv_reader_init(5, 3);

    // Populate the CSV reader with data
    reader->data[0][0] = 10;
    reader->data[0][1] = "John Doe";
    reader->data[0][2] = "New York";

    reader->data[1][0] = 20;
    reader->data[1][1] = "Jane Doe";
    reader->data[1][2] = "Los Angeles";

    // Get the value from the CSV reader
    int value = csv_reader_get_value(reader, 0, 0);
    printf("Value: %d\n", value);

    // Free the CSV reader
    csv_reader_free(reader);

    return 0;
}