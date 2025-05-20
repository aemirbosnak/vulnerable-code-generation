//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSV_ROW {
    char **data;
    int num_cols;
} CSV_ROW;

CSV_ROW *read_csv(char *filename) {
    CSV_ROW *row = malloc(sizeof(CSV_ROW));
    row->data = malloc(MAX_ROWS * MAX_COLS * sizeof(char *));
    row->num_cols = 0;

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char line[MAX_ROWS];
    while (fgets(line, MAX_ROWS, fp) != NULL) {
        char **data = row->data;
        int num_cols = row->num_cols;
        char *ptr = strtok(line, ",");

        while (ptr) {
            data[num_cols++] = strdup(ptr);
            ptr = strtok(NULL, ",");
        }

        row->num_cols = num_cols;
    }

    fclose(fp);
    return row;
}

int main() {
    CSV_ROW *row = read_csv("data.csv");
    if (row) {
        for (int i = 0; i < row->num_cols; i++) {
            printf("%s,", row->data[0][i]);
        }
        printf("\n");

        free(row->data);
        free(row);
    }

    return 0;
}