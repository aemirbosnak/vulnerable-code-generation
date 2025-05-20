//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000

typedef struct CSVReader {
    char **lines;
    int numLines;
    int currentLine;
} CSVReader;

CSVReader *csvReader_init(int numLines) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->lines = malloc(sizeof(char *) * numLines);
    reader->numLines = numLines;
    reader->currentLine = 0;
    return reader;
}

void csvReader_appendLine(CSVReader *reader, char *line) {
    reader->lines[reader->currentLine++] = strdup(line);
}

char **csvReader_getLines(CSVReader *reader) {
    return reader->lines;
}

void csvReader_free(CSVReader *reader) {
    free(reader->lines);
    free(reader);
}

int main() {
    CSVReader *reader = csvReader_init(MAX_LINES);

    // Append lines to the CSV reader
    csvReader_appendLine(reader, "John Doe,123 Main St,New York,NY 10001");
    csvReader_appendLine(reader, "Jane Doe,456 Oak Ave,Los Angeles,CA 90210");
    csvReader_appendLine(reader, "Bill Smith,789 Park Ave,Chicago,IL 60601");

    // Get the lines from the CSV reader
    char **lines = csvReader_getLines(reader);

    // Print the lines
    for (int i = 0; lines[i] != NULL; i++) {
        printf("%s\n", lines[i]);
    }

    // Free the CSV reader
    csvReader_free(reader);

    return 0;
}