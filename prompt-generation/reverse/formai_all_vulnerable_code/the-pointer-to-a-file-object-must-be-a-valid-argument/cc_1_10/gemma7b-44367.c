//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSVReader {
    FILE *fp;
    char **buffer;
    int capacity;
    int used;
    int lineNumber;
} CSVReader;

CSVReader *csvReader_init(char *filename) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->fp = fopen(filename, "r");
    reader->buffer = NULL;
    reader->capacity = 0;
    reader->used = 0;
    reader->lineNumber = 0;

    return reader;
}

void csvReader_readCSV(CSVReader *reader) {
    char line[MAX_BUFFER_SIZE];
    int len = 0;

    fgets(line, MAX_BUFFER_SIZE, reader->fp);
    reader->buffer = realloc(reader->buffer, (reader->used + 1) * MAX_BUFFER_SIZE);
    reader->buffer[reader->used++] = strdup(line);
    reader->lineNumber++;
}

void csvReader_free(CSVReader *reader) {
    fclose(reader->fp);
    free(reader->buffer);
    free(reader);
}

int main() {
    CSVReader *reader = csvReader_init("data.csv");

    while (!feof(reader->fp)) {
        csvReader_readCSV(reader);
    }

    csvReader_free(reader);

    return 0;
}