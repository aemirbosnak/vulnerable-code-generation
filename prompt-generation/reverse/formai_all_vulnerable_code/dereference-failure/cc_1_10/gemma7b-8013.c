//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the database structure
typedef struct Employee {
    char name[50];
    int id;
    struct Employee* next;
} Employee;

// Function to insert a new employee into the database
Employee* insertEmployee(Employee* head, char* name, int id) {
    Employee* newEmployee = (Employee*)malloc(sizeof(Employee));
    strcpy(newEmployee->name, name);
    newEmployee->id = id;
    newEmployee->next = NULL;

    if (head == NULL) {
        head = newEmployee;
    } else {
        Employee* currentEmployee = head;
        while (currentEmployee->next != NULL) {
            currentEmployee = currentEmployee->next;
        }
        currentEmployee->next = newEmployee;
    }

    return head;
}

// Function to search for an employee in the database
Employee* searchEmployee(Employee* head, int id) {
    Employee* currentEmployee = head;
    while (currentEmployee) {
        if (currentEmployee->id == id) {
            return currentEmployee;
        }
        currentEmployee = currentEmployee->next;
    }

    return NULL;
}

// Function to delete an employee from the database
void deleteEmployee(Employee* head, int id) {
    Employee* previousEmployee = NULL;
    Employee* currentEmployee = head;

    while (currentEmployee) {
        if (currentEmployee->id == id) {
            if (previousEmployee) {
                previousEmployee->next = currentEmployee->next;
            } else {
                head = currentEmployee->next;
            }
            free(currentEmployee);
            return;
        }
        previousEmployee = currentEmployee;
        currentEmployee = currentEmployee->next;
    }

    return;
}

int main() {
    Employee* head = NULL;

    // Insert some employees
    insertEmployee(head, "John Doe", 1);
    insertEmployee(head, "Jane Doe", 2);
    insertEmployee(head, "Peter Pan", 3);

    // Search for an employee
    Employee* employee = searchEmployee(head, 2);
    if (employee) {
        printf("Employee name: %s\n", employee->name);
    }

    // Delete an employee
    deleteEmployee(head, 1);

    // Search for the employee after deletion
    employee = searchEmployee(head, 1);
    if (employee) {
        printf("Employee name: %s\n", employee->name);
    } else {
        printf("Employee not found.\n");
    }

    return 0;
}