//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store employee information
struct Employee {
    char name[50];
    int employee_id;
    double salary;
    struct Employee* next;
};

// Function to insert a new employee at the end
void insert_at_end(struct Employee** head, char* name, int id, double salary) {
    struct Employee* new_employee = (struct Employee*)malloc(sizeof(struct Employee));
    strcpy(new_employee->name, name);
    new_employee->employee_id = id;
    new_employee->salary = salary;
    new_employee->next = NULL;

    if (*head == NULL) {
        *head = new_employee;
    } else {
        (*head)->next = new_employee;
    }
}

// Function to search for an employee by ID
struct Employee* search_by_id(struct Employee* head, int id) {
    struct Employee* current = head;
    while (current) {
        if (current->employee_id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    struct Employee* head = NULL;
    insert_at_end(&head, "John Doe", 1, 50000);
    insert_at_end(&head, "Jane Doe", 2, 60000);
    insert_at_end(&head, "Peter Pan", 3, 70000);

    struct Employee* employee = search_by_id(head, 2);
    if (employee) {
        printf("Name: %s\n", employee->name);
        printf("Salary: %.2lf\n", employee->salary);
    } else {
        printf("Employee not found.\n");
    }

    return 0;
}