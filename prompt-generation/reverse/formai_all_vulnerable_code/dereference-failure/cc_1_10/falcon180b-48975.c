//Falcon-180B DATASET v1.0 Category: Data mining ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    char **data;
    int rows;
    int cols;
} DataSet;

DataSet read_csv(char *filename) {
    FILE *fp = fopen(filename, "r");
    DataSet dataset;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int rows = 0;
    int cols = 0;

    dataset.data = NULL;

    while ((read = getline(&line, &len, fp))!= -1) {
        if (rows == 0) {
            cols = count_columns(line);
            dataset.data = malloc(cols * sizeof(char *));
            for (int i = 0; i < cols; i++) {
                dataset.data[i] = NULL;
            }
        }

        char **row = dataset.data;
        char *token = strtok(line, ",");
        while (token!= NULL) {
            int col = count_columns(line) - 1;
            row[col] = strdup(token);
            token = strtok(NULL, ",");
            col++;
        }

        rows++;
    }

    fclose(fp);
    dataset.rows = rows;
    dataset.cols = cols;

    return dataset;
}

int count_columns(char *line) {
    int count = 0;
    char *token = strtok(line, ",");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, ",");
    }
    return count;
}

void print_dataset(DataSet dataset) {
    for (int i = 0; i < dataset.rows; i++) {
        for (int j = 0; j < dataset.cols; j++) {
            printf("%s ", dataset.data[i][j]);
        }
        printf("\n");
    }
}

void free_dataset(DataSet dataset) {
    for (int i = 0; i < dataset.rows; i++) {
        for (int j = 0; j < dataset.cols; j++) {
            free(dataset.data[i][j]);
        }
        free(dataset.data[i]);
    }
    free(dataset.data);
}

int main() {
    DataSet dataset = read_csv("data.csv");
    print_dataset(dataset);
    free_dataset(dataset);

    return 0;
}