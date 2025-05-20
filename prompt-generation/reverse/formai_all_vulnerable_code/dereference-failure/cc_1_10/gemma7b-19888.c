//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: artistic
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

CSV_DATA *csv_reader(char *file_name) {
    CSV_DATA *csv_data = malloc(sizeof(CSV_DATA));

    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        return NULL;
    }

    char line[MAX_ROWS];
    int rows = 0;
    while (fgets(line, MAX_ROWS, file) != NULL) {
        rows++;
    }

    csv_data->rows = rows;
    csv_data->cols = MAX_COLS;
    csv_data->data = malloc(sizeof(char *) * csv_data->rows);
    for (int i = 0; i < csv_data->rows; i++) {
        csv_data->data[i] = malloc(sizeof(char) * csv_data->cols);
    }

    rewind(file);
    int col = 0;
    while (fgets(line, MAX_ROWS, file) != NULL) {
        char *data = line;
        for (int row = 0; data[row] != '\n'; row++) {
            csv_data->data[row][col] = data[row];
        }
        col++;
    }

    fclose(file);

    return csv_data;
}

int main() {
    CSV_DATA *csv_data = csv_reader("data.csv");

    for (int row = 0; row < csv_data->rows; row++) {
        for (int col = 0; col < csv_data->cols; col++) {
            printf("%c ", csv_data->data[row][col]);
        }
        printf("\n");
    }

    free(csv_data->data);
    free(csv_data);

    return 0;
}