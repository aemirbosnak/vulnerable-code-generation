//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000

typedef struct CSV_Row {
    char **data;
    int num_cols;
} CSV_Row;

CSV_Row **read_csv(char *filename) {
    CSV_Row **rows = NULL;
    int num_rows = 0;
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char line[MAX_ROWS];
    while (fgets(line, MAX_ROWS, fp) != NULL) {
        CSV_Row *row = malloc(sizeof(CSV_Row));
        row->data = malloc(sizeof(char *) * MAX_ROWS);
        row->num_cols = 0;

        char *token = strtok(line, ",");
        while (token) {
            row->data[row->num_cols++] = strdup(token);
            token = strtok(NULL, ",");
        }

        rows = realloc(rows, sizeof(CSV_Row *) * (num_rows + 1));
        rows[num_rows++] = row;
    }

    fclose(fp);
    return rows;
}

int main() {
    CSV_Row **rows = read_csv("example.csv");
    for (int i = 0; rows[i] != NULL; i++) {
        for (int j = 0; rows[i]->data[j] != NULL; j++) {
            printf("%s,", rows[i]->data[j]);
        }
        printf("\n");
    }

    return 0;
}