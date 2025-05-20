//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: thoughtful
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

CSVReader *csvReader_init(const char *filename) {
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

char **csvReader_readNextLine(CSVReader *reader) {
    char **line = NULL;

    if (reader->currentLine >= reader->bufferSize) {
        reader->bufferSize *= 2;
        reader->buffer = realloc(reader->buffer, reader->bufferSize * sizeof(char *));
    }

    line = reader->buffer[reader->currentLine++] = malloc(MAX_BUFFER_SIZE);
    fgets(line, MAX_BUFFER_SIZE, reader->fp);

    return line;
}

void csvReader_readNextColumn(CSVReader *reader) {
    reader->currentColumn++;
}

char *csvReader_getValue(CSVReader *reader) {
    return reader->buffer[reader->currentLine - 1][reader->currentColumn - 1];
}

int main() {
    CSVReader *reader = csvReader_init("data.csv");

    char **line = csvReader_readNextLine(reader);
    printf("%s\n", line[0]);

    csvReader_readNextColumn(reader);
    printf("%s\n", csvReader_getValue(reader));

    csvReader_free(reader);

    return 0;
}