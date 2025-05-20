//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 1000
#define MAX_ROWS 1000

typedef struct {
    char **data;
    int rows;
    int columns;
} CsvData;

CsvData *read_csv(FILE *file) {
    CsvData *csv_data = malloc(sizeof(CsvData));
    csv_data->rows = 0;
    csv_data->columns = 0;
    csv_data->data = malloc(MAX_ROWS * sizeof(char *));

    char line[MAX_LINE_LENGTH];
    char *token;
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        csv_data->rows++;
        if (csv_data->columns == 0) {
            token = strtok(line, ",");
            while (token!= NULL) {
                csv_data->columns++;
                token = strtok(NULL, ",");
            }
        }
    }

    rewind(file);
    csv_data->data = realloc(csv_data->data, csv_data->rows * sizeof(char *));
    for (int i = 0; i < csv_data->rows; i++) {
        csv_data->data[i] = malloc(MAX_LINE_LENGTH * sizeof(char));
        fgets(csv_data->data[i], MAX_LINE_LENGTH, file);
    }

    return csv_data;
}

void print_csv(CsvData *csv_data) {
    for (int i = 0; i < csv_data->rows; i++) {
        for (int j = 0; j < csv_data->columns; j++) {
            printf("%s ", csv_data->data[i]);
        }
        printf("\n");
    }
}

int main() {
    FILE *file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    CsvData *csv_data = read_csv(file);
    print_csv(csv_data);

    fclose(file);
    free(csv_data->data);
    free(csv_data);
    return 0;
}