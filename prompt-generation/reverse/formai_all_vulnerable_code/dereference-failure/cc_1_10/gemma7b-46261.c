//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_COLS 20

typedef struct CSV_DATA {
    char **data;
    int num_lines;
    int num_cols;
} CSV_DATA;

CSV_DATA *read_csv(char *filename) {
    CSV_DATA *csv_data = malloc(sizeof(CSV_DATA));
    csv_data->num_lines = 0;
    csv_data->num_cols = 0;
    csv_data->data = NULL;

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char line[MAX_LINES];
    while (fgets(line, MAX_LINES, fp) != NULL) {
        char **columns = NULL;
        int num_cols = 0;
        char *ptr = line;
        while (ptr && *ptr) {
            columns = realloc(columns, (num_cols + 1) * sizeof(char *));
            columns[num_cols++] = strdup(ptr);
            ptr += strcspn(ptr, ",") + 1;
        }
        csv_data->num_lines++;
        csv_data->data = realloc(csv_data->data, csv_data->num_lines * sizeof(char **));
        csv_data->data[csv_data->num_lines - 1] = columns;
        csv_data->num_cols = num_cols;
    }

    fclose(fp);

    return csv_data;
}

int main() {
    char *filename = "romeo_and_juliet.csv";
    CSV_DATA *csv_data = read_csv(filename);

    if (csv_data) {
        for (int i = 0; i < csv_data->num_lines; i++) {
            for (int j = 0; j < csv_data->num_cols; j++) {
                printf("%s,", csv_data->data[i][j]);
            }
            printf("\n");
        }
        free(csv_data->data);
        free(csv_data);
    }

    return 0;
}