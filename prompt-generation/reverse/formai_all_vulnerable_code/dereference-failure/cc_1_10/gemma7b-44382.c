//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100

typedef struct CSVReader
{
    char **data;
    int numRows;
    int numCols;
} CSVReader;

CSVReader* CSVReader_init(int numRows, int numCols)
{
    CSVReader* reader = malloc(sizeof(CSVReader));
    reader->data = malloc(sizeof(char *) * numRows);
    for (int i = 0; i < numRows; i++)
    {
        reader->data[i] = malloc(sizeof(char) * numCols);
    }
    reader->numRows = numRows;
    reader->numCols = numCols;
    return reader;
}

void CSVReader_free(CSVReader* reader)
{
    for (int i = 0; i < reader->numRows; i++)
    {
        free(reader->data[i]);
    }
    free(reader->data);
    free(reader);
}

void CSVReader_read(CSVReader* reader, char* csvData)
{
    char* p = csvData;
    int i = 0;
    for (int row = 0; row < reader->numRows; row++)
    {
        for (int col = 0; col < reader->numCols; col++)
        {
            reader->data[row][col] = *p++;
        }
    }
}

int main()
{
    CSVReader* reader = CSVReader_init(5, 3);
    CSVReader_read(reader, "a,b,c\nd,e,f\ng,h,i");

    for (int row = 0; row < reader->numRows; row++)
    {
        for (int col = 0; col < reader->numCols; col++)
        {
            printf("%s ", reader->data[row][col]);
        }
        printf("\n");
    }

    CSVReader_free(reader);

    return 0;
}