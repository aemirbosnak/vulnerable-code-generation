//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSVReader {
    FILE *fp;
    char **buffer;
    int bufferSize;
    int currentLine;
    int columnCount;
} CSVReader;

CSVReader *createCSVReader(const char *filename) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->fp = fopen(filename, "r");
    reader->buffer = NULL;
    reader->bufferSize = 0;
    reader->currentLine = 0;
    reader->columnCount = 0;
    return reader;
}

void destroyCSVReader(CSVReader *reader) {
    fclose(reader->fp);
    free(reader->buffer);
    free(reader);
}

int readCSVLine(CSVReader *reader, char **line) {
    if (reader->currentLine >= reader->bufferSize) {
        reader->bufferSize *= 2;
        reader->buffer = realloc(reader->buffer, reader->bufferSize * sizeof(char *));
    }
    line = reader->buffer[reader->currentLine++] = malloc(MAX_BUFFER_SIZE);
    int columns = fgets(line, MAX_BUFFER_SIZE, reader->fp);
    reader->columnCount = columns;
    return columns;
}

int main() {
    CSVReader *reader = createCSVReader("data.csv");
    char **line = NULL;
    int columns = readCSVLine(reader, &line);
    printf("Number of columns: %d\n", columns);
    printf("Data: %s\n", line);
    destroyCSVReader(reader);
    return 0;
}