//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 10
#define MAX_ROWS 100

typedef struct CSVReader
{
    char **data;
    int numCols;
    int numRows;
} CSVReader;

CSVReader *csvReader_init(int numCols, int numRows)
{
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->data = malloc(sizeof(char *) * numRows);
    reader->numCols = numCols;
    reader->numRows = numRows;
    return reader;
}

void csvReader_free(CSVReader *reader)
{
    free(reader->data);
    free(reader);
}

int csvReader_read(CSVReader *reader, char **line)
{
    int i = 0;
    for (i = 0; i < reader->numCols && line[i] != '\0'; i++)
    {
        line[i] = reader->data[reader->numRows - 1][i];
    }
    return i;
}

int main()
{
    CSVReader *reader = csvReader_init(5, 10);

    reader->data[0][0] = 'a';
    reader->data[0][1] = 'b';
    reader->data[0][2] = 'c';
    reader->data[0][3] = 'd';
    reader->data[0][4] = 'e';

    reader->data[1][0] = 'f';
    reader->data[1][1] = 'g';
    reader->data[1][2] = 'h';
    reader->data[1][3] = 'i';
    reader->data[1][4] = 'j';

    char *line = malloc(MAX_COLS * sizeof(char));

    int numColsRead = csvReader_read(reader, line);

    printf("Number of columns read: %d\n", numColsRead);

    for (int i = 0; i < numColsRead; i++)
    {
        printf("%c ", line[i]);
    }

    printf("\n");

    csvReader_free(reader);

    return 0;
}