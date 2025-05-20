//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSVReader
{
    FILE *fp;
    char **buffer;
    int size;
    int currentRow;
    int currentCol;
} CSVReader;

CSVReader *createCSVReader(char *filename)
{
    CSVReader *reader = malloc(sizeof(CSVReader));

    reader->fp = fopen(filename, "r");
    if (reader->fp == NULL)
    {
        return NULL;
    }

    reader->buffer = NULL;
    reader->size = 0;
    reader->currentRow = 0;
    reader->currentCol = 0;

    return reader;
}

void destroyCSVReader(CSVReader *reader)
{
    fclose(reader->fp);
    free(reader->buffer);
    free(reader);
}

char **readCSVData(CSVReader *reader)
{
    char **data = NULL;

    // Allocate memory for the data array
    reader->buffer = realloc(reader->buffer, (reader->size + 1) * MAX_BUFFER_SIZE);

    // Read the next line from the CSV file
    char line[MAX_BUFFER_SIZE];
    fgets(line, MAX_BUFFER_SIZE, reader->fp);

    // Split the line into columns
    char *column = strtok(line, ",");

    // Create an array of pointers to the columns
    data = malloc((reader->size + 1) * MAX_BUFFER_SIZE);

    // Fill the data array with the columns
    int i = 0;
    while (column)
    {
        data[i++] = strdup(column);
        column = strtok(NULL, ",");
    }

    // Increment the current row and column indices
    reader->currentRow++;
    reader->currentCol = 0;

    return data;
}

int main()
{
    CSVReader *reader = createCSVReader("example.csv");

    char **data = readCSVData(reader);

    // Print the data
    for (int i = 0; data[i] != NULL; i++)
    {
        printf("%s,", data[i]);
    }

    printf("\n");

    destroyCSVReader(reader);

    return 0;
}