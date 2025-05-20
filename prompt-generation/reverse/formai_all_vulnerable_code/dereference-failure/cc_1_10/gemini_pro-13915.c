//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a CSV record
typedef struct {
    char** fields;
    int num_fields;
} csv_record;

// Function to read a CSV file and return an array of records
csv_record* read_csv(const char* filename) {
    // Open the file
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Allocate memory for the records
    csv_record* records = malloc(sizeof(csv_record));
    records->fields = NULL;
    records->num_fields = 0;

    // Read the file line by line
    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        // Allocate memory for the fields
        records->fields = realloc(records->fields, sizeof(char*) * (records->num_fields + 1));

        // Parse the line into fields
        char* field = strtok(line, ",");
        while (field) {
            // Allocate memory for the field
            records->fields[records->num_fields] = malloc(strlen(field) + 1);

            // Copy the field into the array
            strcpy(records->fields[records->num_fields], field);

            // Increment the number of fields
            records->num_fields++;

            // Get the next field
            field = strtok(NULL, ",");
        }
    }

    // Close the file
    fclose(fp);

    // Return the records
    return records;
}

// Function to free the memory allocated for the records
void free_csv(csv_record* records) {
    // Free the fields
    for (int i = 0; i < records->num_fields; i++) {
        free(records->fields[i]);
    }

    // Free the records
    free(records->fields);
    free(records);
}

// Function to print the records
void print_csv(csv_record* records) {
    // Print the records
    for (int i = 0; i < records->num_fields; i++) {
        for (int j = 0; j < records->num_fields; j++) {
            printf("%s ", records->fields[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Read the CSV file
    csv_record* records = read_csv("data.csv");

    // Print the records
    print_csv(records);

    // Free the memory allocated for the records
    free_csv(records);

    return 0;
}