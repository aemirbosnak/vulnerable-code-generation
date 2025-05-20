//GEMINI-pro DATASET v1.0 Category: File handling ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Custom data structure to store employee information
typedef struct employee {
    int id;
    char name[50];
    int age;
    float salary;
} Employee;

// Function to read employee data from a file
void readEmployees(char *filename, Employee *employees, int *num_employees) {
    // Open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Read the number of employees
    fscanf(fp, "%d", num_employees);

    // Allocate memory for the employees
    employees = malloc(*num_employees * sizeof(Employee));

    // Read each employee's data
    for (int i = 0; i < *num_employees; i++) {
        fscanf(fp, "%d %s %d %f", &employees[i].id, employees[i].name, &employees[i].age, &employees[i].salary);
    }

    // Close the file
    fclose(fp);
}

// Function to write employee data to a file
void writeEmployees(char *filename, const Employee *employees, int num_employees) {
    // Open the file
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Write the number of employees
    fprintf(fp, "%d\n", num_employees);

    // Write each employee's data
    for (int i = 0; i < num_employees; i++) {
        fprintf(fp, "%d %s %d %f\n", employees[i].id, employees[i].name, employees[i].age, employees[i].salary);
    }

    // Close the file
    fclose(fp);
}

// Function to print employee data
void printEmployees(const Employee *employees, int num_employees) {
    for (int i = 0; i < num_employees; i++) {
        printf("ID: %d\n", employees[i].id);
        printf("Name: %s\n", employees[i].name);
        printf("Age: %d\n", employees[i].age);
        printf("Salary: %.2f\n\n", employees[i].salary);
    }
}

int main() {
    // Input file name
    char *input_filename = "employees.txt";

    // Output file name
    char *output_filename = "employees_out.txt";

    // Read employee data from input file
    Employee *employees;
    int num_employees;
    readEmployees(input_filename, employees, &num_employees);

    // Print employee data
    printf("Employees:\n");
    printEmployees(employees, num_employees);

    // Write employee data to output file
    writeEmployees(output_filename, employees, num_employees);

    // Free the allocated memory
    free(employees);

    return 0;
}