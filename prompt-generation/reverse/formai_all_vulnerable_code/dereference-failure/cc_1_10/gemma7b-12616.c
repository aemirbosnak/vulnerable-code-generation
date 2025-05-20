//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a CSV Reader module
typedef struct CSVReader {
    FILE *fp;
    char **data;
    int numRows;
    int numCols;
} CSVReader;

CSVReader *createCSVReader(char *filename) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->fp = fopen(filename, "r");
    reader->data = NULL;
    reader->numRows = 0;
    reader->numCols = 0;

    return reader;
}

void destroyCSVReader(CSVReader *reader) {
    fclose(reader->fp);
    free(reader->data);
    free(reader);
}

void readCSVData(CSVReader *reader) {
    char line[1024];
    char **rowData = NULL;
    int i = 0;

    while (fgets(line, 1024, reader->fp) != NULL) {
        rowData = realloc(rowData, (reader->numRows + 1) * sizeof(char *));
        rowData[reader->numRows] = strdup(line);
        reader->numRows++;
    }

    reader->data = rowData;
}

int main() {
    CSVReader *reader = createCSVReader("data.csv");
    readCSVData(reader);
    printf("%s", reader->data[0]);
    destroyCSVReader(reader);

    return 0;
}