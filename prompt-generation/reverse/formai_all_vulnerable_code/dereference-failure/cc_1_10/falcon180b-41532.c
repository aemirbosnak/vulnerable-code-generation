//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_COLUMNS 100
#define DELIMITER ','

typedef struct {
    char **values;
    int num_rows;
    int num_columns;
} CSVData;

CSVData *read_csv_file(FILE *file) {
    CSVData *data = malloc(sizeof(CSVData));
    data->values = NULL;
    data->num_rows = 0;
    data->num_columns = 0;

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char *token = strtok(line, DELIMITER);
        int num_columns_in_row = 0;

        while (token!= NULL) {
            num_columns_in_row++;
            if (data->num_columns == 0) {
                data->num_columns = num_columns_in_row;
            } else if (num_columns_in_row!= data->num_columns) {
                printf("Error: inconsistent number of columns\n");
                exit(1);
            }

            if (data->num_rows == 0) {
                data->values = malloc(data->num_columns * sizeof(char *));
            } else {
                data->values = realloc(data->values, data->num_columns * sizeof(char *) * (data->num_rows + 1));
            }

            data->values[data->num_rows * data->num_columns + num_columns_in_row - 1] = strdup(token);

            token = strtok(NULL, DELIMITER);
        }

        data->num_rows++;
    }

    return data;
}

void print_csv_data(CSVData *data) {
    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_columns; j++) {
            printf("%s\t", data->values[i * data->num_columns + j]);
        }
        printf("\n");
    }
}

void free_csv_data(CSVData *data) {
    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_columns; j++) {
            free(data->values[i * data->num_columns + j]);
        }
    }
    free(data->values);
    free(data);
}

int main() {
    FILE *file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    CSVData *data = read_csv_file(file);
    print_csv_data(data);
    free_csv_data(data);

    fclose(file);
    return 0;
}