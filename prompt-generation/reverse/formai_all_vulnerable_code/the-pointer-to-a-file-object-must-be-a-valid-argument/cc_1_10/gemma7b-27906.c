//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1024

typedef struct CSVReader {
    FILE *fp;
    char **data;
    int lines;
    int cols;
} CSVReader;

CSVReader *csv_reader_init(const char *filename) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->fp = fopen(filename, "r");
    reader->data = NULL;
    reader->lines = 0;
    reader->cols = 0;

    return reader;
}

void csv_reader_free(CSVReader *reader) {
    fclose(reader->fp);
    free(reader->data);
    free(reader);
}

void csv_reader_read(CSVReader *reader) {
    char line[MAX_LINES];
    char **data = NULL;
    int i = 0;

    while (fgets(line, MAX_LINES, reader->fp) != NULL) {
        reader->lines++;

        data = realloc(data, reader->lines * sizeof(char *));
        data[reader->lines - 1] = strdup(line);

        for (i = 0; i < reader->cols; i++) {
            printf("%s,", data[reader->lines - 1][i]);
        }

        printf("\n");
    }
}

int main() {
    CSVReader *reader = csv_reader_init("data.csv");
    csv_reader_read(reader);
    csv_reader_free(reader);

    return 0;
}