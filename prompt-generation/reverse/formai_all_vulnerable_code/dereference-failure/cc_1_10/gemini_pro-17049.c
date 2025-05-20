//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int num_cols;
    char **cols;
} csv_t;

csv_t *csv_create(int num_cols) {
    csv_t *csv = malloc(sizeof(csv_t));
    csv->num_cols = num_cols;
    csv->cols = malloc(sizeof(char *) * num_cols);
    for (int i = 0; i < num_cols; i++) {
        csv->cols[i] = NULL;
    }
    return csv;
}

void csv_destroy(csv_t *csv) {
    for (int i = 0; i < csv->num_cols; i++) {
        free(csv->cols[i]);
    }
    free(csv->cols);
    free(csv);
}

int csv_add_col(csv_t *csv, char *col) {
    if (csv->num_cols == 0) {
        csv->cols = malloc(sizeof(char *));
    } else {
        csv->cols = realloc(csv->cols, sizeof(char *) * (csv->num_cols + 1));
    }
    csv->cols[csv->num_cols++] = col;
    return csv->num_cols - 1;
}

int csv_add_row(csv_t *csv, char **row) {
    for (int i = 0; i < csv->num_cols; i++) {
        csv_add_col(csv, row[i]);
    }
    return csv->num_cols;
}

int csv_get_num_cols(csv_t *csv) {
    return csv->num_cols;
}

int csv_get_num_rows(csv_t *csv) {
    return csv->num_cols ? csv->num_cols - 1 : 0;
}

char *csv_get_col(csv_t *csv, int col) {
    return csv->cols[col];
}

char *csv_get_row(csv_t *csv, int row) {
    return csv->cols[row + 1];
}

int csv_print(csv_t *csv) {
    for (int i = 0; i < csv->num_cols; i++) {
        printf("%s\t", csv->cols[i]);
    }
    printf("\n");
    return 0;
}

int main() {
    csv_t *csv = csv_create(3);
    csv_add_row(csv, (char *[]){"a", "b", "c"});
    csv_add_row(csv, (char *[]){"d", "e", "f"});
    csv_print(csv);
    csv_destroy(csv);
    return 0;
}