//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSVReader {
    FILE *fp;
    char **buffer;
    int bufferSize;
    int currentLine;
    int currentColumn;
} CSVReader;

CSVReader *csvReader_init(char *filename) {
    CSVReader *reader = malloc(sizeof(CSVReader));

    reader->fp = fopen(filename, "r");
    reader->buffer = NULL;
    reader->bufferSize = 0;
    reader->currentLine = 0;
    reader->currentColumn = 0;

    return reader;
}

void csvReader_free(CSVReader *reader) {
    fclose(reader->fp);
    free(reader->buffer);
    free(reader);
}

int csvReader_getNextLine(CSVReader *reader) {
    char *line = NULL;
    int lineSize = 0;

    if (reader->currentLine == reader->bufferSize - 1) {
        reader->bufferSize *= 2;
        reader->buffer = realloc(reader->buffer, reader->bufferSize * sizeof(char *));
    }

    line = fgets(reader->buffer[reader->currentLine], MAX_BUFFER_SIZE, reader->fp);

    if (line) {
        reader->currentLine++;
    }

    return lineSize;
}

int csvReader_getColumn(CSVReader *reader, int column) {
    char **columns = reader->buffer[reader->currentLine - 1];
    return columns[column];
}

int main() {
    CSVReader *reader = csvReader_init("data.csv");

    while (csvReader_getNextLine(reader) > 0) {
        for (int i = 0; i < csvReader_getColumn(reader, 2); i++) {
            printf("%s ", csvReader_getColumn(reader, i));
        }

        printf("\n");
    }

    csvReader_free(reader);

    return 0;
}