//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024
#define MAX_FIELDS 10

// Define the structure for storing data from each row
typedef struct {
    char** fields;
    int num_fields;
} CSVRow;

// Define the structure for the CSV file
typedef struct {
    CSVRow* rows;
    int num_rows;
    int max_rows;
} CSVFile;

// Function to split a string into fields based on a delimiter
char** split_string(char* str, char delim, int* num_fields) {
    char** fields = malloc(MAX_FIELDS * sizeof(char*));
    char* token;
    int count = 0;

    token = strtok(str, &delim);
    while (token != NULL && count < MAX_FIELDS) {
        fields[count++] = token;
        token = strtok(NULL, &delim);
    }

    *num_fields = count;
    return fields;
}

// Function to read and parse a CSV file
CSVFile* read_csv_file(char* filename) {
    FILE* fp = fopen(filename, "r");
    char buffer[MAX_BUFFER];
    CSVFile* csv_file = malloc(sizeof(CSVFile));
    csv_file->rows = malloc(MAX_BUFFER * sizeof(CSVRow));
    csv_file->num_rows = 0;
    csv_file->max_rows = MAX_BUFFER;

    while (fgets(buffer, MAX_BUFFER, fp)) {
        if (csv_file->num_rows == csv_file->max_rows) {
            csv_file->max_rows *= 2;
            csv_file->rows = realloc(csv_file->rows, csv_file->max_rows * sizeof(CSVRow));
        }

        CSVRow* row = malloc(sizeof(CSVRow));
        row->fields = split_string(buffer, ',', &row->num_fields);
        csv_file->rows[csv_file->num_rows++] = *row;
    }

    fclose(fp);
    return csv_file;
}

// Function to free memory from a CSV file
void free_csv_file(CSVFile* csv_file) {
    for (int i = 0; i < csv_file->num_rows; i++) {
        free(csv_file->rows[i].fields);
    }
    free(csv_file->rows);
    free(csv_file);
}

// Main function
int main() {
    CSVFile* csv_file = read_csv_file("example.csv");

    // Print the data from each row
    for (int i = 0; i < csv_file->num_rows; i++) {
        printf("Row %d:\n", i+1);
        for (int j = 0; j < csv_file->rows[i].num_fields; j++) {
            printf("  Field %d: %s\n", j+1, csv_file->rows[i].fields[j]);
        }
    }

    free_csv_file(csv_file);
    return 0;
}