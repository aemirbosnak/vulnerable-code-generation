//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELDS 100

// Struct to hold a single field
typedef struct {
    char* data;
    int size;
} Field;

// Struct to hold the CSV file and its data
typedef struct {
    FILE* file;
    int num_fields;
    int num_lines;
    Field* fields;
} CSV;

// Function to create a new CSV object
CSV* csv_create() {
    CSV* csv = (CSV*) malloc(sizeof(CSV));
    csv->file = NULL;
    csv->num_fields = 0;
    csv->num_lines = 0;
    csv->fields = (Field*) malloc(MAX_FIELDS * sizeof(Field));
    for (int i = 0; i < MAX_FIELDS; i++) {
        csv->fields[i].data = NULL;
        csv->fields[i].size = 0;
    }
    return csv;
}

// Function to destroy a CSV object and free its memory
void csv_destroy(CSV* csv) {
    if (csv->file!= NULL) {
        fclose(csv->file);
    }
    free(csv->fields);
    free(csv);
}

// Function to read a line from the CSV file and split it into fields
int csv_read_line(CSV* csv) {
    char line[MAX_LINE_SIZE];
    if (fgets(line, MAX_LINE_SIZE, csv->file) == NULL) {
        return 0;
    }
    csv->num_lines++;
    char* token = strtok(line, ",");
    while (token!= NULL) {
        int field_index = csv->num_fields;
        if (field_index >= MAX_FIELDS) {
            printf("Error: Too many fields in line %d\n", csv->num_lines);
            return 0;
        }
        csv->fields[field_index].data = strdup(token);
        csv->fields[field_index].size = strlen(token);
        csv->num_fields++;
        token = strtok(NULL, ",");
    }
    return 1;
}

// Function to print the contents of a field
void csv_print_field(Field* field) {
    printf("%s", field->data);
}

// Function to print the contents of a row
void csv_print_row(CSV* csv, int row_index) {
    for (int i = 0; i < csv->num_fields; i++) {
        csv_print_field(csv->fields + i);
        if (i < csv->num_fields - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

// Function to print the entire CSV file
void csv_print(CSV* csv) {
    for (int i = 0; i < csv->num_lines; i++) {
        csv_print_row(csv, i);
    }
}

// Main function to read a CSV file and print its contents
int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }
    CSV* csv = csv_create();
    csv->file = fopen(argv[1], "r");
    if (csv->file == NULL) {
        printf("Error: Could not open file '%s'\n", argv[1]);
        csv_destroy(csv);
        return 1;
    }
    while (csv_read_line(csv)) {
        // Do nothing
    }
    csv_print(csv);
    csv_destroy(csv);
    return 0;
}