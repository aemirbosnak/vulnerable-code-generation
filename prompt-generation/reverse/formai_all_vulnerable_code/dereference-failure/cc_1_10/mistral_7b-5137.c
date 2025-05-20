//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct CSV_ROW {
    size_t num_cols;
    char **cols;
} CSV_ROW;

bool is_delimiter(char c, char delimiter) {
    return (c == delimiter) ? true : false;
}

CSV_ROW *read_line(FILE *file, char delimiter) {
    size_t num_cols = 0;
    size_t capacity = 1;
    size_t col_capacity = 32;
    size_t len = 0;
    char *line = NULL;
    size_t pos = 0;
    CSV_ROW *row = malloc(sizeof(CSV_ROW));

    while (getline(&line, &len, file) > 0) {
        if (pos > 0 && is_delimiter(line[pos], delimiter)) {
            num_cols++;
            if (capacity <= num_cols) {
                capacity *= 2;
                row->cols = realloc(row->cols, capacity * sizeof(char *));
            }
            row->cols[num_cols - 1] = malloc(pos + 1);
            strncpy(row->cols[num_cols - 1], line, pos + 1);
            row->cols[num_cols - 1][pos] = '\0';
            pos = 0;
        } else {
            if (capacity <= num_cols + 1) {
                capacity *= 2;
                row->cols = realloc(row->cols, capacity * sizeof(char *));
            }
            row->cols[num_cols] = malloc(len + 1);
            strcpy(row->cols[num_cols], line);
        }
    }

    if (num_cols > 0) {
        row->num_cols = num_cols + 1;
    } else {
        free(row);
        return NULL;
    }

    return row;
}

void print_csv_row(CSV_ROW *row) {
    for (size_t i = 0; i < row->num_cols; i++) {
        printf("%s", row->cols[i]);
        if (i < row->num_cols - 1) {
            printf(",");
        }
    }
    printf("\n");
}

int main() {
    FILE *file = fopen("example.csv", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    CSV_ROW *row = NULL;

    while (row = read_line(file, ',')) {
        print_csv_row(row);
        for (size_t i = 0; i < row->num_cols; i++) {
            free(row->cols[i]);
        }
        free(row->cols);
        free(row);
    }

    fclose(file);

    return EXIT_SUCCESS;
}