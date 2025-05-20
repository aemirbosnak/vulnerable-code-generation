//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CSV file is assumed to have 3 columns
#define NUM_COLUMNS 3

// struct representing a row in the CSV file
typedef struct {
    char* column1;
    char* column2;
    char* column3;
} CSVRow;

// function to parse a CSV row from a string
CSVRow* parse_csv_row(char* str) {
    // allocate memory for CSVRow struct
    CSVRow* row = malloc(sizeof(CSVRow));
    if (row == NULL) {
        fprintf(stderr, "Error: failed to allocate memory for CSVRow\n");
        exit(1);
    }

    // use strtok to parse the CSV row string
    char* token;
    token = strtok(str, ",");
    if (token == NULL) {
        fprintf(stderr, "Error: CSV row is empty\n");
        exit(1);
    }
    row->column1 = strdup(token);

    token = strtok(NULL, ",");
    if (token == NULL) {
        fprintf(stderr, "Error: CSV row has fewer than %d columns\n", NUM_COLUMNS);
        exit(1);
    }
    row->column2 = strdup(token);

    token = strtok(NULL, ",");
    if (token == NULL) {
        fprintf(stderr, "Error: CSV row has fewer than %d columns\n", NUM_COLUMNS);
        exit(1);
    }
    row->column3 = strdup(token);

    // return the parsed CSV row
    return row;
}

int main() {
    // open the CSV file
    FILE* csv_file = fopen("example.csv", "r");
    if (csv_file == NULL) {
        fprintf(stderr, "Error: failed to open CSV file\n");
        exit(1);
    }

    // read the CSV file line by line
    char line[1024];
    while (fgets(line, 1024, csv_file)) {
        // remove the newline character at the end of the line
        char* newline_pos = strchr(line, '\n');
        if (newline_pos) {
            *newline_pos = '\0';
        }

        // parse the CSV row from the line
        CSVRow* row = parse_csv_row(line);

        // print the CSV row
        printf("Column 1: %s\n", row->column1);
        printf("Column 2: %s\n", row->column2);
        printf("Column 3: %s\n\n", row->column3);

        // free the memory allocated for the CSV row
        free(row->column1);
        free(row->column2);
        free(row->column3);
        free(row);
    }

    // close the CSV file
    fclose(csv_file);

    return 0;
}