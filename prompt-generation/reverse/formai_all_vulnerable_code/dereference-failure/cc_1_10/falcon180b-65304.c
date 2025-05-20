//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define DELIMITER ','

typedef struct {
    char **data;
    int rows;
    int cols;
} CsvData;

void csv_read_file(char *filename, CsvData *data) {
    FILE *fp;
    char line[1024];
    char *token;
    int row = 0;
    int col = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    data->rows = 0;
    data->cols = 0;
    data->data = (char **)malloc(MAX_ROWS * sizeof(char *));

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (row >= MAX_ROWS) {
            printf("Error: Exceeded maximum number of rows\n");
            exit(1);
        }

        token = strtok(line, DELIMITER);
        while (token!= NULL) {
            if (col >= MAX_COLS) {
                printf("Error: Exceeded maximum number of columns\n");
                exit(1);
            }

            data->data[row] = (char *)realloc(data->data[row], strlen(token) + 1);
            strcpy(data->data[row], token);

            col++;
            token = strtok(NULL, DELIMITER);
        }

        row++;
    }

    fclose(fp);

    data->rows = row;
    data->cols = col;
}

void csv_print_data(CsvData *data) {
    int i, j;

    for (i = 0; i < data->rows; i++) {
        for (j = 0; j < data->cols; j++) {
            printf("%s ", data->data[i]);
        }
        printf("\n");
    }
}

void csv_free_data(CsvData *data) {
    int i;

    for (i = 0; i < data->rows; i++) {
        free(data->data[i]);
    }

    free(data->data);
}

int main(int argc, char *argv[]) {
    CsvData data;

    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    csv_read_file(argv[1], &data);
    csv_print_data(&data);
    csv_free_data(&data);

    return 0;
}