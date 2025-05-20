//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RECORDS 100
#define MAX_NAME_LEN 20
#define MAX_AGE 100

// Structure to store student records
typedef struct {
    char name[MAX_NAME_LEN];
    int age;
} student_t;

// Function to read student records from a file
student_t* read_records(const char* file_name) {
    // Open the file in read mode
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", file_name);
        return NULL;
    }

    // Create an array to store the student records
    student_t* records = malloc(sizeof(student_t) * MAX_RECORDS);
    if (records == NULL) {
        printf("Error: Could not allocate memory for records\n");
        fclose(file);
        return NULL;
    }

    // Read the student records from the file
    int i = 0;
    while (i < MAX_RECORDS && fscanf(file, "%19s %d", records[i].name, &records[i].age) == 2) {
        i++;
    }

    // Check if all the records were read successfully
    if (i != MAX_RECORDS) {
        printf("Error: Not all records were read successfully\n");
        free(records);
        fclose(file);
        return NULL;
    }

    // Return the array of student records
    return records;
}

// Function to write student records to a file
void write_records(const char* file_name, student_t* records) {
    // Open the file in write mode
    FILE* file = fopen(file_name, "w");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", file_name);
        return;
    }

    // Write the student records to the file
    for (int i = 0; i < MAX_RECORDS; i++) {
        fprintf(file, "%19s %d\n", records[i].name, records[i].age);
    }

    // Close the file
    fclose(file);
}

int main() {
    // Read the student records from a file
    student_t* records = read_records("student_records.txt");
    if (records == NULL) {
        printf("Error: Could not read student records\n");
        return 1;
    }

    // Print the student records
    for (int i = 0; i < MAX_RECORDS; i++) {
        printf("%d. %s (%d years old)\n", i + 1, records[i].name, records[i].age);
    }

    // Write the student records to a new file
    write_records("student_records_new.txt", records);

    // Free the memory allocated for the student records
    free(records);

    return 0;
}