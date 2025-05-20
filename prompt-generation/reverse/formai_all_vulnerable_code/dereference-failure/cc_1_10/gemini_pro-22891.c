//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CSV_LINES 1024
#define MAX_CSV_COLUMNS 128

typedef struct {
    char **data;
    int num_lines;
    int num_columns;
} csv_t;

csv_t *csv_read(const char *filename)
{
    // Open the CSV file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    // Allocate memory for the CSV data
    csv_t *csv = (csv_t *)malloc(sizeof(csv_t));
    if (csv == NULL) {
        fprintf(stderr, "Error: could not allocate memory for CSV data\n");
        fclose(fp);
        return NULL;
    }

    // Read the CSV data line by line
    char line[1024];
    int num_lines = 0;
    int num_columns = 0;
    while (fgets(line, sizeof(line), fp)) {
        // Count the number of columns in the line
        int num_cols = 0;
        char *token = strtok(line, ",");
        while (token != NULL) {
            num_cols++;
            token = strtok(NULL, ",");
        }

        // Allocate memory for the data in the line
        csv->data = (char **)realloc(csv->data, (num_lines + 1) * sizeof(char *));
        if (csv->data == NULL) {
            fprintf(stderr, "Error: could not allocate memory for CSV data\n");
            fclose(fp);
            free(csv);
            return NULL;
        }

        // Store the data in the line
        token = strtok(line, ",");
        int i = 0;
        while (token != NULL) {
            csv->data[num_lines][i++] = strdup(token);
            token = strtok(NULL, ",");
        }

        // Increment the number of lines and columns
        num_lines++;
        num_columns = num_cols;
    }

    // Close the CSV file
    fclose(fp);

    // Set the number of lines and columns in the CSV data
    csv->num_lines = num_lines;
    csv->num_columns = num_columns;

    // Return the CSV data
    return csv;
}

void csv_free(csv_t *csv)
{
    // Free the memory for the CSV data
    for (int i = 0; i < csv->num_lines; i++) {
        for (int j = 0; j < csv->num_columns; j++) {
            free(csv->data[i][j]);
        }
        free(csv->data[i]);
    }
    free(csv->data);

    // Free the memory for the CSV struct
    free(csv);
}

int main(int argc, char *argv[])
{
    // Check if the user has specified a CSV file to read
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Read the CSV file
    csv_t *csv = csv_read(argv[1]);
    if (csv == NULL) {
        return EXIT_FAILURE;
    }

    // Print the CSV data
    for (int i = 0; i < csv->num_lines; i++) {
        for (int j = 0; j < csv->num_columns; j++) {
            printf("%s, ", csv->data[i][j]);
        }
        printf("\n");
    }

    // Free the memory for the CSV data
    csv_free(csv);

    return EXIT_SUCCESS;
}