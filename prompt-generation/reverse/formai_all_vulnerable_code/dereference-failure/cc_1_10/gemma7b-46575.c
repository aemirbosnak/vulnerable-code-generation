//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSVReader {
    char **buffer;
    int capacity;
    int used;
    FILE *fp;
} CSVReader;

CSVReader *csv_reader_init(FILE *fp) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->buffer = NULL;
    reader->capacity = 0;
    reader->used = 0;
    reader->fp = fp;

    return reader;
}

void csv_reader_read(CSVReader *reader) {
    char *line = NULL;
    size_t len = 0;

    getline(reader->fp, line, &len);

    if (line) {
        reader->buffer = realloc(reader->buffer, (reader->used + 1) * MAX_BUFFER_SIZE);
        reader->buffer[reader->used++] = line;
    }
}

void csv_reader_finalize(CSVReader *reader) {
    free(reader->buffer);
    fclose(reader->fp);
    free(reader);
}

int main() {
    FILE *fp = fopen("data.csv", "r");
    CSVReader *reader = csv_reader_init(fp);

    while (!feof(fp)) {
        csv_reader_read(reader);
    }

    csv_reader_finalize(reader);

    return 0;
}