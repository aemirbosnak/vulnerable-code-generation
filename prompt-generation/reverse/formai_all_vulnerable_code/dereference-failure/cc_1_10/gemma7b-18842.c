//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSV_ROW {
    char **data;
    int num_cols;
} CSV_ROW;

typedef struct CSV_FILE {
    CSV_ROW **rows;
    int num_rows;
} CSV_FILE;

CSV_FILE *csv_file_new(int num_rows, int num_cols)
{
    CSV_FILE *file = malloc(sizeof(CSV_FILE));
    file->rows = malloc(sizeof(CSV_ROW *) * num_rows);
    file->num_rows = num_rows;

    for (int i = 0; i < num_rows; i++)
    {
        file->rows[i] = malloc(sizeof(CSV_ROW));
        file->rows[i]->data = malloc(sizeof(char *) * num_cols);
        file->rows[i]->num_cols = num_cols;
    }

    return file;
}

void csv_file_append_row(CSV_FILE *file, char **data, int num_cols)
{
    CSV_ROW *row = malloc(sizeof(CSV_ROW));
    row->data = malloc(sizeof(char *) * num_cols);
    row->num_cols = num_cols;

    for (int i = 0; i < num_cols; i++)
    {
        row->data[i] = strdup(data[i]);
    }

    file->rows[file->num_rows++] = row;
}

int main()
{
    CSV_FILE *file = csv_file_new(MAX_ROWS, MAX_COLS);

    char **data = malloc(sizeof(char *) * MAX_COLS);
    data[0] = "John Doe";
    data[1] = "New York";

    csv_file_append_row(file, data, 2);

    data[0] = "Jane Doe";
    data[1] = "Los Angeles";

    csv_file_append_row(file, data, 2);

    for (int i = 0; i < file->num_rows; i++)
    {
        for (int j = 0; j < file->rows[i]->num_cols; j++)
        {
            printf("%s,", file->rows[i]->data[j]);
        }

        printf("\n");
    }

    return 0;
}