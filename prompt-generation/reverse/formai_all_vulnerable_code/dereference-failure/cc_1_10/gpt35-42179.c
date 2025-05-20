//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char** rows;
    int num_rows;
    int num_cols;
} CSV;

CSV* read_csv(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    char* line = NULL;
    size_t len = 0;
    ssize_t nread;

    int row_count = 0;
    int col_count = 0;

    CSV* csv = (CSV*) malloc(sizeof(CSV));

    while ((nread = getline(&line, &len, file)) != -1) {
        char* tok = strtok(line, ",");
        int col_index = 0;

        while (tok != NULL) {
            if (row_count == 0) {
                col_count++;
            }

            if (col_index >= col_count) {
                fprintf(stderr, "Row %d has too many columns!\n", row_count);
                exit(1);
            }

            if (row_count == 0) {
                csv->rows = (char**) malloc(sizeof(char*));
            } else {
                csv->rows = (char**) realloc(csv->rows, (row_count + 1) * sizeof(char*));
            }

            char* cell = (char*) malloc((strlen(tok) + 1) * sizeof(char));
            strcpy(cell, tok);

            csv->rows[row_count] = cell;

            tok = strtok(NULL, ",");
            col_index++;
        }

        row_count++;
    }

    csv->num_rows = row_count;
    csv->num_cols = col_count;

    fclose(file);

    return csv;
}

void print_csv(CSV* csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            printf("%s", csv->rows[i * csv->num_cols + j]);
            if (j < csv->num_cols - 1) {
                printf(",");
            }
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: ./csv_reader <csv_file>");
        exit(1);
    }

    CSV* csv = read_csv(argv[1]);
    print_csv(csv);

    return 0;
}