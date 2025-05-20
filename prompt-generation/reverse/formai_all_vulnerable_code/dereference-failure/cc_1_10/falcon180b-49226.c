//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_DATA 1000

// Structure for CSV data
typedef struct {
    char delimiter;
    int num_rows;
    int num_cols;
    char **data;
} csv_data;

// Function to read CSV file and populate data structure
csv_data *read_csv(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    csv_data *data = malloc(sizeof(csv_data));
    data->delimiter = ',';
    data->num_rows = 0;
    data->num_cols = 0;
    data->data = malloc(MAX_ROWS * sizeof(char*));

    char line[MAX_CELL_DATA];
    while (fgets(line, MAX_CELL_DATA, fp)!= NULL) {
        if (data->num_rows >= MAX_ROWS) {
            printf("Error: Maximum number of rows exceeded.\n");
            exit(1);
        }
        data->data[data->num_rows] = malloc(MAX_CELL_DATA);
        strcpy(data->data[data->num_rows], line);
        data->num_rows++;

        int num_cols = 0;
        char *token = strtok(line, data->delimiter);
        while (token!= NULL) {
            if (data->num_cols >= MAX_COLS) {
                printf("Error: Maximum number of columns exceeded.\n");
                exit(1);
            }
            data->data[data->num_rows-1][num_cols] = malloc(MAX_CELL_DATA);
            strcpy(data->data[data->num_rows-1][num_cols], token);
            num_cols++;
            token = strtok(NULL, data->delimiter);
        }
        data->num_cols = num_cols;
    }

    fclose(fp);
    return data;
}

// Function to print CSV data
void print_csv(csv_data *data) {
    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_cols; j++) {
            printf("%s\t", data->data[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    csv_data *data = read_csv(argv[1]);
    if (data == NULL) {
        exit(1);
    }

    print_csv(data);

    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_cols; j++) {
            free(data->data[i][j]);
        }
        free(data->data[i]);
    }
    free(data->data);
    free(data);

    return 0;
}