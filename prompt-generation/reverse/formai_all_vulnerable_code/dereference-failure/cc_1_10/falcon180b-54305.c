//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 1000
#define DELIMITER ','

typedef struct {
    char **data;
    int num_rows;
    int num_columns;
} CsvData;

CsvData *csv_read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    CsvData *data = (CsvData *) malloc(sizeof(CsvData));
    data->num_rows = 0;
    data->num_columns = 0;
    data->data = (char **) malloc(MAX_COLUMNS * sizeof(char *));

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *token = strtok(line, DELIMITER);
        int column_count = 0;

        while (token!= NULL) {
            data->data[column_count] = (char *) malloc((strlen(token) + 1) * sizeof(char));
            strcpy(data->data[column_count], token);
            column_count++;

            token = strtok(NULL, DELIMITER);
        }

        data->num_columns = column_count;
        data->num_rows++;
    }

    fclose(file);
    return data;
}

void csv_print_data(CsvData *data) {
    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_columns; j++) {
            printf("%s ", data->data[j]);
        }
        printf("\n");
    }
}

void csv_free_data(CsvData *data) {
    for (int i = 0; i < data->num_columns; i++) {
        free(data->data[i]);
    }
    free(data->data);
    free(data);
}

int main() {
    CsvData *data = csv_read_file("example.csv");
    csv_print_data(data);
    csv_free_data(data);

    return 0;
}