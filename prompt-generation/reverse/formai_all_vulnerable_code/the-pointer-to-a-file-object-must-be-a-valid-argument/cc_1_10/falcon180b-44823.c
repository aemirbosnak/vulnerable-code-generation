//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_COLUMNS 100
#define MAX_ROWS 100
#define DELIMITER ','

typedef struct {
    char **data;
    int rows;
    int columns;
} CSVData;

CSVData *read_csv_file(FILE *file) {
    CSVData *data = malloc(sizeof(CSVData));
    data->data = NULL;
    data->rows = 0;
    data->columns = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *token = strtok(line, DELIMITER);
        int columns = 0;

        while (token!= NULL) {
            columns++;
            token = strtok(NULL, DELIMITER);
        }

        if (data->rows == 0) {
            data->columns = columns;
            data->data = malloc(sizeof(char *) * columns);
        } else if (data->columns!= columns) {
            printf("Error: number of columns in row %d does not match previous rows.\n", data->rows + 1);
            exit(1);
        }

        int i = 0;
        token = strtok(line, DELIMITER);
        while (token!= NULL) {
            data->data[i] = malloc(sizeof(char) * (strlen(token) + 1));
            strcpy(data->data[i], token);
            i++;
            token = strtok(NULL, DELIMITER);
        }

        data->rows++;
    }

    return data;
}

void print_csv_data(CSVData *data) {
    int i, j;
    for (i = 0; i < data->rows; i++) {
        for (j = 0; j < data->columns; j++) {
            printf("%s ", data->data[i * data->columns + j]);
        }
        printf("\n");
    }
}

void free_csv_data(CSVData *data) {
    int i, j;
    for (i = 0; i < data->rows; i++) {
        for (j = 0; j < data->columns; j++) {
            free(data->data[i * data->columns + j]);
        }
    }
    free(data->data);
    free(data);
}

int main() {
    FILE *file = fopen("example.csv", "r");
    CSVData *data = read_csv_file(file);
    print_csv_data(data);
    free_csv_data(data);
    fclose(file);

    return 0;
}