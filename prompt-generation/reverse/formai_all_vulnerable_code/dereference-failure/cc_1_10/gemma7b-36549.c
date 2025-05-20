//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSV_ROW {
    char **data;
    int num_cols;
} CSV_ROW;

CSV_ROW *read_csv(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    CSV_ROW *row = malloc(sizeof(CSV_ROW));
    row->data = malloc(MAX_ROWS * MAX_COLS * sizeof(char *));
    row->num_cols = 0;

    char line[1024];
    while (fgets(line, 1024, fp) != NULL) {
        char *comma = strchr(line, ',');
        int num_cols = 0;
        while (comma) {
            char *data = malloc(MAX_COLS * sizeof(char));
            memcpy(data, comma + 1, MAX_COLS * sizeof(char) - 1);
            row->data[row->num_cols++] = data;
            comma = strchr(comma + 1, ',');
        }
        row->data[row->num_cols++] = NULL;
    }

    fclose(fp);
    return row;
}

int main() {
    CSV_ROW *row = read_csv("data.csv");
    for (int i = 0; row->data[i] != NULL; i++) {
        for (int j = 0; row->data[i][j] != NULL; j++) {
            printf("%s,", row->data[i][j]);
        }
        printf("\n");
    }

    free(row);
    return 0;
}