//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSVReader {
    char **buffer;
    int size;
    int capacity;
    FILE *fp;
} CSVReader;

CSVReader *createCSVReader(FILE *fp) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->buffer = NULL;
    reader->size = 0;
    reader->capacity = MAX_BUFFER_SIZE;
    reader->fp = fp;
    return reader;
}

void readCSVLine(CSVReader *reader) {
    char *line = NULL;
    int len = 0;
    reader->buffer = realloc(reader->buffer, (reader->size + 1) * reader->capacity);
    line = reader->buffer[reader->size++] = malloc(MAX_BUFFER_SIZE);

    fscanf(reader->fp, "%[^\n]%*c", line);
    printf("%s\n", line);
}

void destroyCSVReader(CSVReader *reader) {
    free(reader->buffer);
    fclose(reader->fp);
    free(reader);
}

int main() {
    FILE *fp = fopen("test.csv", "r");
    CSVReader *reader = createCSVReader(fp);

    readCSVLine(reader);
    readCSVLine(reader);
    readCSVLine(reader);

    destroyCSVReader(reader);
    fclose(fp);

    return 0;
}