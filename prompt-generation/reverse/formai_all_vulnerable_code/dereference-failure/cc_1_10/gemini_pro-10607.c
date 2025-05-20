//GEMINI-pro DATASET v1.0 Category: File handling ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom data structure to hold a record
typedef struct record {
    int id;
    char name[50];
    float salary;
} record_t;

int main() {
    // Open a file for reading
    FILE *fp = fopen("employees.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read the first line to get the number of records
    int num_records;
    fscanf(fp, "%d\n", &num_records);

    // Allocate memory for the array of records
    record_t *records = malloc(sizeof(record_t) * num_records);
    if (records == NULL) {
        printf("Error allocating memory!\n");
        fclose(fp);
        return 1;
    }

    // Read the remaining lines and store the records in the array
    for (int i = 0; i < num_records; i++) {
        fscanf(fp, "%d %s %f\n", &records[i].id, records[i].name, &records[i].salary);
    }

    // Close the file
    fclose(fp);

    // Find the employee with the highest salary
    int max_salary_index = 0;
    for (int i = 1; i < num_records; i++) {
        if (records[i].salary > records[max_salary_index].salary) {
            max_salary_index = i;
        }
    }

    // Print the employee with the highest salary
    printf("Employee with the highest salary:\n");
    printf("ID: %d\n", records[max_salary_index].id);
    printf("Name: %s\n", records[max_salary_index].name);
    printf("Salary: %.2f\n", records[max_salary_index].salary);

    // Free the allocated memory
    free(records);

    return 0;
}