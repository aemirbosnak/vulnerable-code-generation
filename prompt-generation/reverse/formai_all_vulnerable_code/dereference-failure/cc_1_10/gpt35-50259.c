//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// struct to represent a single row of data
typedef struct {
    char** columns;
    size_t num_columns;
} CSVRow;

// function to free memory used by CSVRow
void free_csv_row(CSVRow* row) {
    for (size_t i = 0; i < row->num_columns; i++) {
        free(row->columns[i]);
    }
    free(row->columns);
    free(row);
}

// function to read and parse a single row from a CSV file
CSVRow* read_csv_row(FILE* file) {
    char line[MAX_LINE_LENGTH];
    if (!fgets(line, MAX_LINE_LENGTH, file)) {
        return NULL;
    }
    size_t num_columns = 1;
    for (size_t i = 0; i < strlen(line); i++) {
        if (line[i] == ',') {
            num_columns++;
        }
    }
    CSVRow* row = malloc(sizeof(CSVRow));
    row->columns = malloc(sizeof(char*) * num_columns);
    row->num_columns = num_columns;
    char* token = strtok(line, ",");
    size_t i = 0;
    while (token != NULL) {
        row->columns[i] = strdup(token);
        i++;
        token = strtok(NULL, ",");
    }
    return row;
}

// function to print a single CSVRow
void print_csv_row(CSVRow* row) {
    for (size_t i = 0; i < row->num_columns; i++) {
        printf("%s", row->columns[i]);
        if (i < row->num_columns - 1) {
            printf(",");
        }
    }
    printf("\n");
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: csvreader <filename>\n");
        return 1;
    }
    char* filename = argv[1];
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s\n", filename);
        return 1;
    }
    CSVRow* row = read_csv_row(file); // ignore the first row (header)
    free_csv_row(row);
    while ((row = read_csv_row(file))) { // read and print all other rows
        print_csv_row(row);
        free_csv_row(row);
    }
    fclose(file);
    return 0;
}