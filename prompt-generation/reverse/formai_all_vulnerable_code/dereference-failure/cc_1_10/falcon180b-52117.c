//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_COLUMNS 100
#define DELIMITER ','

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} CSVData;

CSVData *read_csv(FILE *file) {
    int row = 0, col = 0;
    CSVData *data = malloc(sizeof(CSVData));
    data->num_rows = 0;
    data->num_cols = 0;
    data->data = malloc(MAX_COLUMNS * sizeof(char *));

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char *token = strtok(line, DELIMITER);
        while (token!= NULL) {
            col++;
            if (col > data->num_cols) {
                data->num_cols = col;
                data->data = realloc(data->data, MAX_COLUMNS * sizeof(char *));
            }
            data->data[col - 1] = token;
            token = strtok(NULL, DELIMITER);
        }
        row++;
        data->num_rows = row;
    }

    return data;
}

void print_csv(CSVData *data) {
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
        printf("Could not open file.\n");
        exit(1);
    }

    CSVData *data = read_csv(file);

    print_csv(data);

    free(data->data);
    free(data);

    fclose(file);
    return 0;
}