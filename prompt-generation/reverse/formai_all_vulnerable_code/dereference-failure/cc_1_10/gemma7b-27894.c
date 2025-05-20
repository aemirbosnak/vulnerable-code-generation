//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_COLS 20

typedef struct CSVReader {
    char ***data;
    int numLines;
    int numCols;
} CSVReader;

CSVReader *createCSVReader(int numLines, int numCols) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->data = malloc(sizeof(char ***) * numLines);
    for (int i = 0; i < numLines; i++) {
        reader->data[i] = malloc(sizeof(char **) * numCols);
        for (int j = 0; j < numCols; j++) {
            reader->data[i][j] = malloc(sizeof(char) * MAX_LINES);
        }
    }
    reader->numLines = numLines;
    reader->numCols = numCols;
    return reader;
}

void freeCSVReader(CSVReader *reader) {
    for (int i = 0; i < reader->numLines; i++) {
        for (int j = 0; j < reader->numCols; j++) {
            free(reader->data[i][j]);
        }
        free(reader->data[i]);
    }
    free(reader->data);
    free(reader);
}

int main() {
    CSVReader *reader = createCSVReader(5, 3);
    reader->data[0][0] = "John Doe";
    reader->data[0][1] = "New York";
    reader->data[0][2] = "123 Main St";

    reader->data[1][0] = "Jane Doe";
    reader->data[1][1] = "Los Angeles";
    reader->data[1][2] = "456 Oak Ave";

    for (int i = 0; i < reader->numLines; i++) {
        for (int j = 0; j < reader->numCols; j++) {
            printf("%s, %s, %s\n", reader->data[i][j]);
        }
    }

    freeCSVReader(reader);
    return 0;
}