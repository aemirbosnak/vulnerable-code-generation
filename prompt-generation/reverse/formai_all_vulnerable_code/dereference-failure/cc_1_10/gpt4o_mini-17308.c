//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

void parseCSVLine(char *line, char **fields, int *field_count) {
    char *token;
    *field_count = 0;

    token = strtok(line, ",");
    while (token != NULL && *field_count < MAX_FIELDS) {
        fields[(*field_count)++] = token;
        token = strtok(NULL, ",");
    }
}

void readCSVFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s for reading.\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    char *fields[MAX_FIELDS];
    int field_count;
    
    // Read the file line by line
    while (fgets(line, sizeof(line), file)) {
        // Remove newline character from the end of line
        line[strcspn(line, "\n")] = 0;

        parseCSVLine(line, fields, &field_count);
        
        // Print the parsed fields
        printf("Parsed %d fields:\n", field_count);
        for (int i = 0; i < field_count; i++) {
            printf("Field %d: %s\n", i + 1, fields[i]);
        }
        printf("\n");
    }

    fclose(file);
}

void writeCSVFile(const char *filename, char ***data, int rows, int cols) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s for writing.\n", filename);
        return;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(file, "%s", data[i][j]);
            if (j < cols - 1) {
                fprintf(file, ",");
            }
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

void freeMemory(char ***data, int rows) {
    for (int i = 0; i < rows; i++) {
        free(data[i]);
    }
    free(data);
}

int main() {
    // Define a CSV file name
    const char *input_filename = "input.csv";
    const char *output_filename = "output.csv";

    // Read input CSV file
    printf("Reading from: %s\n", input_filename);
    readCSVFile(input_filename);

    // Prepare data for writing output CSV file
    int rows = 3, cols = 3;
    char ***data = malloc(rows * sizeof(char **));
    for (int i = 0; i < rows; i++) {
        data[i] = malloc(cols * sizeof(char *));
        for (int j = 0; j < cols; j++) {
            data[i][j] = malloc(50 * sizeof(char)); // Allocate space for each field
            sprintf(data[i][j], "Row%d_Col%d", i + 1, j + 1); // Sample data
        }
    }

    // Write output CSV file
    printf("Writing to: %s\n", output_filename);
    writeCSVFile(output_filename, data, rows, cols);

    // Free allocated memory
    freeMemory(data, rows);

    return 0;
}