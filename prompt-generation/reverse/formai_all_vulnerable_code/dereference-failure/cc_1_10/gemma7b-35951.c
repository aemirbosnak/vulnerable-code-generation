//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSV_DATA {
    char **data;
    int rows;
    int cols;
} CSV_DATA;

CSV_DATA *csv_read(char *filename)
{
    CSV_DATA *csv_data = malloc(sizeof(CSV_DATA));
    csv_data->data = NULL;
    csv_data->rows = 0;
    csv_data->cols = 0;

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char line[MAX_ROWS][MAX_COLS];
    int i = 0;
    while (fgets(line[i], MAX_COLS, fp) != NULL) {
        csv_data->rows++;
        char **row = realloc(csv_data->data, csv_data->rows * sizeof(char *));
        csv_data->data = row;
        csv_data->data[i] = strdup(line[i]);
        i++;
    }

    fclose(fp);
    return csv_data;
}

int main()
{
    char *filename = "test.csv";
    CSV_DATA *csv_data = csv_read(filename);

    if (csv_data) {
        for (int i = 0; i < csv_data->rows; i++) {
            printf("%s\n", csv_data->data[i]);
        }

        free(csv_data->data);
        free(csv_data);
    }

    return 0;
}