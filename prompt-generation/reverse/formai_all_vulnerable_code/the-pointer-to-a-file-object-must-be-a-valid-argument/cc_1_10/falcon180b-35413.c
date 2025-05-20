//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 1000
#define MAX_ROWS 1000
#define MAX_CELL_SIZE 1000

typedef struct {
    char **data;
    int rows;
    int columns;
} CsvData;

CsvData *read_csv(FILE *file) {
    CsvData *data = malloc(sizeof(CsvData));
    data->data = malloc(MAX_ROWS * sizeof(char *));
    data->rows = 0;
    data->columns = 0;

    char line[MAX_CELL_SIZE];
    char *token = strtok(line, ",");
    int column_count = 0;

    while (fgets(line, MAX_CELL_SIZE, file)!= NULL) {
        data->rows++;
        char *cell = strtok(line, ",");
        while (cell!= NULL) {
            data->columns = column_count > data->columns? column_count : data->columns;
            column_count++;
            data->data[data->rows - 1] = realloc(data->data[data->rows - 1], sizeof(char *) * (column_count + 1));
            data->data[data->rows - 1][column_count - 1] = strdup(cell);
            cell = strtok(NULL, ",");
        }
    }

    for (int i = 0; i < data->rows; i++) {
        for (int j = 0; j < data->columns; j++) {
            if (data->data[i][j] == NULL) {
                data->data[i][j] = strdup("");
            }
        }
    }

    return data;
}

void print_csv(CsvData *data) {
    for (int i = 0; i < data->rows; i++) {
        for (int j = 0; j < data->columns; j++) {
            printf("%s\t", data->data[i][j]);
        }
        printf("\n");
    }
}

void free_csv(CsvData *data) {
    for (int i = 0; i < data->rows; i++) {
        for (int j = 0; j < data->columns; j++) {
            free(data->data[i][j]);
        }
        free(data->data[i]);
    }
    free(data->data);
    free(data);
}

int main() {
    FILE *file = fopen("example.csv", "r");
    CsvData *data = read_csv(file);
    print_csv(data);
    free_csv(data);
    fclose(file);
    return 0;
}