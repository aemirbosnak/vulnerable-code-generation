//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} csv_t;

csv_t *csv_read(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    // Read the first line to get the number of columns
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    if ((read = getline(&line, &len, fp)) == -1) {
        fclose(fp);
        return NULL;
    }

    // Split the first line into columns
    char **cols = NULL;
    int num_cols = 0;
    char *col = strtok(line, ",");
    while (col != NULL) {
        cols = realloc(cols, (num_cols + 1) * sizeof(char *));
        cols[num_cols++] = strdup(col);
        col = strtok(NULL, ",");
    }

    // Read the remaining lines and add them to the rows
    csv_t *csv = malloc(sizeof(csv_t));
    csv->data = malloc(num_cols * sizeof(char *));
    for (int i = 0; i < num_cols; i++) {
        csv->data[i] = malloc(strlen(cols[i]) + 1);
        strcpy(csv->data[i], cols[i]);
    }
    csv->num_rows = 1;
    csv->num_cols = num_cols;
    free(cols);

    while ((read = getline(&line, &len, fp)) != -1) {
        // Split the line into columns
        cols = NULL;
        num_cols = 0;
        col = strtok(line, ",");
        while (col != NULL) {
            cols = realloc(cols, (num_cols + 1) * sizeof(char *));
            cols[num_cols++] = strdup(col);
            col = strtok(NULL, ",");
        }

        // Add the columns to the rows
        csv->data = realloc(csv->data, (csv->num_rows + 1) * sizeof(char *));
        csv->data[csv->num_rows] = malloc(num_cols * sizeof(char *));
        for (int i = 0; i < num_cols; i++) {
            csv->data[csv->num_rows][i] = malloc(strlen(cols[i]) + 1);
            strcpy(csv->data[csv->num_rows][i], cols[i]);
        }
        csv->num_rows++;
        free(cols);
    }

    fclose(fp);
    return csv;
}

void csv_free(csv_t *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            free(csv->data[i][j]);
        }
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    csv_t *csv = csv_read("data.csv");
    if (csv == NULL) {
        printf("Error reading CSV file\n");
        return 1;
    }

    printf("Number of rows: %d\n", csv->num_rows);
    printf("Number of columns: %d\n", csv->num_cols);

    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            printf("%s", csv->data[i][j]);
            if (j < csv->num_cols - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }

    csv_free(csv);

    return 0;
}