//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of columns and rows in the CSV file
#define MAX_COLUMNS 100
#define MAX_ROWS 1000

// Define the data structure to hold the CSV data
typedef struct {
    char *data[MAX_COLUMNS];
    int num_columns;
    int num_rows;
} csv_data;

// Function to read a CSV file and store the data in a csv_data struct
csv_data *read_csv_file(char *filename) {
    // Open the CSV file for reading
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    // Allocate memory for the csv_data struct
    csv_data *data = malloc(sizeof(csv_data));
    if (data == NULL) {
        fprintf(stderr, "Error allocating memory for csv_data struct\n");
        fclose(file);
        return NULL;
    }

    // Initialize the csv_data struct
    data->num_columns = 0;
    data->num_rows = 0;

    // Read the header line from the CSV file
    char line[1024];
    if (fgets(line, sizeof(line), file) == NULL) {
        fprintf(stderr, "Error reading header line from file %s\n", filename);
        fclose(file);
        free(data);
        return NULL;
    }

    // Tokenize the header line and store the column names in the csv_data struct
    char *token = strtok(line, ",");
    while (token != NULL) {
        data->data[data->num_columns] = strdup(token);
        data->num_columns++;
        token = strtok(NULL, ",");
    }

    // Read the data lines from the CSV file
    while (fgets(line, sizeof(line), file) != NULL) {
        // Tokenize the data line and store the data values in the csv_data struct
        token = strtok(line, ",");
        int col = 0;
        while (token != NULL) {
            data->data[col][data->num_rows] = strdup(token);
            col++;
            token = strtok(NULL, ",");
        }
        data->num_rows++;
    }

    // Close the CSV file
    fclose(file);

    // Return the csv_data struct
    return data;
}

// Function to print the data in a csv_data struct
void print_csv_data(csv_data *data) {
    // Print the header line
    for (int i = 0; i < data->num_columns; i++) {
        printf("%s,", data->data[i]);
    }
    printf("\n");

    // Print the data lines
    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_columns; j++) {
            printf("%s,", data->data[j][i]);
        }
        printf("\n");
    }
}

// Function to free the memory allocated for a csv_data struct
void free_csv_data(csv_data *data) {
    // Free the memory allocated for the data values
    for (int i = 0; i < data->num_columns; i++) {
        for (int j = 0; j < data->num_rows; j++) {
            free(data->data[i][j]);
        }
    }

    // Free the memory allocated for the column names
    for (int i = 0; i < data->num_columns; i++) {
        free(data->data[i]);
    }

    // Free the memory allocated for the csv_data struct
    free(data);
}

// Main function
int main() {
    // Read the CSV file
    csv_data *data = read_csv_file("data.csv");
    if (data == NULL) {
        return 1;
    }

    // Print the data in the CSV file
    print_csv_data(data);

    // Free the memory allocated for the CSV data
    free_csv_data(data);

    return 0;
}