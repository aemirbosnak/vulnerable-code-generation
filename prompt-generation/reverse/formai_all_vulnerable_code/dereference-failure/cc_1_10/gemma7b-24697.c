//Gemma-7B DATASET v1.0 Category: Database querying ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Employee {
    char name[MAX_SIZE];
    int id;
    double salary;
    struct Employee* next;
} Employee;

Employee* insertEmployee(Employee* head, char* name, int id, double salary) {
    Employee* newEmployee = (Employee*)malloc(sizeof(Employee));
    strcpy(newEmployee->name, name);
    newEmployee->id = id;
    newEmployee->salary = salary;
    newEmployee->next = NULL;

    if (head == NULL) {
        head = newEmployee;
    } else {
        head->next = newEmployee;
    }

    return head;
}

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

void printEmployees(Employee* head) {
    Employee* currentEmployee = head;

    while (currentEmployee) {
        printf("%s (ID: %d), Salary: %.2lf\n", currentEmployee->name, currentEmployee->id, currentEmployee->salary);
        currentEmployee = currentEmployee->next;
    }
}

int main() {
    Employee* head = NULL;

    insertEmployee(head, "John Doe", 1, 50000);
    insertEmployee(head, "Jane Doe", 2, 60000);
    insertEmployee(head, "Peter Pan", 3, 70000);

    printEmployees(head);

    Employee* employee = searchEmployee(head, 2);

    if (employee) {
        printf("Employee found: %s (ID: %d), Salary: %.2lf\n", employee->name, employee->id, employee->salary);
    } else {
        printf("Employee not found.\n");
    }

    return 0;
}