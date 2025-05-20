//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 100

// Define the structure for each row in the CSV file
typedef struct {
    char *values[MAX_COLS]; // An array of strings to hold the values in each row
    int num_cols; // The number of columns in the row
} Row;

// Function to read the CSV file and store the data in a 2D array
void read_csv(char *filename, Row **data, int *num_rows) {
    FILE *fp;
    char line[MAX_ROWS];
    char delimiter;
    int row_num = 0;
    int col_num = 0;

    // Open the CSV file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    // Read the first line to determine the delimiter
    fgets(line, MAX_ROWS, fp);
    delimiter = line[0];

    // Allocate memory for the data array and initialize the number of rows
    *data = (Row *) malloc(sizeof(Row) * MAX_ROWS);
    *num_rows = 0;

    // Read each line from the file and store the data in the array
    while (fgets(line, MAX_ROWS, fp)!= NULL) {
        // Split the line into an array of strings based on the delimiter
        char *token;
        int i = 0;
        token = strtok(line, &delimiter);
        while (token!= NULL) {
            (*data)[(*num_rows)].values[i] = strdup(token);
            i++;
            token = strtok(NULL, &delimiter);
        }
        (*data)[(*num_rows)].num_cols = i;
        (*num_rows)++;
    }

    // Close the file
    fclose(fp);
}

// Function to print the data in the 2D array
void print_data(Row *data, int num_rows) {
    int i, j;

    for (i = 0; i < num_rows; i++) {
        for (j = 0; j < data[i].num_cols; j++) {
            printf("%s ", data[i].values[j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    char filename[100];
    Row *data;
    int num_rows;

    // Prompt the user for the filename
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Read the CSV file and store the data in a 2D array
    read_csv(filename, &data, &num_rows);

    // Print the data in the 2D array
    printf("Data:\n");
    print_data(data, num_rows);

    // Free the memory allocated for the data array
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < data[i].num_cols; j++) {
            free(data[i].values[j]);
        }
        free(data[i].values);
    }
    free(data);

    return 0;
}