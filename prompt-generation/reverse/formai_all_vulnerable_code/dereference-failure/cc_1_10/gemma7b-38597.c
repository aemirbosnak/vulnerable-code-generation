//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    char line[MAX_LINES];
    while (fgets(line, MAX_LINES, file) != NULL) {
        csv_data->num_lines++;
        csv_data->data = realloc(csv_data->data, csv_data->num_lines * sizeof(char *));
        csv_data->data[csv_data->num_lines - 1] = malloc(MAX_COLS * sizeof(char));
        char *ptr = csv_data->data[csv_data->num_lines - 1];
        int i = 0;
        for (i = 0; line[i] != ',' && line[i] != '\0'; i++) {
            ptr[i] = line[i];
        }
        ptr[i] = '\0';
    }

    fclose(file);
    return csv_data;
}

int main() {
    CSV_DATA *csv_data = read_csv("example.csv");
    if (csv_data == NULL) {
        return 1;
    }

    for (int i = 0; i < csv_data->num_lines; i++) {
        for (int j = 0; j < csv_data->num_cols; j++) {
            printf("%s,", csv_data->data[i][j]);
        }
        printf("\n");
    }

    free(csv_data->data);
    free(csv_data);
    return 0;
}