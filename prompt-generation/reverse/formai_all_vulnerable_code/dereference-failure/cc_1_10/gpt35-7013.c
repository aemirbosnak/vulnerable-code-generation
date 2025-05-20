//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_FIELDS 10

int read_csv(char *filename, char ***data, int *num_rows, int *num_cols) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }

    // Initialize variables
    char buffer[MAX_BUFFER_SIZE];
    int row_count = 0;
    int col_count = 0;
    char **rows = NULL;

    // Read each line of the file
    while (fgets(buffer, MAX_BUFFER_SIZE, fp) != NULL) {
        // Remove newline character
        strtok(buffer, "\n");

        // Parse fields
        char **fields = (char **) malloc(MAX_FIELDS * sizeof(char *));
        if (fields == NULL) {
            return -1;
        }

        int i = 0;
        char *field = strtok(buffer, ",");
        while (field != NULL && i < MAX_FIELDS) {
            fields[i] = (char *) malloc((strlen(field) + 1) * sizeof(char));
            if (fields[i] == NULL) {
                return -1;
            }

            strcpy(fields[i], field);
            i++;
            field = strtok(NULL, ",");
        }

        // Add row to list of rows
        rows = (char **) realloc(rows, (row_count + 1) * sizeof(char *));
        if (rows == NULL) {
            return -1;
        }

        rows[row_count] = (char *) malloc(i * sizeof(char));
        if (rows[row_count] == NULL) {
            return -1;
        }

        memcpy(rows[row_count], fields, i * sizeof(char));
        col_count = i;
        row_count++;

        free(fields);
    }

    *data = rows;
    *num_rows = row_count;
    *num_cols = col_count;

    fclose(fp);
    return 0;
}

int main() {
    char **data;
    int num_rows, num_cols;
    int i, j;

    if (read_csv("data.csv", &data, &num_rows, &num_cols) == -1) {
        printf("Failed to read CSV file.\n");
        return -1;
    }

    // Print data
    for (i = 0; i < num_rows; i++) {
        for (j = 0; j < num_cols; j++) {
            printf("%s ", data[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < num_rows; i++) {
        free(data[i]);
    }
    free(data);

    return 0;
}