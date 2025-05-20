//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 100

typedef struct {
    char** rows;
    int row_count;
    int col_count;
} CSVData;

CSVData read_csv(const char* filename) {
    CSVData csv = {0};

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file: %s\n", filename);
        return csv;
    }

    char line[BUFSIZ];
    char* values[MAX_COLS];
    int line_count = 0;

    while (fgets(line, BUFSIZ, file) != NULL) {
        if (line_count == MAX_ROWS) { // limit number of rows
            break;
        }

        int col_count = 0;

        char* value = strtok(line, ",");
        while (value != NULL && col_count < MAX_COLS) { // limit number of columns
            values[col_count] = strdup(value); // create copy of value
            col_count++;
            value = strtok(NULL, ",");
        }

        if (col_count > csv.col_count) { // update column count
            csv.col_count = col_count;
        }

        csv.rows = realloc(csv.rows, (line_count + 1) * sizeof(char*)); // allocate memory for new row
        csv.rows[line_count] = malloc(csv.col_count * sizeof(char*)); // allocate memory for row values
        
        for (int i = 0; i < col_count; i++) {
            csv.rows[line_count][i] = values[i];
        }

        line_count++;
    }

    csv.row_count = line_count;

    fclose(file);

    return csv;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* filename = argv[1];

    CSVData csv = read_csv(filename);

    printf("Rows: %d\n", csv.row_count);
    printf("Cols: %d\n", csv.col_count);

    for (int i = 0; i < csv.row_count; i++) {
        printf("Row %d: ", i + 1);

        for (int j = 0; j < csv.col_count; j++) {
            printf("%s ", csv.rows[i][j]);
            free(csv.rows[i][j]); // free individual value memory
        }

        free(csv.rows[i]); // free row memory
        printf("\n");
    }

    free(csv.rows); // free rows memory

    return EXIT_SUCCESS;
}