//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: high level of detail
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

CSVReader *createCSVReader(int rows, int cols)
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

void readCSVFile(CSVReader *reader, FILE *fp)
{
    char line[MAX_ROWS][MAX_COLS];
    int i = 0;
    while (fgets(line[i], MAX_COLS, fp) != NULL)
    {
        reader->data[i] = strdup(line[i]);
        i++;
    }
    reader->rows = i;
}

void printCSVData(CSVReader *reader)
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
    CSVReader *reader = createCSVReader(10, 2);
    FILE *fp = fopen("data.csv", "r");
    readCSVFile(reader, fp);
    printCSVData(reader);
    fclose(fp);
    free(reader);
    return 0;
}