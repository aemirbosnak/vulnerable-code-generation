//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSVReader {
    char **data;
    int rows;
    int cols;
} CSVReader;

CSVReader* csv_reader_init(int rows, int cols) {
    CSVReader* reader = malloc(sizeof(CSVReader));
    reader->data = malloc(sizeof(char*) * rows);
    for (int i = 0; i < rows; i++) {
        reader->data[i] = malloc(sizeof(char) * cols);
    }
    reader->rows = rows;
    reader->cols = cols;
    return reader;
}

void csv_reader_read(CSVReader* reader, char* csv_data) {
    char* line = strtok(csv_data, "\n");
    int idx = 0;
    while (line) {
        char** cols = strtok(line, ",");
        for (int i = 0; cols[i]; i++) {
            reader->data[idx][i] = cols[i];
        }
        idx++;
        line = strtok(NULL, "\n");
    }
}

int main() {
    CSVReader* reader = csv_reader_init(5, 3);
    csv_reader_read(reader, "a,b,c\nd,e,f\ng,h,i");
    for (int i = 0; i < reader->rows; i++) {
        for (int j = 0; j < reader->cols; j++) {
            printf("%s ", reader->data[i][j]);
        }
        printf("\n");
    }
    free(reader->data);
    free(reader);
    return 0;
}