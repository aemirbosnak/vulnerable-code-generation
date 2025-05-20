//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100

typedef struct CSVReader
{
    char **lines;
    int numLines;
    int curLine;
} CSVReader;

CSVReader *csvReader_init(int lines)
{
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->lines = malloc(lines * sizeof(char *));
    reader->numLines = lines;
    reader->curLine = 0;
    return reader;
}

void csvReader_addLines(CSVReader *reader, char **lines)
{
    reader->lines[reader->curLine++] = lines;
}

char **csvReader_getLine(CSVReader *reader)
{
    return reader->lines[reader->curLine - 1];
}

int main()
{
    CSVReader *reader = csvReader_init(MAX_LINES);
    char **lines = malloc(MAX_LINES * sizeof(char *));

    lines[0] = "John Doe,123 Main St,New York,NY 10001";
    lines[1] = "Jane Doe,456 Oak Ave,Los Angeles,CA 90012";
    lines[2] = "Bill Smith,789 Oak Ave,Chicago,IL 60653";

    csvReader_addLines(reader, lines);

    char **line = csvReader_getLine(reader);

    printf("Name: %s\n", line[0]);
    printf("Address: %s\n", line[1]);
    printf("City: %s\n", line[2]);
    printf("State: %s\n", line[3]);
    printf("Zip: %s\n", line[4]);

    free(lines);
    free(reader);

    return 0;
}