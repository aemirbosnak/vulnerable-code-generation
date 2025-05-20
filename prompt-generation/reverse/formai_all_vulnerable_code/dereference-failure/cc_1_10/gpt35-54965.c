//FormAI DATASET v1.0 Category: File handling ; Style: innovative
/*
 * This program demonstrates file handling in C. It reads a file containing
 * student records in CSV format, calculates the average GPA, and writes the
 * result to a new file in plain text format.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LEN 50

// Define a struct to represent a student record
typedef struct {
    char name[MAX_NAME_LEN];
    int id;
    float gpa;
} record_t;

int main() {
    // Open the input file for reading
    FILE* in_file = fopen("input.csv", "r");
    if (!in_file) {
        fprintf(stderr, "Error: could not open input file\n");
        return EXIT_FAILURE;
    }
    
    // Read the input file and store the records in an array
    record_t records[MAX_RECORDS];
    int num_records = 0;
    char line[1024];
    while (fgets(line, 1024, in_file)) {
        // Parse the CSV line into a record struct
        char* name = strtok(line, ",");
        int id = atoi(strtok(NULL, ","));
        float gpa = atof(strtok(NULL, ","));
        if (!name || !id || !gpa) {
            fprintf(stderr, "Error: invalid input format\n");
            return EXIT_FAILURE;
        }
        
        // Copy the record data into the array
        strncpy(records[num_records].name, name, MAX_NAME_LEN);
        records[num_records].id = id;
        records[num_records].gpa = gpa;
        num_records++;
    }
    fclose(in_file);
    
    // Calculate the average GPA
    float total_gpa = 0;
    for (int i = 0; i < num_records; i++) {
        total_gpa += records[i].gpa;
    }
    float avg_gpa = total_gpa / num_records;
    
    // Open the output file for writing
    FILE* out_file = fopen("output.txt", "w");
    if (!out_file) {
        fprintf(stderr, "Error: could not open output file\n");
        return EXIT_FAILURE;
    }
    
    // Write the calculated average to the output file
    fprintf(out_file, "The class average GPA is %.2f", avg_gpa);
    fclose(out_file);
    
    return EXIT_SUCCESS;
}