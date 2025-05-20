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

    // Open the file
    FILE *fp = fopen(filename, "r");

    // Get the number of rows and columns
    int num_rows = 0;
    int num_cols = 0;
    char line[MAX_LINES];
    while (fgets(line, MAX_LINES, fp) != NULL) {
        char *comma = strchr(line, ',');
        if (comma) {
            num_cols++;
        }
        num_rows++;
    }

    // Allocate memory for the data
    csv_data->data = malloc(num_rows * sizeof(char *) + 1);

    // Read the data from the file
    rewind(fp);
    int i = 0;
    while (fgets(line, MAX_LINES, fp) != NULL) {
        csv_data->data[i] = malloc(num_cols * sizeof(char) + 1);
        char *comma = strchr(line, ',');
        int j = 0;
        while (comma) {
            csv_data->data[i][j] = strdup(comma + 1);
            comma = strchr(comma + 1, ',');
            j++;
        }
        csv_data->data[i][num_cols] = NULL;
        i++;
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
    for (int i = 0; i < csv_data->num_rows; i++) {
        for (int j = 0; j < csv_data->num_cols; j++) {
            printf("%s, ", csv_data->data[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < csv_data->num_rows; i++) {
        for (int j = 0; j < csv_data->num_cols; j++) {
            free(csv_data->data[i][j]);
        }
        free(csv_data->data[i]);
    }
    free(csv_data->data);
    free(csv_data);

    return 0;
}