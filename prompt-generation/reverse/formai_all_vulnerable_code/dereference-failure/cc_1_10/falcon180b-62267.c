//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW_COLUMNS 1000
#define MAX_COLUMN_NAME_LENGTH 100

typedef struct {
    char **row_data;
    int num_rows;
    int num_columns;
} CsvData;

CsvData *read_csv_file(FILE *csv_file) {
    CsvData *csv_data = malloc(sizeof(CsvData));
    csv_data->row_data = NULL;
    csv_data->num_rows = 0;
    csv_data->num_columns = 0;

    char line[MAX_ROW_COLUMNS];
    char delimiter = ',';
    int row_num = 0;

    while (fgets(line, MAX_ROW_COLUMNS, csv_file)!= NULL) {
        int num_columns = 0;
        char *token = strtok(line, &delimiter);

        while (token!= NULL) {
            num_columns++;
            token = strtok(NULL, &delimiter);
        }

        if (num_columns > csv_data->num_columns) {
            csv_data->num_columns = num_columns;
        }

        csv_data->row_data = realloc(csv_data->row_data, sizeof(char *) * csv_data->num_rows * csv_data->num_columns);

        for (int i = 0; i < num_columns; i++) {
            csv_data->row_data[row_num * csv_data->num_columns + i] = strdup(token);
            token = strtok(NULL, &delimiter);
        }

        row_num++;
    }

    csv_data->num_rows = row_num;

    return csv_data;
}

void print_csv_data(CsvData *csv_data) {
    for (int i = 0; i < csv_data->num_rows; i++) {
        for (int j = 0; j < csv_data->num_columns; j++) {
            printf("%s\t", csv_data->row_data[i * csv_data->num_columns + j]);
        }
        printf("\n");
    }
}

void free_csv_data(CsvData *csv_data) {
    for (int i = 0; i < csv_data->num_rows; i++) {
        for (int j = 0; j < csv_data->num_columns; j++) {
            free(csv_data->row_data[i * csv_data->num_columns + j]);
        }
    }

    free(csv_data->row_data);
    free(csv_data);
}

int main() {
    FILE *csv_file = fopen("example.csv", "r");

    if (csv_file == NULL) {
        printf("Error: Could not open CSV file.\n");
        return 1;
    }

    CsvData *csv_data = read_csv_file(csv_file);

    if (csv_data == NULL) {
        printf("Error: Could not read CSV data.\n");
        fclose(csv_file);
        return 1;
    }

    print_csv_data(csv_data);

    free_csv_data(csv_data);
    fclose(csv_file);

    return 0;
}