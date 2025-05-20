//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold a CSV row
typedef struct csv_row {
    char **fields;
    int num_fields;
} csv_row;

// Structure to hold a CSV file
typedef struct csv_file {
    csv_row *rows;
    int num_rows;
} csv_file;

// Function to read a CSV file
csv_file *read_csv(const char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    // Allocate memory for the CSV file
    csv_file *csv = malloc(sizeof(csv_file));
    if (csv == NULL) {
        fclose(fp);
        return NULL;
    }

    // Read the header line
    char line[1024];
    if (fgets(line, sizeof(line), fp) == NULL) {
        fclose(fp);
        free(csv);
        return NULL;
    }

    // Count the number of fields in the header line
    int num_fields = 0;
    char *field = strtok(line, ",");
    while (field != NULL) {
        num_fields++;
        field = strtok(NULL, ",");
    }

    // Allocate memory for the rows
    csv->rows = malloc(sizeof(csv_row) * num_fields);
    if (csv->rows == NULL) {
        fclose(fp);
        free(csv);
        return NULL;
    }

    // Read the rest of the lines
    int row_index = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Allocate memory for the row
        csv->rows[row_index].fields = malloc(sizeof(char *) * num_fields);
        if (csv->rows[row_index].fields == NULL) {
            fclose(fp);
            free(csv->rows);
            free(csv);
            return NULL;
        }

        // Parse the line
        int field_index = 0;
        field = strtok(line, ",");
        while (field != NULL) {
            // Store the field in the row
            csv->rows[row_index].fields[field_index] = strdup(field);
            if (csv->rows[row_index].fields[field_index] == NULL) {
                fclose(fp);
                for (int i = 0; i < field_index; i++) {
                    free(csv->rows[row_index].fields[i]);
                }
                free(csv->rows[row_index].fields);
                for (int i = 0; i < row_index; i++) {
                    for (int j = 0; j < csv->rows[i].num_fields; j++) {
                        free(csv->rows[i].fields[j]);
                    }
                    free(csv->rows[i].fields);
                }
                free(csv->rows);
                free(csv);
                return NULL;
            }

            field_index++;
            field = strtok(NULL, ",");
        }

        // Store the number of fields in the row
        csv->rows[row_index].num_fields = field_index;

        // Increment the row index
        row_index++;
    }

    // Store the number of rows in the CSV file
    csv->num_rows = row_index;

    // Close the file
    fclose(fp);

    // Return the CSV file
    return csv;
}

// Function to free the memory allocated for a CSV file
void free_csv(csv_file *csv) {
    // Free the memory allocated for the rows
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->rows[i].num_fields; j++) {
            free(csv->rows[i].fields[j]);
        }
        free(csv->rows[i].fields);
    }
    free(csv->rows);

    // Free the memory allocated for the CSV file
    free(csv);
}

// Function to print a CSV file
void print_csv(csv_file *csv) {
    // Print the header line
    for (int i = 0; i < csv->rows[0].num_fields; i++) {
        printf("%s,", csv->rows[0].fields[i]);
    }
    printf("\n");

    // Print the rest of the lines
    for (int i = 1; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->rows[i].num_fields; j++) {
            printf("%s,", csv->rows[i].fields[j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Read the CSV file
    csv_file *csv = read_csv("data.csv");
    if (csv == NULL) {
        printf("Error reading CSV file\n");
        return EXIT_FAILURE;
    }

    // Print the CSV file
    print_csv(csv);

    // Free the memory allocated for the CSV file
    free_csv(csv);

    return EXIT_SUCCESS;
}