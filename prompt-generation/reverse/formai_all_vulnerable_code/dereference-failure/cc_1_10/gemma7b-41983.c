//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1024

typedef struct CSV_Reader {
    char **data;
    int rows;
    int cols;
} CSV_Reader;

CSV_Reader* csv_reader_new(int cols)
{
    CSV_Reader* reader = malloc(sizeof(CSV_Reader));
    reader->data = malloc(sizeof(char*) * MAX_ROWS);
    reader->rows = 0;
    reader->cols = cols;
    return reader;
}

void csv_reader_append(CSV_Reader* reader, char** row)
{
    reader->data[reader->rows++] = row;
}

void csv_reader_free(CSV_Reader* reader)
{
    free(reader->data);
    free(reader);
}

int main()
{
    CSV_Reader* reader = csv_reader_new(5);
    char** row = malloc(sizeof(char*) * reader->cols);
    row[0] = "John Doe";
    row[1] = "New York";
    row[2] = "Software Engineer";
    row[3] = "25";
    row[4] = "male";

    csv_reader_append(reader, row);

    row = malloc(sizeof(char*) * reader->cols);
    row[0] = "Jane Doe";
    row[1] = "Los Angeles";
    row[2] = "Marketing Manager";
    row[3] = "30";
    row[4] = "female";

    csv_reader_append(reader, row);

    for (int i = 0; i < reader->rows; i++)
    {
        for (int j = 0; j < reader->cols; j++)
        {
            printf("%s ", reader->data[i][j]);
        }
        printf("\n");
    }

    csv_reader_free(reader);

    return 0;
}