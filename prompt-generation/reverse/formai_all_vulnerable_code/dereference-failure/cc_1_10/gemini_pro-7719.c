//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A happy CSV reader! :)

// Assuming the CSV file is well-formed, this function reads a row from the file and returns it as an array of strings.
char **read_csv_row(FILE *fp) {
    char *line = NULL;
    size_t len = 0;
    getline(&line, &len, fp);

    // Split the line into fields.
    char **fields = malloc(sizeof(char *) * 10);
    int num_fields = 0;
    char *field = strtok(line, ",");
    while (field) {
        fields[num_fields++] = field;
        field = strtok(NULL, ",");
    }

    // Return the array of fields.
    return fields;
}

// This function reads all the rows from the CSV file and returns them as a 2D array of strings.
char ***read_csv_file(FILE *fp) {
    // Get the number of rows in the file.
    int num_rows = 0;
    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, fp) != -1) {
        num_rows++;
    }

    // Allocate memory for the 2D array of strings.
    char ***rows = malloc(sizeof(char **) * num_rows);

    // Read the rows from the file.
    fseek(fp, 0, SEEK_SET);
    for (int i = 0; i < num_rows; i++) {
        rows[i] = read_csv_row(fp);
    }

    // Return the 2D array of strings.
    return rows;
}

// This function prints the 2D array of strings to the console.
void print_csv_file(char ***rows, int num_rows) {
    for (int i = 0; i < num_rows; i++) {
        char **row = rows[i];
        int num_fields = 0;
        while (row[num_fields]) {
            printf("%s", row[num_fields++]);
            if (row[num_fields]) {
                printf(",");
            }
        }
        printf("\n");
    }
}

int main() {
    // Open the CSV file.
    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read the CSV file into a 2D array of strings.
    char ***rows = read_csv_file(fp);

    // Get the number of rows in the file.
    int num_rows = 0;
    while (rows[num_rows]) {
        num_rows++;
    }

    // Print the 2D array of strings to the console.
    print_csv_file(rows, num_rows);

    // Free the memory allocated for the 2D array of strings.
    for (int i = 0; i < num_rows; i++) {
        free(rows[i]);
    }
    free(rows);

    // Close the CSV file.
    fclose(fp);

    return EXIT_SUCCESS;
}