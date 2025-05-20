//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSVReader {
    FILE *file;
    char **buffer;
    int bufferSize;
    int currentLine;
    int columns;
} CSVReader;

CSVReader *createCSVReader(char *fileName) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->file = fopen(fileName, "r");
    reader->buffer = NULL;
    reader->bufferSize = 0;
    reader->currentLine = 0;
    reader->columns = 0;

    return reader;
}

void destroyCSVReader(CSVReader *reader) {
    fclose(reader->file);
    free(reader->buffer);
    free(reader);
}

int readCSVLine(CSVReader *reader) {
    reader->currentLine++;

    if (reader->bufferSize == 0) {
        reader->bufferSize = MAX_BUFFER_SIZE;
        reader->buffer = malloc(reader->bufferSize * sizeof(char *));
    }

    char *line = fgets(reader->buffer[reader->currentLine - 1], reader->bufferSize, reader->file);

    if (line) {
        reader->columns = countColumns(line);
        return 1;
    } else {
        return 0;
    }
}

int countColumns(char *line) {
    int columns = 0;

    char *token = strtok(line, ",");

    while (token) {
        columns++;
        token = strtok(NULL, ",");
    }

    return columns;
}

int main() {
    CSVReader *reader = createCSVReader("example.csv");

    while (readCSVLine(reader)) {
        for (int i = 0; i < reader->columns; i++) {
            printf("%s,", reader->buffer[reader->currentLine - 1][i]);
        }
        printf("\n");
    }

    destroyCSVReader(reader);

    return 0;
}