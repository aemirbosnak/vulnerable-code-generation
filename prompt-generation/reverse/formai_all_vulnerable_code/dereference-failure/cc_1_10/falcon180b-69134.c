//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 1000
#define MAX_ROWS 10000
#define MAX_CELL_SIZE 1000

typedef struct {
    char **values;
    int num_columns;
    int num_rows;
} CsvData;

CsvData *csv_read(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    CsvData *data = malloc(sizeof(CsvData));
    data->values = malloc(MAX_ROWS * sizeof(char *));
    data->num_columns = 0;
    data->num_rows = 0;

    char line[MAX_CELL_SIZE];
    while (fgets(line, MAX_CELL_SIZE, file)!= NULL) {
        char *token = strtok(line, ",");
        while (token!= NULL) {
            data->num_columns++;
            if (data->num_columns >= MAX_COLUMNS) {
                printf("Error: too many columns\n");
                exit(1);
            }
            data->values[data->num_rows] = malloc(MAX_CELL_SIZE);
            strcpy(data->values[data->num_rows], token);
            data->num_rows++;
            if (data->num_rows >= MAX_ROWS) {
                printf("Error: too many rows\n");
                exit(1);
            }
            token = strtok(NULL, ",");
        }
    }

    fclose(file);
    return data;
}

void csv_print(CsvData *data) {
    for (int i = 0; i < data->num_columns; i++) {
        printf("%s", data->values[0][i]);
        for (int j = 1; j < data->num_rows; j++) {
            printf(",%s", data->values[j][i]);
        }
        printf("\n");
    }
}

void csv_free(CsvData *data) {
    for (int i = 0; i < data->num_rows; i++) {
        free(data->values[i]);
    }
    free(data->values);
    free(data);
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    CsvData *data = csv_read(argv[1]);
    csv_print(data);
    csv_free(data);

    return 0;
}