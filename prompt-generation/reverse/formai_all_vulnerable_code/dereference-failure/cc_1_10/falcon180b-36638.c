//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 1000
#define MAX_COL 1000
#define MAX_LINE 10000

typedef struct {
    char **data;
    int row;
    int col;
} CSVReader;

CSVReader *csv_reader_create(FILE *fp) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->data = NULL;
    reader->row = 0;
    reader->col = 0;

    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, fp)!= NULL) {
        char *token = strtok(line, ",");
        int count = 0;
        while (token!= NULL) {
            count++;
            token = strtok(NULL, ",");
        }
        if (count > reader->col) {
            reader->col = count;
        }
    }

    rewind(fp);
    reader->data = malloc(sizeof(char *) * reader->row);
    for (int i = 0; i < reader->row; i++) {
        reader->data[i] = malloc(sizeof(char) * reader->col);
    }

    return reader;
}

void csv_reader_destroy(CSVReader *reader) {
    for (int i = 0; i < reader->row; i++) {
        free(reader->data[i]);
    }
    free(reader->data);
    free(reader);
}

int csv_reader_get_row(CSVReader *reader) {
    return reader->row;
}

int csv_reader_get_col(CSVReader *reader) {
    return reader->col;
}

char *csv_reader_get_value(CSVReader *reader, int row, int col) {
    if (row >= reader->row || col >= reader->col) {
        return NULL;
    }

    return reader->data[row][col];
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    CSVReader *reader = csv_reader_create(fp);

    int row = csv_reader_get_row(reader);
    int col = csv_reader_get_col(reader);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            char *value = csv_reader_get_value(reader, i, j);
            printf("%s ", value);
        }
        printf("\n");
    }

    csv_reader_destroy(reader);
    fclose(fp);

    return 0;
}