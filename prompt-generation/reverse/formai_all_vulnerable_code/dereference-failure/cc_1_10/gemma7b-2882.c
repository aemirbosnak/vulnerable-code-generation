//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSVReader {
    FILE *fp;
    char **buffer;
    int bufferSize;
    int currentLine;
    int columnCount;
} CSVReader;

CSVReader *csvReader_init(char *filename) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->fp = fopen(filename, "r");
    reader->buffer = NULL;
    reader->bufferSize = 0;
    reader->currentLine = 0;
    reader->columnCount = 0;

    return reader;
}

void csvReader_free(CSVReader *reader) {
    fclose(reader->fp);
    free(reader->buffer);
    free(reader);
}

int csvReader_readLine(CSVReader *reader) {
    reader->currentLine++;

    // Allocate memory for the line buffer if needed
    if (reader->bufferSize < reader->currentLine) {
        reader->bufferSize = reader->currentLine * MAX_BUFFER_SIZE;
        reader->buffer = realloc(reader->buffer, reader->bufferSize);
    }

    // Read the line from the file
    reader->buffer[reader->currentLine - 1] = fgets(reader->buffer[reader->currentLine - 1], MAX_BUFFER_SIZE, reader->fp);

    // Return the number of columns in the line
    return csvReader_parseLine(reader);
}

int csvReader_parseLine(CSVReader *reader) {
    char *line = reader->buffer[reader->currentLine - 1];
    char *column = strtok(line, ",");

    // Count the number of columns in the line
    reader->columnCount = 0;
    while (column) {
        reader->columnCount++;
        column = strtok(NULL, ",");
    }

    return reader->columnCount;
}

int main() {
    CSVReader *reader = csvReader_init("data.csv");

    // Read lines from the CSV file
    while (csvReader_readLine(reader) > 0) {
        // Process the data in each line
        int numColumns = reader->columnCount;
        for (int i = 0; i < numColumns; i++) {
            printf("%s,", reader->buffer[reader->currentLine - 1][i]);
        }
        printf("\n");
    }

    csvReader_free(reader);

    return 0;
}