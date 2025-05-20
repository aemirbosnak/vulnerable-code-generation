//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CsvData {
    char **labels;
    int rows, cols;
    char ***data;
};

int count_chars(char *str, char c) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == c) count++;
    }
    return count;
}

void free_csv_data(struct CsvData *csv_data) {
    for (int i = 0; i < csv_data -> rows; i++) {
        for (int j = 0; j < csv_data -> cols; j++) {
            free(csv_data -> data[i][j]);
        }
        free(csv_data -> data[i]);
    }
    free(csv_data -> data);
    for (int i = 0; i < csv_data -> cols; i++) {
        free(csv_data -> labels[i]);
    }
    free(csv_data -> labels);
    free(csv_data);
}

int load_csv(struct CsvData **csv_data, char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) return -1;

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int row_count = 0;
    int col_count = 0;

    struct CsvData *data = malloc(sizeof(struct CsvData));

    if ((read = getline(&line, &len, file)) != -1) {
        col_count = count_chars(line, ',') + 1;
        data -> labels = malloc(col_count * sizeof(char *));
        char *token = strtok(line, ",\n");
        int i = 0;
        while (token) {
            data -> labels[i] = malloc((strlen(token) + 1) * sizeof(char));
            strcpy(data -> labels[i], token);
            token = strtok(NULL, ",\n");
            i++;
        }
    }

    int max_rows = 10;
    data -> data = malloc(max_rows * sizeof(char ***));
    while ((read = getline(&line, &len, file)) != -1) {
        if (row_count >= max_rows) {
            max_rows *= 2;
            data -> data = realloc(data -> data, max_rows * sizeof(char ***));
        }
        data -> data[row_count] = malloc(col_count * sizeof(char **));
        char *token = strtok(line, ",\n");
        int i = 0;
        while (token) {
            data -> data[row_count][i] = malloc((strlen(token) + 1) * sizeof(char));
            strcpy(data -> data[row_count][i], token);
            token = strtok(NULL, ",\n");
            i++;
        }
        row_count++;
    }
    data -> rows = row_count;
    data -> cols = col_count;

    if (line) free(line);
    fclose(file);
    *csv_data = data;

    return 0;
}

int main() {
    struct CsvData *data;
    if (load_csv(&data, "example.csv") < 0) {
        printf("Failed to load CSV data\n");
    }

    for (int i = 0; i < data -> cols; i++) {
        printf("%s\t", data -> labels[i]);
    }
    printf("\n");

    for (int i = 0; i < data -> rows; i++) {
        for (int j = 0; j < data -> cols; j++) {
            printf("%s\t", data -> data[i][j]);
        }
        printf("\n");
    }

    free_csv_data(data);

    return 0;
}