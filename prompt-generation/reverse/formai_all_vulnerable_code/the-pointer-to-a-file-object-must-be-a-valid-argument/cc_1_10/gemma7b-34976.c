//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSVReader {
    FILE *fp;
    char **buffer;
    int bufferSize;
    int currentLine;
    int **data;
    int dataSize;
} CSVReader;

CSVReader *csvReader_init(char *filename) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->fp = fopen(filename, "r");
    reader->buffer = NULL;
    reader->bufferSize = 0;
    reader->currentLine = 0;
    reader->data = NULL;
    reader->dataSize = 0;

    return reader;
}

void csvReader_free(CSVReader *reader) {
    fclose(reader->fp);
    free(reader->buffer);
    free(reader->data);
    free(reader);
}

int csvReader_readNextLine(CSVReader *reader) {
    reader->currentLine++;

    if (reader->bufferSize == 0) {
        reader->buffer = malloc(MAX_BUFFER_SIZE);
        reader->bufferSize = MAX_BUFFER_SIZE;
    }

    char *line = fgets(reader->buffer, reader->bufferSize, reader->fp);

    if (line == NULL) {
        return 0;
    }

    return 1;
}

int csvReader_parseLine(CSVReader *reader) {
    char **data = NULL;
    int dataSize = 0;

    // Split the line into individual cells
    char *cell = strtok(reader->buffer, ",");
    while (cell) {
        data = realloc(data, (dataSize + 1) * sizeof(char *));
        data[dataSize++] = cell;
        cell = strtok(NULL, ",");
    }

    reader->data = data;
    reader->dataSize = dataSize;

    return 1;
}

int main() {
    CSVReader *reader = csvReader_init("data.csv");

    while (csvReader_readNextLine(reader) > 0) {
        csvReader_parseLine(reader);

        // Process the data
        for (int i = 0; i < reader->dataSize; i++) {
            printf("%s,", reader->data[i]);
        }

        printf("\n");
    }

    csvReader_free(reader);

    return 0;
}