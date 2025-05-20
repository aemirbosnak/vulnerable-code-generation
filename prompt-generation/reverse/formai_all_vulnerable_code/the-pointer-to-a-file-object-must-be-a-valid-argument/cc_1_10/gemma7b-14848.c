//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: active
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

    // Open the file
    FILE *fp = fopen(filename, "r");

    // Get the number of rows and columns
    int num_rows = 0;
    int num_cols = 0;
    char line[MAX_LINES];
    while (fgets(line, MAX_LINES, fp) != NULL) {
        num_rows++;
        char *col = strtok(line, ",");
        while (col) {
            num_cols++;
            col = strtok(NULL, ",");
        }
    }

    // Allocate memory for the data
    csv_data->data = malloc(num_rows * num_cols * sizeof(char *));

    // Read the data
    rewind(fp);
    int r = 0;
    while (fgets(line, MAX_LINES, fp) != NULL) {
        char *col = strtok(line, ",");
        int c = 0;
        while (col) {
            csv_data->data[r][c] = col;
            col = strtok(NULL, ",");
            c++;
        }
        r++;
    }

    // Close the file
    fclose(fp);

    // Return the CSV data
    return csv_data;
}

int main() {
    char *filename = "data.csv";
    CSV_DATA *csv_data = read_csv(filename);

    // Print the data
    for (int r = 0; r < csv_data->num_rows; r++) {
        for (int c = 0; c < csv_data->num_cols; c++) {
            printf("%s ", csv_data->data[r][c]);
        }
        printf("\n");
    }

    // Free the memory
    free(csv_data->data);
    free(csv_data);

    return 0;
}