//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CSVReader
{
    char **data;
    int rows;
    int cols;
} CSVReader;

CSVReader *csv_reader_init(int rows, int cols)
{
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->data = malloc((rows + 1) * sizeof(char *));
    reader->rows = rows;
    reader->cols = cols;

    for (int r = 0; r <= rows; r++)
    {
        reader->data[r] = malloc(cols * sizeof(char));
    }

    return reader;
}

void csv_reader_free(CSVReader *reader)
{
    for (int r = 0; r < reader->rows; r++)
    {
        free(reader->data[r]);
    }

    free(reader->data);
    free(reader);
}

void csv_reader_set_data(CSVReader *reader, char **data)
{
    for (int r = 0; r < reader->rows; r++)
    {
        for (int c = 0; c < reader->cols; c++)
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
            printf("%s ", reader->data[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    CSVReader *reader = csv_reader_init(5, 3);
    char **data = malloc(5 * sizeof(char *));
    for (int r = 0; r < 5; r++)
    {
        data[r] = malloc(3 * sizeof(char));
    }

    data[0][0] = 'a';
    data[0][1] = 'b';
    data[0][2] = 'c';

    data[1][0] = 'd';
    data[1][1] = 'e';
    data[1][2] = 'f';

    csv_reader_set_data(reader, data);
    csv_reader_print(reader);

    csv_reader_free(reader);
    free(data);

    return 0;
}