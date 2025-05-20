//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 1000

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} CSVData;

CSVData *read_csv(FILE *file) {
    CSVData *data = malloc(sizeof(CSVData));
    data->num_rows = 0;
    data->num_cols = 0;
    data->data = malloc(MAX_ROWS * sizeof(char *));

    char line[MAX_CELL_SIZE];
    char *token = NULL;
    int row = 0;
    int col = 0;

    while (fgets(line, MAX_CELL_SIZE, file)!= NULL) {
        row++;
        data->num_rows++;

        token = strtok(line, ",");
        while (token!= NULL) {
            col++;
            data->num_cols = col > data->num_cols? col : data->num_cols;

            data->data[row] = realloc(data->data[row], data->num_cols * sizeof(char *));
            data->data[row][col - 1] = strdup(token);

            token = strtok(NULL, ",");
        }
    }

    return data;
}

void print_csv(CSVData *data) {
    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_cols; j++) {
            printf("%s\t", data->data[i][j]);
        }
        printf("\n");
    }
}

void free_csv(CSVData *data) {
    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_cols; j++) {
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
        printf("Error opening file\n");
        return 1;
    }

    CSVData *data = read_csv(file);
    if (data == NULL) {
        printf("Error reading file\n");
        return 1;
    }

    print_csv(data);

    free_csv(data);

    fclose(file);

    return 0;
}