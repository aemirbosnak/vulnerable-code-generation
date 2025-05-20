//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_COLUMNS 1000
#define MAX_ROWS 1000

typedef struct {
    char **data;
    int num_rows;
    int num_columns;
} CSVData;

CSVData *csv_read_file(FILE *file) {
    CSVData *data = malloc(sizeof(CSVData));
    data->num_rows = 0;
    data->num_columns = 0;
    data->data = malloc(sizeof(char *) * MAX_ROWS);

    char line[MAX_LINE_SIZE];
    char *token;
    int row = 0;
    int column = 0;

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        row++;
        column = 0;
        char *line_copy = strdup(line);
        token = strtok(line_copy, ",");
        while (token!= NULL) {
            data->data[row] = realloc(data->data[row], sizeof(char *) * ++data->num_columns);
            data->data[row][column] = strdup(token);
            column++;
            token = strtok(NULL, ",");
        }
        free(line_copy);
    }

    data->num_rows = row;
    data->num_columns = column;

    return data;
}

void csv_print_data(CSVData *data) {
    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_columns; j++) {
            printf("%s ", data->data[i][j]);
        }
        printf("\n");
    }
}

void csv_free_data(CSVData *data) {
    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_columns; j++) {
            free(data->data[i][j]);
        }
        free(data->data[i]);
    }
    free(data->data);
    free(data);
}

int main() {
    FILE *file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    CSVData *data = csv_read_file(file);
    if (data == NULL) {
        printf("Error reading file.\n");
        return 2;
    }

    csv_print_data(data);

    csv_free_data(data);

    return 0;
}