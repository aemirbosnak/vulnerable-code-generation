//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSVReader {
    FILE* file;
    char** buffer;
    int bufferSize;
    int currentLine;
} CSVReader;

CSVReader* csvReader_init(const char* filename) {
    CSVReader* reader = malloc(sizeof(CSVReader));

    reader->file = fopen(filename, "r");
    reader->buffer = NULL;
    reader->bufferSize = MAX_BUFFER_SIZE;
    reader->currentLine = 0;

    return reader;
}

void csvReader_free(CSVReader* reader) {
    fclose(reader->file);
    free(reader->buffer);
    free(reader);
}

int csvReader_getNextLine(CSVReader* reader) {
    if (reader->currentLine >= reader->bufferSize - 1) {
        reader->bufferSize *= 2;
        reader->buffer = realloc(reader->buffer, reader->bufferSize * sizeof(char*));
    }

    char* line = fgets(reader->buffer[reader->currentLine], MAX_BUFFER_SIZE, reader->file);

    if (line) {
        reader->currentLine++;
        return 0;
    } else {
        return -1;
    }
}

int main() {
    CSVReader* reader = csvReader_init("data.csv");

    while (csvReader_getNextLine(reader) == 0) {
        // Process the line
        printf("Line: %s\n", reader->buffer[reader->currentLine - 1]);
    }

    csvReader_free(reader);

    return 0;
}