//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Ken Thompson
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

CSV_DATA *csv_read(char *filename) {
    CSV_DATA *csv_data = malloc(sizeof(CSV_DATA));
    csv_data->data = NULL;
    csv_data->num_lines = 0;
    csv_data->num_cols = 0;

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char line[MAX_LINES];
    while (fgets(line, MAX_LINES, fp) != NULL) {
        csv_data->num_lines++;
        csv_data->data = realloc(csv_data->data, csv_data->num_lines * sizeof(char *));
        csv_data->data[csv_data->num_lines - 1] = strdup(line);
    }

    fclose(fp);

    return csv_data;
}

int main() {
    CSV_DATA *csv_data = csv_read("data.csv");
    if (csv_data == NULL) {
        return 1;
    }

    for (int i = 0; i < csv_data->num_lines; i++) {
        printf("%s\n", csv_data->data[i]);
    }

    free(csv_data->data);
    free(csv_data);

    return 0;
}