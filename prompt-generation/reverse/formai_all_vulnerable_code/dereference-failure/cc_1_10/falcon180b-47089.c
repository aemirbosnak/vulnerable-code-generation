//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_CELL_SIZE 100

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} csv_data;

csv_data *read_csv_file(FILE *file) {
    csv_data *data = (csv_data *)malloc(sizeof(csv_data));
    data->data = (char **)malloc(MAX_ROWS * sizeof(char *));
    data->num_rows = 0;
    data->num_cols = 0;

    char line[MAX_CELL_SIZE];
    char *token = NULL;
    int row = 0;
    int col = 0;

    while (fgets(line, MAX_CELL_SIZE, file)!= NULL) {
        token = strtok(line, ",");
        while (token!= NULL) {
            if (col >= MAX_COLS) {
                printf("Error: Too many columns.\n");
                exit(1);
            }
            data->data[row] = (char *)realloc(data->data[row], (col + 1) * sizeof(char));
            strcpy(data->data[row] + col * MAX_CELL_SIZE, token);
            col++;
            token = strtok(NULL, ",");
        }
        row++;
        col = 0;
    }

    data->num_rows = row;
    data->num_cols = col;

    return data;
}

void print_csv_data(csv_data *data) {
    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_cols; j++) {
            printf("%s ", data->data[i] + j * MAX_CELL_SIZE);
        }
        printf("\n");
    }
}

int main() {
    FILE *file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    csv_data *data = read_csv_file(file);
    print_csv_data(data);

    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_cols; j++) {
            printf("%c", data->data[i][j]);
        }
        printf("\n");
    }

    free(data->data);
    free(data);
    fclose(file);

    return 0;
}