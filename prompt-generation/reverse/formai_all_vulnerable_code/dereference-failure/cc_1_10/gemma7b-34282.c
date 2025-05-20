//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Define a structure to store employee information
typedef struct Employee {
    char name[50];
    int employee_id;
    double salary;
    struct Employee* next;
} Employee;

// Function to insert a new employee at the end
void insert_at_end(Employee* head, Employee* new_employee) {
    if (head == NULL) {
        head = new_employee;
    } else {
        head->next = new_employee;
        head = new_employee;
    }
}

// Function to print all employees
void print_employees(Employee* head) {
    Employee* current = head;
    while (current) {
        printf("%s, %d, %.2lf\n", current->name, current->employee_id, current->salary);
        current = current->next;
    }
}

int main() {
    // Create a new employee structure
    Employee* head = NULL;

    // Insert a few employees
    insert_at_end(head, malloc(sizeof(Employee)));
    strcpy(head->name, "John Doe");
    head->employee_id = 1;
    head->salary = 50000;

    insert_at_end(head, malloc(sizeof(Employee)));
    strcpy(head->next->name, "Jane Doe");
    head->next->employee_id = 2;
    head->next->salary = 60000;

    insert_at_end(head, malloc(sizeof(Employee)));
    strcpy(head->next->next->name, "Peter Pan");
    head->next->next->employee_id = 3;
    head->next->next->salary = 70000;

    // Print all employees
    print_employees(head);

    return 0;
}