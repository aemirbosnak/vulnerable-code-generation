//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_COLS 20

typedef struct CSV_DATA {
    char **data;
    int num_rows;
    int num_cols;
} CSV_DATA;

CSV_DATA *read_csv(char *filename) {
    CSV_DATA *csv_data = malloc(sizeof(CSV_DATA));
    csv_data->data = NULL;
    csv_data->num_rows = 0;
    csv_data->num_cols = 0;

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    // Read the number of rows and columns
    char line[MAX_LINES];
    int num_rows = 0;
    while (fgets(line, MAX_LINES, fp) != NULL) {
        num_rows++;
    }

    csv_data->num_rows = num_rows;

    // Allocate memory for the data
    csv_data->data = malloc(num_rows * MAX_COLS * sizeof(char *));
    for (int r = 0; r < num_rows; r++) {
        csv_data->data[r] = malloc(MAX_COLS * sizeof(char *));
    }

    // Read the data from the file
    rewind(fp);
    int num_cols = 0;
    while (fgets(line, MAX_LINES, fp) != NULL) {
        char **cols = csv_data->data[num_rows - 1];
        char *ptr = strtok(line, ",");
        while (ptr) {
            cols[num_cols++] = strdup(ptr);
            ptr = strtok(NULL, ",");
        }
    }

    csv_data->num_cols = num_cols;

    fclose(fp);

    return csv_data;
}

int main() {
    char *filename = "test.csv";
    CSV_DATA *csv_data = read_csv(filename);

    if (csv_data) {
        printf("Number of rows: %d\n", csv_data->num_rows);
        printf("Number of columns: %d\n", csv_data->num_cols);
        printf("Data:\n");
        for (int r = 0; r < csv_data->num_rows; r++) {
            for (int c = 0; c < csv_data->num_cols; c++) {
                printf("%s ", csv_data->data[r][c]);
            }
            printf("\n");
        }
    } else {
        printf("Error reading CSV file.\n");
    }

    return 0;
}