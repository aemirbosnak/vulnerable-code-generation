//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100

typedef struct CSVReader
{
    char **data;
    int lines;
    int cols;
} CSVReader;

CSVReader* csv_reader_init(int lines, int cols)
{
    CSVReader* reader = malloc(sizeof(CSVReader));
    reader->data = malloc(sizeof(char *) * lines);
    for (int i = 0; i < lines; i++)
    {
        reader->data[i] = malloc(sizeof(char) * cols);
    }
    reader->lines = lines;
    reader->cols = cols;
    return reader;
}

void csv_reader_add_data(CSVReader* reader, char **data, int num_cols)
{
    for (int i = 0; i < reader->lines; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            reader->data[i][j] = data[j];
        }
    }
}

void csv_reader_free(CSVReader* reader)
{
    for (int i = 0; i < reader->lines; i++)
    {
        free(reader->data[i]);
    }
    free(reader->data);
    free(reader);
}

int main()
{
    CSVReader* reader = csv_reader_init(5, 3);
    char **data = malloc(sizeof(char *) * 5);
    for (int i = 0; i < 5; i++)
    {
        data[i] = malloc(sizeof(char) * 3);
    }
    data[0] = "John Doe";
    data[1] = "Jane Doe";
    data[2] = "Peter Pan";
    data[3] = "Mary Poppins";
    data[4] = "The Wizard of Oz";

    csv_reader_add_data(reader, data, 3);

    for (int i = 0; i < reader->lines; i++)
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