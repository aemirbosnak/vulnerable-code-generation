//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: secure
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

CSVReader *csvReader_init(int rows, int cols)
{
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->data = malloc(sizeof(char *) * rows);
    for (int i = 0; i < rows; i++)
    {
        reader->data[i] = malloc(sizeof(char) * cols);
    }
    reader->rows = rows;
    reader->cols = cols;

    return reader;
}

void csvReader_free(CSVReader *reader)
{
    for (int i = 0; i < reader->rows; i++)
    {
        free(reader->data[i]);
    }
    free(reader->data);
    free(reader);
}

int csvReader_get_num_rows(CSVReader *reader)
{
    return reader->rows;
}

int csvReader_get_num_cols(CSVReader *reader)
{
    return reader->cols;
}

char **csvReader_get_data(CSVReader *reader)
{
    return reader->data;
}

int main()
{
    CSVReader *reader = csvReader_init(5, 3);

    reader->data[0][0] = "John Doe";
    reader->data[0][1] = "New York";
    reader->data[0][2] = 30;

    reader->data[1][0] = "Jane Doe";
    reader->data[1][1] = "Los Angeles";
    reader->data[1][2] = 25;

    reader->data[2][0] = "Peter Pan";
    reader->data[2][1] = "Neverland";
    reader->data[2][2] = 12;

    reader->data[3][0] = "Mary Poppins";
    reader->data[3][1] = "Cherry Tree Lane";
    reader->data[3][2] = 40;

    reader->data[4][0] = "The Wizard of Oz";
    reader->data[4][1] = "Emerald City";
    reader->data[4][2] = 50;

    for (int i = 0; i < csvReader_get_num_rows(reader); i++)
    {
        for (int j = 0; j < csvReader_get_num_cols(reader); j++)
        {
            printf("%s, %s, %d\n", csvReader_get_data(reader)[i][j]);
        }
    }

    csvReader_free(reader);

    return 0;
}