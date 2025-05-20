//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Delineate the file's columns
typedef struct {
    char **columns;
    int num_columns;
} CSVRow;

// Prototype our CSV-reading wizardry
CSVRow *read_csv(const char *filename);
void free_csv(CSVRow *row);

int main() {
    // Ready our CSV reader for action!
    CSVRow *data = read_csv("data.csv");

    // Let's peek into the data's treasures
    for (int i = 0; i < data->num_columns; i++) {
        printf("%s", data->columns[i]);
        if (i < data->num_columns - 1) {
            printf(", ");
        }
    }
    printf("\n");

    // Tidy up our CSV playground
    free_csv(data);

    return 0;
}

CSVRow *read_csv(const char *filename) {
    // Open the file for exploration
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    // Initialize our CSV vessel
    CSVRow *row = malloc(sizeof(CSVRow));
    row->columns = NULL;
    row->num_columns = 0;

    // Read the file line by line, savoring each morsel of data
    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, fp) != -1) {
        // Split the line into its constituent columns
        char *column = strtok(line, ",");
        while (column != NULL) {
            // Expand our column array to accommodate the new data
            row->columns = realloc(row->columns, (row->num_columns + 1) * sizeof(char *));
            row->columns[row->num_columns++] = strdup(column);
            column = strtok(NULL, ",");
        }
    }

    // Release the memory allocated for the line
    free(line);

    // Close the file after our reading escapade
    fclose(fp);

    return row;
}

void free_csv(CSVRow *row) {
    // Free each column and the array itself
    for (int i = 0; i < row->num_columns; i++) {
        free(row->columns[i]);
    }
    free(row->columns);
    free(row);
}