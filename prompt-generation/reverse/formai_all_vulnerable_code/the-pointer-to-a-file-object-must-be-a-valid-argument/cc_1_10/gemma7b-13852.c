//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSVReader {
    FILE* file;
    char** buffer;
    int bufferSize;
    int currentLine;
} CSVReader;

CSVReader* csvReader_init(char* filename) {
    CSVReader* reader = malloc(sizeof(CSVReader));
    reader->file = fopen(filename, "r");
    reader->buffer = NULL;
    reader->bufferSize = 0;
    reader->currentLine = 0;

    return reader;
}

void csvReader_free(CSVReader* reader) {
    fclose(reader->file);
    free(reader->buffer);
    free(reader);
}

int csvReader_getNextLine(CSVReader* reader) {
    reader->currentLine++;

    if (reader->bufferSize == reader->currentLine) {
        reader->bufferSize *= 2;
        reader->buffer = realloc(reader->buffer, reader->bufferSize * sizeof(char*));
    }

    reader->buffer[reader->currentLine - 1] = fgets(reader->buffer[reader->currentLine - 1], MAX_BUFFER_SIZE, reader->file);

    return reader->currentLine;
}

char** csvReader_getRow(CSVReader* reader) {
    return reader->buffer[reader->currentLine - 1];
}

int main() {
    CSVReader* reader = csvReader_init("data.csv");

    int lineNumber = csvReader_getNextLine(reader);

    while (lineNumber) {
        char** row = csvReader_getRow(reader);

        for (int i = 0; row[i] != NULL; i++) {
            printf("%s,", row[i]);
        }

        printf("\n");

        lineNumber = csvReader_getNextLine(reader);
    }

    csvReader_free(reader);

    return 0;
}