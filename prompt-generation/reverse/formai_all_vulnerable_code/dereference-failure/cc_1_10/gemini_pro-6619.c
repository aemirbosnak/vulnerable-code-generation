//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define a custom data structure to store employee information
typedef struct employee {
    char* name;
    int age;
    double salary;
} employee_t;

// Create a function to allocate memory for an employee struct
employee_t* create_employee(char* name, int age, double salary) {
    // Allocate memory for the employee struct
    employee_t* employee = (employee_t*) malloc(sizeof(employee_t));

    // Check if the memory allocation was successful
    if (employee == NULL) {
        perror("malloc() failed");
        return NULL;
    }

    // Initialize the employee struct with the given values
    employee->name = name;
    employee->age = age;
    employee->salary = salary;

    // Return the employee struct
    return employee;
}

// Create a function to free the memory allocated for an employee struct
void destroy_employee(employee_t* employee) {
    // Free the memory allocated for the employee's name
    free(employee->name);

    // Free the memory allocated for the employee struct
    free(employee);
}

// Create a function to print the information of an employee
void print_employee(employee_t* employee) {
    // Print the employee's information
    printf("Name: %s\n", employee->name);
    printf("Age: %d\n", employee->age);
    printf("Salary: %.2f\n", employee->salary);
}

// Main function
int main() {
    // Create an array of employee structs
    employee_t* employees[3];

    // Create an employee struct for each employee
    employees[0] = create_employee("John Doe", 30, 50000.0);
    employees[1] = create_employee("Jane Smith", 25, 40000.0);
    employees[2] = create_employee("Peter Jones", 40, 60000.0);

    // Print the information of each employee
    for (int i = 0; i < 3; i++) {
        print_employee(employees[i]);
    }

    // Free the memory allocated for each employee struct
    for (int i = 0; i < 3; i++) {
        destroy_employee(employees[i]);
    }

    return 0;
}