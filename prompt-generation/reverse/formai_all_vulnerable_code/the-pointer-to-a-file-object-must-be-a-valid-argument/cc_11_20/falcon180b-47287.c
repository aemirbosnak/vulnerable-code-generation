//Falcon-180B DATASET v1.0 Category: Database querying ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} Table;

int main() {
    Table table;
    table.num_rows = 0;
    table.num_cols = 0;
    table.data = NULL;

    // Load data from CSV file
    FILE *fp = fopen("data.csv", "r");
    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        char *token = strtok(line, ",");
        int row = 0;
        while (token!= NULL) {
            if (row >= MAX_ROWS) {
                printf("Error: Too many rows in CSV file.\n");
                exit(1);
            }
            if (table.data[row] == NULL) {
                table.data[row] = malloc(MAX_COLS * sizeof(char*));
            }
            int col = 0;
            while (col < MAX_COLS && table.data[row][col] == NULL) {
                table.data[row][col] = strdup(token);
                col++;
            }
            if (col >= MAX_COLS) {
                printf("Error: Too many columns in CSV file.\n");
                exit(1);
            }
            row++;
            token = strtok(NULL, ",");
        }
        table.num_rows++;
    }
    fclose(fp);

    // Query the data
    int num_results = 0;
    char **results = malloc(MAX_ROWS * sizeof(char*));
    for (int i = 0; i < table.num_rows; i++) {
        for (int j = 0; j < table.num_cols; j++) {
            if (table.data[i][j]!= NULL) {
                if (num_results >= MAX_ROWS) {
                    printf("Error: Too many results for query.\n");
                    exit(1);
                }
                results[num_results] = strdup(table.data[i][j]);
                num_results++;
            }
        }
    }

    // Print the results
    for (int i = 0; i < num_results; i++) {
        printf("%s\n", results[i]);
    }

    // Free memory
    for (int i = 0; i < table.num_rows; i++) {
        for (int j = 0; j < table.num_cols; j++) {
            free(table.data[i][j]);
        }
        free(table.data[i]);
    }
    free(table.data);
    free(results);

    return 0;
}