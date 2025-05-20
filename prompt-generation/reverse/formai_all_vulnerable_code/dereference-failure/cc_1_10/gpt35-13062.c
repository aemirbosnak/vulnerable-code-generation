//FormAI DATASET v1.0 Category: Data mining ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 10
#define MAX_ROWS 100

typedef struct {
    char *data[MAX_ROWS][MAX_COLUMNS];
    int num_rows;
    int num_columns;
} CsvData;

CsvData *load_csv(char *filename, char delimiter);
void free_csv(CsvData *data);

CsvData *load_csv(char *filename, char delimiter) {
    CsvData *csv_data = malloc(sizeof(CsvData));
    csv_data->num_rows = 0;
    csv_data->num_columns = 0;

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open %s file\n", filename);
        return NULL;
    }

    char line[1024];
    while (fgets(line, 1024, file)) {
        char *token;
        int column = 0;
        char *ptr = strtok(line, &delimiter);
        while (ptr != NULL) {
            csv_data->data[csv_data->num_rows][column] = malloc(strlen(ptr) + 1);
            strcpy(csv_data->data[csv_data->num_rows][column], ptr);

            ptr = strtok(NULL, &delimiter);
            column++;
        }

        if (column > csv_data->num_columns) {
            csv_data->num_columns = column;
        }

        csv_data->num_rows++;
    }

    fclose(file);
    return csv_data;
}

void free_csv(CsvData *data) {
    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_columns; j++) {
            free(data->data[i][j]);
        }
    }
    free(data);
}

int main() {
    CsvData *csv_data = load_csv("data.csv", ',');
    if(csv_data == NULL) { return 1; }

    for (int i = 0; i < csv_data->num_rows; i++) {
        for (int j = 0; j < csv_data->num_columns; j++) {
            printf("%s\t", csv_data->data[i][j]);
        }
        printf("\n");
    }

    free_csv(csv_data);

    return 0;
}