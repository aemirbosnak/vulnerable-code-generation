//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSV_ROW {
    char **data;
    int num_cols;
} CSV_ROW;

typedef struct CSV_TABLE {
    CSV_ROW **rows;
    int num_rows;
} CSV_TABLE;

CSV_TABLE *csv_read(char *filename) {
    FILE *fp;
    CSV_TABLE *table = malloc(sizeof(CSV_TABLE));
    table->rows = NULL;
    table->num_rows = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char buffer[MAX_BUFFER_SIZE];
    char *line = NULL;
    int line_num = 0;

    while ((line = fgets(buffer, MAX_BUFFER_SIZE, fp)) != NULL) {
        line_num++;
        CSV_ROW *row = malloc(sizeof(CSV_ROW));
        row->data = NULL;
        row->num_cols = 0;

        char *token = strtok(line, ",");
        while (token) {
            row->data = realloc(row->data, (row->num_cols + 1) * sizeof(char *));
            row->data[row->num_cols++] = strdup(token);
            token = strtok(NULL, ",");
        }

        table->rows = realloc(table->rows, (table->num_rows + 1) * sizeof(CSV_ROW *));
        table->rows[table->num_rows++] = row;
    }

    fclose(fp);

    return table;
}

int main() {
    char *filename = "test.csv";
    CSV_TABLE *table = csv_read(filename);

    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->rows[i]->num_cols; j++) {
            printf("%s,", table->rows[i]->data[j]);
        }
        printf("\n");
    }

    free(table);

    return 0;
}