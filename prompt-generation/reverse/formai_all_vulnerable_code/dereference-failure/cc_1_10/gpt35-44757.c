//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1000
#define MAX_FIELD_LEN 50

/* Struct to hold the CSV data */
typedef struct {
    char **field;   // Pointer to array of field strings
    int num_fields; // Number of fields in the row
} CSVRow;

/* Function to parse a CSV row */
CSVRow *parse_csv_row(char *line, char *delimiter) {

    // Allocate memory for CSVRow struct
    CSVRow *row = (CSVRow *)malloc(sizeof(CSVRow));

    // Make a temporary copy of the line so that we can modify it
    char *line_copy = (char *)malloc(strlen(line)+1);
    strcpy(line_copy, line);

    // Determine the number of fields by counting delimiters
    row->num_fields = 1;
    for (int i = 0; i < strlen(line_copy); i++) {
        if (line_copy[i] == delimiter[0]) {
            row->num_fields++;
        }
    }

    // Allocate memory for field array
    row->field = (char **)malloc(row->num_fields*sizeof(char *));

    // Loop through each field and assign it to the field array
    char *ptr = strtok(line_copy, delimiter);
    for (int i = 0; i < row->num_fields; i++) {
        row->field[i] = (char *)malloc(MAX_FIELD_LEN*sizeof(char));
        if (ptr == NULL) {
            strcpy(row->field[i], "");
        } else {
            strcpy(row->field[i], ptr);
        }
        ptr = strtok(NULL, delimiter);
    }

    // Free memory for line_copy
    free(line_copy);

    return row;
}

/* Function to free memory allocated for a CSVRow struct */
void free_csv_row(CSVRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        free(row->field[i]);
    }
    free(row->field);
    free(row);
}

/* Function to read a CSV file */
int read_csv_file(char *filename, char *header[], CSVRow ***data, char *delimiter) {

    // Open the file for reading
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }

    // Read the header row
    char header_line[MAX_LINE_LEN];
    fgets(header_line, MAX_LINE_LEN, fp);
    strtok(header_line, "\n"); // Remove newline character if present
    *header = (char *)malloc(strlen(header_line)*sizeof(char));
    strcpy(*header, header_line);

    // Allocate memory for data array
    *data = (CSVRow **)malloc(100*sizeof(CSVRow *)); // Assume no more than 100 rows
    int num_rows = 0;

    // Loop through each line of the file and parse the CSV rows
    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
        strtok(line, "\n"); // Remove newline character if present
        (*data)[num_rows] = parse_csv_row(line, delimiter);
        num_rows++;
    }

    // Close the file
    fclose(fp);

    return num_rows;
}

/* Main function to test CSV reader */
int main() {

    char *filename = "example.csv";
    char *header;
    CSVRow **data;
    int num_rows = read_csv_file(filename, &header, &data, ",");

    // Print header
    printf("Header:\n%s\n\n", header);

    // Print data
    printf("Data:\n");
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < data[i]->num_fields; j++) {
            printf("%s\t", data[i]->field[j]);
        }
        printf("\n");
    }

    // Free memory allocated for header and data
    free(header);
    for (int i = 0; i < num_rows; i++) {
        free_csv_row(data[i]);
    }
    free(data);

    return 0;
}