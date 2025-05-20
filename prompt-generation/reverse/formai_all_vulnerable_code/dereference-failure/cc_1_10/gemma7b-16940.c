//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_ADDRESS_LENGTH 255

typedef struct Employee {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    int salary;
    struct Employee* next;
} Employee;

Employee* createEmployee(char* name, char* address, int salary) {
    Employee* employee = malloc(sizeof(Employee));
    strcpy(employee->name, name);
    strcpy(employee->address, address);
    employee->salary = salary;
    employee->next = NULL;
    return employee;
}

void addToEmployeeList(Employee** head, Employee* newEmployee) {
    if (*head == NULL) {
        *head = newEmployee;
    } else {
        (*head)->next = newEmployee;
        *head = newEmployee;
    }
}

void printEmployeeList(Employee* head) {
    Employee* currentEmployee = head;
    while (currentEmployee) {
        printf("Name: %s\n", currentEmployee->name);
        printf("Address: %s\n", currentEmployee->address);
        printf("Salary: %d\n", currentEmployee->salary);
        printf("\n");
        currentEmployee = currentEmployee->next;
    }
}

int main() {
    Employee* head = NULL;
    addToEmployeeList(&head, createEmployee("John Doe", "123 Main St.", 50000));
    addToEmployeeList(&head, createEmployee("Jane Doe", "456 Oak Ave.", 60000));
    addToEmployeeList(&head, createEmployee("Bob Smith", "789 Park Ave.", 70000));

    printEmployeeList(head);

    return 0;
}