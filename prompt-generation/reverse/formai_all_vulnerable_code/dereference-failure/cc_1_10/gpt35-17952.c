//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char **data;
    int rows;
    int cols;
} csv_data_t;

csv_data_t csv_read(char *filename) {
    csv_data_t data;

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        data.data = NULL;
        data.rows = 0;
        data.cols = 0;
        return data;
    }

    data.rows = 0;
    data.cols = 0;
    char line[MAX_LINE_SIZE];
    char *tok;

    while (fgets(line, MAX_LINE_SIZE, fp)) {
        if (data.rows == 0) {
            // count number of columns in first row
            tok = strtok(line, ",");
            while (tok != NULL) {
                data.cols++;
                tok = strtok(NULL, ",");
            }

            // allocate memory for data array
            data.data = malloc(sizeof(char *) * data.rows);
            for (int i = 0; i < data.rows; i++) {
                data.data[i] = malloc(sizeof(char) * MAX_LINE_SIZE);
            }
        }

        // tokenize line and store in data array
        tok = strtok(line, ",");
        int col = 0;
        while (tok != NULL) {
            strcpy(data.data[data.rows] + (col * MAX_LINE_SIZE), tok);
            col++;
            tok = strtok(NULL, ",");
        }

        data.rows++;
        data.data = realloc(data.data, sizeof(char *) * data.rows);
        for (int i = 0; i < data.rows; i++) {
            data.data[i] = realloc(data.data[i], sizeof(char) * MAX_LINE_SIZE);
        }
    }

    fclose(fp);

    return data;
}

int main() {
    csv_data_t data = csv_read("example.csv");

    printf("Number of rows: %d\n", data.rows);
    printf("Number of columns: %d\n", data.cols);

    for (int i = 0; i < data.rows; i++) {
        for (int j = 0; j < data.cols; j++) {
            printf("%s%c", data.data[i] + (j * MAX_LINE_SIZE), j == data.cols - 1 ? '\n' : ',');
        }
    }

    // free memory
    for (int i = 0; i < data.rows; i++) {
        free(data.data[i]);
    }
    free(data.data);

    return 0;
}