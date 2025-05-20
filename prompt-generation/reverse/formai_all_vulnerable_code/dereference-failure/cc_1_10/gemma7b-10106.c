//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: careful
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

CSVReader *CSVReader_init(int rows, int cols) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->data = malloc((rows + 1) * sizeof(char *) + 1);
    for (int r = 0; r <= rows; r++) {
        reader->data[r] = malloc((cols + 1) * sizeof(char) + 1);
    }
    reader->rows = rows;
    reader->cols = cols;
    return reader;
}

void CSVReader_free(CSVReader *reader) {
    for (int r = 0; r < reader->rows; r++) {
        free(reader->data[r]);
    }
    free(reader->data);
    free(reader);
}

void CSVReader_read(CSVReader *reader, char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return;
    }

    char line[MAX_ROWS];
    int line_num = 0;
    while (fgets(line, MAX_ROWS, file) != NULL) {
        line_num++;
        char **fields = malloc(sizeof(char *) * MAX_COLS);
        int field_num = 0;
        char *field = strtok(line, ",");
        while (field) {
            fields[field_num++] = strdup(field);
            field = strtok(NULL, ",");
        }
        for (int c = 0; c < reader->cols; c++) {
            reader->data[line_num - 1][c] = fields[c] ? fields[c] : "";
        }
        free(fields);
    }

    fclose(file);
}

int main() {
    CSVReader *reader = CSVReader_init(10, 2);
    CSVReader_read(reader, "data.csv");

    for (int r = 0; r < reader->rows; r++) {
        for (int c = 0; c < reader->cols; c++) {
            printf("%s,", reader->data[r][c]);
        }
        printf("\n");
    }

    CSVReader_free(reader);

    return 0;
}