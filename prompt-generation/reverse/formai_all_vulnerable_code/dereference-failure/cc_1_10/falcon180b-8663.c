//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 1000
#define DELIMITER ','

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} csv_data;

csv_data* read_csv(FILE *file) {
    csv_data *data = malloc(sizeof(csv_data));
    data->num_rows = 0;
    data->num_cols = 0;
    data->data = malloc(MAX_COLUMNS * sizeof(char*));

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *token = strtok(line, DELIMITER);
        while (token!= NULL) {
            if (data->num_cols >= MAX_COLUMNS) {
                printf("Error: CSV file has too many columns.\n");
                exit(1);
            }
            data->data[data->num_cols++] = strdup(token);
            token = strtok(NULL, DELIMITER);
        }
        if (data->num_rows >= MAX_COLUMNS) {
            printf("Error: CSV file has too many rows.\n");
            exit(1);
        }
        data->num_rows++;
    }

    return data;
}

void print_csv(csv_data *data) {
    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_cols; j++) {
            printf("%s ", data->data[j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error: Could not open CSV file.\n");
        exit(1);
    }

    csv_data *data = read_csv(file);
    fclose(file);

    print_csv(data);

    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_cols; j++) {
            free(data->data[j]);
        }
        free(data->data[i]);
    }
    free(data->data);
    free(data);

    return 0;
}