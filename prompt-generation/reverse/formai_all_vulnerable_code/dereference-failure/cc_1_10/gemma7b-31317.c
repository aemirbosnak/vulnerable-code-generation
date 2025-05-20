//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store employee information
typedef struct Employee {
    char name[20];
    int id;
    float salary;
} Employee;

// Function to insert an employee into the database
int insertEmployee(Employee *employee) {
    // Allocate memory for the employee
    employee = (Employee *)malloc(sizeof(Employee));

    // Get the employee's name, ID, and salary
    printf("Enter employee name: ");
    scanf("%s", employee->name);

    printf("Enter employee ID: ");
    scanf("%d", &employee->id);

    printf("Enter employee salary: ");
    scanf("%f", &employee->salary);

    // Return the employee ID
    return employee->id;
}

// Function to search for an employee in the database
int searchEmployee(Employee *employee, int id) {
    // Iterate over the employees in the database
    for (employee = employee; employee->id != -1; employee++) {
        // Check if the employee ID matches the search ID
        if (employee->id == id) {
            // Print the employee's information
            printf("Employee name: %s\n", employee->name);
            printf("Employee ID: %d\n", employee->id);
            printf("Employee salary: %f\n", employee->salary);
            return 1;
        }
    }

    // Employee not found
    return 0;
}

int main() {
    // Create an employee database
    Employee *employees = NULL;

    // Insert an employee into the database
    int employeeId = insertEmployee(employees);

    // Search for an employee in the database
    searchEmployee(employees, employeeId);

    return 0;
}