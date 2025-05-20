//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_DATA 1024

typedef struct {
    char delimiter;
    FILE *fp;
    char filename[MAX_COLS];
    int row;
    int col;
    char **data;
} CSVReader;

CSVReader *csv_open(char *filename) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->delimiter = ',';
    strcpy(reader->filename, filename);
    reader->fp = fopen(filename, "r");
    reader->row = 0;
    reader->col = 0;
    reader->data = malloc(MAX_ROWS * sizeof(char*));
    for (int i = 0; i < MAX_ROWS; i++) {
        reader->data[i] = malloc(MAX_COLS * sizeof(char));
    }
    return reader;
}

void csv_close(CSVReader *reader) {
    fclose(reader->fp);
    for (int i = 0; i < MAX_ROWS; i++) {
        free(reader->data[i]);
    }
    free(reader->data);
    free(reader);
}

int csv_read(CSVReader *reader) {
    char line[MAX_CELL_DATA];
    char *token = NULL;
    int row = 0;
    int col = 0;
    while (fgets(line, MAX_CELL_DATA, reader->fp)!= NULL) {
        row++;
        col = 0;
        token = strtok(line, reader->delimiter);
        while (token!= NULL) {
            strcpy(reader->data[row], token);
            col++;
            token = strtok(NULL, reader->delimiter);
        }
        if (col > reader->col) {
            reader->col = col;
        }
    }
    return row;
}

char *csv_get_cell(CSVReader *reader, int row, int col) {
    if (row >= 0 && row < reader->row && col >= 0 && col < reader->col) {
        return reader->data[row][col];
    }
    return NULL;
}

int main() {
    CSVReader *reader = csv_open("test.csv");
    int rows = csv_read(reader);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < reader->col; j++) {
            printf("%s\t", csv_get_cell(reader, i, j));
        }
        printf("\n");
    }
    csv_close(reader);
    return 0;
}