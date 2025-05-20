//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    char **data;
    int rows;
    int cols;
} CSVReader;

CSVReader *csv_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->data = NULL;
    reader->rows = 0;
    reader->cols = 0;

    while ((read = getline(&line, &len, fp))!= -1) {
        char *token = strtok(line, ",");
        int cols = 0;

        while (token!= NULL) {
            cols++;
            token = strtok(NULL, ",");
        }

        if (cols > reader->cols) {
            reader->cols = cols;
        }

        if (reader->data == NULL) {
            reader->data = malloc(sizeof(char *) * cols);
        } else {
            reader->data = realloc(reader->data, sizeof(char *) * cols);
        }

        char **row = reader->data + reader->rows * cols;
        int i = 0;
        token = strtok(line, ",");

        while (token!= NULL) {
            row[i] = strdup(token);
            i++;
            token = strtok(NULL, ",");
        }

        reader->rows++;
    }

    fclose(fp);

    return reader;
}

void csv_print(CSVReader *reader) {
    for (int i = 0; i < reader->rows; i++) {
        for (int j = 0; j < reader->cols; j++) {
            printf("%s ", reader->data[i * reader->cols + j]);
        }
        printf("\n");
    }
}

void csv_close(CSVReader *reader) {
    for (int i = 0; i < reader->rows; i++) {
        for (int j = 0; j < reader->cols; j++) {
            free(reader->data[i * reader->cols + j]);
        }
    }

    free(reader->data);
    free(reader);
}

int main() {
    CSVReader *reader = csv_open("example.csv");
    csv_print(reader);
    csv_close(reader);

    return 0;
}