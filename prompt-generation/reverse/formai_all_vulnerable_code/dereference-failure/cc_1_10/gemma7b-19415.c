//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1024
#define MAX_COLS 256

typedef struct CSVReader {
    char **data;
    int lines;
    int cols;
} CSVReader;

CSVReader *createCSVReader(int lines, int cols) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->data = malloc(sizeof(char *) * lines);
    for (int i = 0; i < lines; i++) {
        reader->data[i] = malloc(sizeof(char) * cols);
    }
    reader->lines = lines;
    reader->cols = cols;
    return reader;
}

void readCSV(CSVReader *reader, char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return;
    }

    int line = 0;
    char line_buffer[MAX_LINES];
    while (fgets(line_buffer, MAX_LINES, file) != NULL) {
        reader->data[line] = strdup(line_buffer);
        line++;
    }

    fclose(file);
}

void printCSV(CSVReader *reader) {
    for (int i = 0; i < reader->lines; i++) {
        printf("%s\n", reader->data[i]);
    }
}

int main() {
    CSVReader *reader = createCSVReader(5, 3);
    readCSV(reader, "data.csv");
    printCSV(reader);

    return 0;
}