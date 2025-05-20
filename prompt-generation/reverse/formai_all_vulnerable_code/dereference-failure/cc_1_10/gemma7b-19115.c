//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: real-life
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
    {
        reader->data[r] = malloc(sizeof(char *) * cols);
    }
    reader->rows = rows;
    reader->cols = cols;
    return reader;
}

void CSVReader_free(CSVReader *reader)
{
    for (int r = 0; r < reader->rows; r++)
    {
        free(reader->data[r]);
    }
    free(reader->data);
    free(reader);
}

int main()
{
    CSVReader *reader = CSVReader_init(5, 3);

    reader->data[0][0] = "John Doe";
    reader->data[0][1] = "New York";
    reader->data[0][2] = "123 Main St";

    reader->data[1][0] = "Jane Doe";
    reader->data[1][1] = "Los Angeles";
    reader->data[1][2] = "456 Oak Ave";

    reader->data[2][0] = "Bob Smith";
    reader->data[2][1] = "Chicago";
    reader->data[2][2] = "789 Oak St";

    reader->data[3][0] = "Alice White";
    reader->data[3][1] = "San Francisco";
    reader->data[3][2] = "123 Main St";

    reader->data[4][0] = "Tom Brown";
    reader->data[4][1] = "Boston";
    reader->data[4][2] = "456 Oak Ave";

    for (int r = 0; r < reader->rows; r++)
    {
        for (int c = 0; c < reader->cols; c++)
        {
            printf("%s ", reader->data[r][c]);
        }
        printf("\n");
    }

    CSVReader_free(reader);

    return 0;
}