//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_SIZE 1000
#define MAX_COLUMNS 1000
#define DELIMITER ","

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} CSVData;

CSVData *read_csv_file(FILE *file) {
    CSVData *data = malloc(sizeof(CSVData));
    data->num_rows = 0;
    data->num_cols = 0;
    data->data = malloc(MAX_LINE_SIZE * MAX_COLUMNS);

    char line[MAX_LINE_SIZE];
    char *token = NULL;
    int row = 0;
    int col = 0;

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        row++;
        col = 0;
        char *save_ptr = NULL;
        token = strtok_r(line, DELIMITER, &save_ptr);
        while (token!= NULL) {
            col++;
            if (col > data->num_cols) {
                data->num_cols = col;
            }
            if (row > data->num_rows) {
                data->num_rows = row;
            }
            data->data[row * data->num_cols + col - 1] = token;
            token = strtok_r(NULL, DELIMITER, &save_ptr);
        }
    }

    return data;
}

void print_csv_data(CSVData *data) {
    int i, j;
    for (i = 0; i < data->num_rows; i++) {
        for (j = 0; j < data->num_cols; j++) {
            printf("%s ", data->data[i * data->num_cols + j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    CSVData *data = read_csv_file(file);
    if (data == NULL) {
        printf("Error reading file\n");
        return 1;
    }

    printf("CSV Data:\n");
    print_csv_data(data);

    free(data->data);
    free(data);

    fclose(file);
    return 0;
}