//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// Define a struct to hold CSV file data
typedef struct csv_data {
    char **rows;
    int num_rows;
    int num_cols;
} csv_data;

// Function to read a CSV file into a csv_data struct
csv_data read_csv(const char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "r");

    if (!fp) {
        printf("Failed to open file: %s", filename);
        exit(1);
    }

    // Create a csv_data struct
    csv_data data;
    data.num_rows = 0;
    data.num_cols = 0;

    // Allocate memory for the rows and initialize them to NULL
    data.rows = (char **) malloc(MAX_LEN * sizeof(char *));
    for (int i = 0; i < MAX_LEN; i++) {
        data.rows[i] = NULL;
    }

    char line[MAX_LEN];

    // Read the file line by line and store each line in the rows array
    while (fgets(line, MAX_LEN, fp)) {
        // Remove the trailing newline character
        line[strcspn(line, "\n")] = '\0';

        // Tokenize the line and count the number of columns
        char *token = strtok(line, ",");
        int num_cols = 0;
        while (token) {
            num_cols++;
            token = strtok(NULL, ",");
        }

        // If this is the first row, set the number of columns in the csv_data struct
        if (data.num_rows == 0) {
            data.num_cols = num_cols;
        }

        // If the number of columns doesn't match the header, exit with an error
        if (num_cols != data.num_cols) {
            printf("Invalid CSV file: %s", filename);
            exit(1);
        }

        // Allocate memory for the row and copy the line into it
        data.rows[data.num_rows] = (char *) malloc(strlen(line) + 1);
        strcpy(data.rows[data.num_rows], line);

        data.num_rows++;
    }

    // Close the file
    fclose(fp);

    return data;
}

int main() {
    csv_data data = read_csv("example.csv");

    // Print the contents of the CSV file
    for (int i = 0; i < data.num_rows; i++) {
        printf("%s\n", data.rows[i]);
    }

    // Free the memory allocated for the rows
    for (int i = 0; i < MAX_LEN; i++) {
        free(data.rows[i]);
    }

    // Free the memory allocated for the rows array
    free(data.rows);

    return 0;
}