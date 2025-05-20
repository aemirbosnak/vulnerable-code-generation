//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 1000

typedef struct {
    char **rows;
    int num_rows;
    int num_cols;
} CSVReader;

CSVReader *csv_reader_create(FILE *file) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    if (reader == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for CSV reader.\n");
        exit(1);
    }

    reader->rows = malloc(MAX_ROWS * sizeof(char *));
    if (reader->rows == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for CSV rows.\n");
        exit(1);
    }

    reader->num_rows = 0;
    reader->num_cols = 0;

    return reader;
}

void csv_reader_destroy(CSVReader *reader) {
    for (int i = 0; i < reader->num_rows; i++) {
        free(reader->rows[i]);
    }
    free(reader->rows);
    free(reader);
}

int csv_reader_read(CSVReader *reader, FILE *file) {
    char line[MAX_CELL_SIZE];
    char *token;
    int num_cols = 0;

    while (fgets(line, MAX_CELL_SIZE, file)!= NULL) {
        if (reader->num_rows >= MAX_ROWS) {
            fprintf(stderr, "Error: Maximum number of rows exceeded.\n");
            exit(1);
        }

        token = strtok(line, ",");
        while (token!= NULL) {
            if (num_cols >= MAX_COLS) {
                fprintf(stderr, "Error: Maximum number of columns exceeded.\n");
                exit(1);
            }

            reader->rows[reader->num_rows] = realloc(reader->rows[reader->num_rows], (num_cols + 1) * sizeof(char *));
            if (reader->rows[reader->num_rows] == NULL) {
                fprintf(stderr, "Error: Failed to reallocate memory for CSV rows.\n");
                exit(1);
            }

            reader->rows[reader->num_rows][num_cols] = malloc((strlen(token) + 1) * sizeof(char));
            if (reader->rows[reader->num_rows][num_cols] == NULL) {
                fprintf(stderr, "Error: Failed to allocate memory for CSV cell.\n");
                exit(1);
            }

            strcpy(reader->rows[reader->num_rows][num_cols], token);
            num_cols++;

            token = strtok(NULL, ",");
        }

        reader->num_rows++;
        num_cols = 0;
    }

    if (feof(file)) {
        reader->num_cols = num_cols;
    } else {
        fprintf(stderr, "Error: Failed to read CSV file.\n");
        exit(1);
    }

    return 0;
}

void csv_reader_print(CSVReader *reader) {
    for (int i = 0; i < reader->num_rows; i++) {
        for (int j = 0; j < reader->num_cols; j++) {
            printf("%s ", reader->rows[i][j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *file = fopen("example.csv", "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Failed to open CSV file.\n");
        exit(1);
    }

    CSVReader *reader = csv_reader_create(file);
    csv_reader_read(reader, file);
    fclose(file);

    csv_reader_print(reader);

    csv_reader_destroy(reader);

    return 0;
}