//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 128
#define MAX_ROWS 1024

typedef struct {
    int num_cols;
    char *cols[MAX_COLS];
    char *data[MAX_ROWS][MAX_COLS];
} CSV;

CSV *read_csv(char *filename) {
    CSV *csv = (CSV*) malloc(sizeof(CSV));
    FILE *file = fopen(filename, "r");

    if (!file) {
        printf("Error: could not open file '%s'\n", filename);
        return NULL;
    }

    // read header row
    char line[1024];
    if (!fgets(line, sizeof(line), file)) {
        printf("Error: file '%s' is empty\n", filename);
        fclose(file);
        return NULL;
    }

    char *token = strtok(line, ",");
    int col = 0;
    while (token) {
        csv->cols[col++] = strdup(token);
        token = strtok(NULL, ",");
    }
    csv->num_cols = col;

    // read data rows
    int row = 0;
    while (fgets(line, sizeof(line), file) && row < MAX_ROWS) {
        token = strtok(line, ",");
        col = 0;
        while (token && col < csv->num_cols) {
            csv->data[row][col++] = strdup(token);
            token = strtok(NULL, ",");
        }
        row++;
    }

    fclose(file);
    return csv;
}

void free_csv(CSV *csv) {
    for (int i = 0; i < csv->num_cols; i++) {
        free(csv->cols[i]);
    }
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            if (csv->data[i][j]) {
                free(csv->data[i][j]);
            }
        }
    }
    free(csv);
}

int main() {
    CSV *csv = read_csv("example.csv");
    if (!csv) {
        return 1;
    }

    printf("CSV file has %d columns\n", csv->num_cols);
    printf("Header: ");
    for (int i = 0; i < csv->num_cols; i++) {
        printf("%s", csv->cols[i]);
        if (i < csv->num_cols - 1) {
            printf(", ");
        } else {
            printf("\n");
        }
    }
    printf("Data:\n");
    for (int i = 0; i < MAX_ROWS && csv->data[i][0]; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            printf("%s", csv->data[i][j]);
            if (j < csv->num_cols - 1) {
                printf(", ");
            } else {
                printf("\n");
            }
        }
    }

    free_csv(csv);
    return 0;
}