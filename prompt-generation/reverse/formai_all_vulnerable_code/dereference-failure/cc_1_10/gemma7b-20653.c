//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINES 1024
#define MAX_COLS 256

typedef struct CSVReader {
    char **data;
    int numLines;
    int numCols;
    FILE *file;
} CSVReader;

CSVReader *createCSVReader(char *filename) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->data = NULL;
    reader->numLines = 0;
    reader->numCols = 0;
    reader->file = fopen(filename, "r");

    return reader;
}

void destroyCSVReader(CSVReader *reader) {
    fclose(reader->file);
    free(reader->data);
    free(reader);
}

int readCSV(CSVReader *reader) {
    char line[MAX_LINES];
    int numCols = 0;
    char **data = NULL;

    while (fgets(line, MAX_LINES, reader->file) != NULL) {
        char *token = strtok(line, ",");
        while (token) {
            data = realloc(data, (reader->numLines + 1) * sizeof(char *));
            data[reader->numLines] = strdup(token);
            numCols++;
            token = strtok(NULL, ",");
        }

        reader->numLines++;
        reader->numCols = numCols;
        reader->data = data;
    }

    return 0;
}

int main() {
    CSVReader *reader = createCSVReader("data.csv");
    readCSV(reader);
    destroyCSVReader(reader);

    return 0;
}