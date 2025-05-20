//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define a custom data structure to store employee information
typedef struct Employee {
    char *name;
    int age;
    double salary;
} Employee;

// Function to allocate memory for an employee struct and initialize its fields
Employee *createEmployee(char *name, int age, double salary) {
    // Allocate memory for the employee struct
    Employee *employee = (Employee *) malloc(sizeof(Employee));

    // Check if memory allocation was successful
    if (employee == NULL) {
        printf("Error allocating memory for employee struct.\n");
        exit(1);
    }

    // Initialize the employee's fields
    employee->name = (char *) malloc(strlen(name) + 1);
    strcpy(employee->name, name);
    employee->age = age;
    employee->salary = salary;

    // Return the pointer to the employee struct
    return employee;
}

// Function to print the details of an employee
void printEmployee(Employee *employee) {
    printf("Employee Name: %s\n", employee->name);
    printf("Employee Age: %d\n", employee->age);
    printf("Employee Salary: %f\n", employee->salary);
}

// Function to free the memory allocated for an employee struct
void deleteEmployee(Employee *employee) {
    // Free the memory allocated for the employee's name
    free(employee->name);

    // Free the memory allocated for the employee struct
    free(employee);
}

// Main function
int main() {
    // Create an employee struct using the createEmployee() function
    Employee *employee1 = createEmployee("John Doe", 30, 50000.0);

    // Print the details of the employee using the printEmployee() function
    printEmployee(employee1);

    // Free the memory allocated for the employee struct using the deleteEmployee() function
    deleteEmployee(employee1);

    return 0;
}