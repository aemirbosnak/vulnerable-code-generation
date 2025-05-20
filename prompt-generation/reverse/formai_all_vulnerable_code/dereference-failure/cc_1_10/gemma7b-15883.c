//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSVReader {
    char **buffer;
    int size;
    int pos;
    FILE *file;
} CSVReader;

CSVReader *createCSVReader(const char *filename) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->buffer = NULL;
    reader->size = 0;
    reader->pos = 0;
    reader->file = fopen(filename, "r");

    if (reader->file == NULL) {
        perror("Error opening file");
        free(reader);
        return NULL;
    }

    return reader;
}

void destroyCSVReader(CSVReader *reader) {
    fclose(reader->file);
    free(reader->buffer);
    free(reader);
}

int readCSVLine(CSVReader *reader, char **line) {
    int size = reader->size;
    if (reader->pos >= size) {
        size = reader->size * 2;
        reader->buffer = realloc(reader->buffer, size * sizeof(char *));
        reader->size = size;
    }

    line = reader->buffer[reader->pos++] = malloc(MAX_BUFFER_SIZE);

    return fread(line, MAX_BUFFER_SIZE, 1, reader->file) == 1;
}

int main() {
    CSVReader *reader = createCSVReader("data.csv");

    char **line = NULL;
    while (readCSVLine(reader, &line)) {
        // Process the line
        printf("%s\n", line);
        free(line);
    }

    destroyCSVReader(reader);

    return 0;
}