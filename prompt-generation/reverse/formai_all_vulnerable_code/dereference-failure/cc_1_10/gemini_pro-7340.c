//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of employees in the company
#define MAX_EMPLOYEES 100

// Define the structure of an employee
typedef struct employee {
    int id;
    char name[50];
    double salary;
} employee;

// Define the structure of a company
typedef struct company {
    char name[50];
    int num_employees;
    employee employees[MAX_EMPLOYEES];
} company;

// Create a new company
company* create_company(char* name) {
    company* c = malloc(sizeof(company));
    strcpy(c->name, name);
    c->num_employees = 0;
    return c;
}

// Add an employee to a company
void add_employee(company* c, employee* e) {
    c->employees[c->num_employees++] = *e;
}

// Print the details of a company
void print_company(company* c) {
    printf("Company: %s\n", c->name);
    printf("Number of employees: %d\n", c->num_employees);
    for (int i = 0; i < c->num_employees; i++) {
        printf("Employee %d: %s, %.2f\n", c->employees[i].id, c->employees[i].name, c->employees[i].salary);
    }
}

// Find an employee by ID
employee* find_employee(company* c, int id) {
    for (int i = 0; i < c->num_employees; i++) {
        if (c->employees[i].id == id) {
            return &c->employees[i];
        }
    }
    return NULL;
}

// Delete an employee by ID
void delete_employee(company* c, int id) {
    for (int i = 0; i < c->num_employees; i++) {
        if (c->employees[i].id == id) {
            for (int j = i + 1; j < c->num_employees; j++) {
                c->employees[j - 1] = c->employees[j];
            }
            c->num_employees--;
            return;
        }
    }
}

// Update an employee's salary
void update_salary(company* c, int id, double salary) {
    employee* e = find_employee(c, id);
    if (e != NULL) {
        e->salary = salary;
    }
}

// Main function
int main() {
    // Create a new company
    company* c = create_company("Acme Corporation");

    // Add some employees to the company
    employee e1 = {1, "John Smith", 100000.0};
    add_employee(c, &e1);
    employee e2 = {2, "Jane Doe", 50000.0};
    add_employee(c, &e2);

    // Print the details of the company
    print_company(c);

    // Find an employee by ID
    employee* e = find_employee(c, 1);
    if (e != NULL) {
        printf("Employee 1: %s, %.2f\n", e->name, e->salary);
    } else {
        printf("Employee 1 not found\n");
    }

    // Delete an employee by ID
    delete_employee(c, 2);

    // Print the details of the company
    print_company(c);

    // Update an employee's salary
    update_salary(c, 1, 120000.0);

    // Print the details of the company
    print_company(c);

    // Free the memory allocated for the company
    free(c);

    return 0;
}