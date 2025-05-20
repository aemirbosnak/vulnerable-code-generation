//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSVReader {
    FILE *file;
    char **buffer;
    int bufferSize;
    int currentLine;
    char **currentLineBuffer;
    int currentLineBufferSize;
} CSVReader;

CSVReader *createCSVReader(char *filePath) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->file = fopen(filePath, "r");
    reader->buffer = NULL;
    reader->bufferSize = 0;
    reader->currentLine = 0;
    reader->currentLineBuffer = NULL;
    reader->currentLineBufferSize = 0;

    return reader;
}

void freeCSVReader(CSVReader *reader) {
    fclose(reader->file);
    free(reader->buffer);
    free(reader->currentLineBuffer);
    free(reader);
}

int readCSVLine(CSVReader *reader) {
    reader->currentLine++;

    if (reader->currentLineBuffer) {
        free(reader->currentLineBuffer);
    }

    reader->currentLineBufferSize = MAX_BUFFER_SIZE;
    reader->currentLineBuffer = malloc(reader->currentLineBufferSize);

    int readBytes = fread(reader->currentLineBuffer, reader->currentLineBufferSize, 1, reader->file);

    if (readBytes != 1) {
        return -1;
    }

    return 0;
}

int main() {
    CSVReader *reader = createCSVReader("data.csv");

    if (readCSVLine(reader) == -1) {
        printf("Error reading CSV line.\n");
    } else {
        printf("Line %d: %s\n", reader->currentLine, reader->currentLineBuffer);
    }

    freeCSVReader(reader);

    return 0;
}