//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **data;
    int rows; 
    int cols;
} CSV;

void free_csv(CSV* csv) {
    if (csv->data) {
        for (int i = 0; i < csv->rows; i++) {
            free(csv->data[i]);
        }
        free(csv->data);
    }
    free(csv);
}

CSV* read_csv(char* filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return NULL;
    }
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int row = 0;
    int col = 0;
    CSV *csv = calloc(1, sizeof(CSV));
    while ((read = getline(&line, &len, file)) != -1) {
        if (csv->data == NULL) {
            csv->data = calloc(1, sizeof(char*));
        } else {
            csv->data = realloc(csv->data, (row + 1) * sizeof(char *));
        }
        char *token;
        int i = 0;
        while ((token = strsep(&line, ",")) != NULL) {
            if (i == 0) {
                csv->data[row] = calloc(1, sizeof(char *));
            } else {
                csv->data[row] = realloc(csv->data[row], i * sizeof(char *));
            }
            csv->data[row][col] = calloc(strlen(token) + 1, sizeof(char));
            strcpy(csv->data[row][col], token);
            col++;
            i++;
        }
        if (csv->cols == 0) {
            csv->cols = i;
        }
        row++;
        col = 0;
    }
    csv->rows = row;
    if (line) {
        free(line);
    }
    fclose(file);
    return csv;
}

int main(int argc, char *argv[]) {
    CSV *csv = read_csv("example.csv");
    if (!csv) {
        return 1;
    }
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s,", csv->data[i][j]);
        }
        printf("\n");
    }
    free_csv(csv);
    return 0;
}