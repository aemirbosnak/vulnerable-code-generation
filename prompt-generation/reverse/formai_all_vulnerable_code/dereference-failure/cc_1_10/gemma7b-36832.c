//Gemma-7B DATASET v1.0 Category: Database querying ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Employee {
    char name[MAX_SIZE];
    int id;
    struct Employee* next;
} Employee;

Employee* insertEmployee(Employee* head, char* name, int id) {
    Employee* newEmployee = (Employee*)malloc(sizeof(Employee));
    strcpy(newEmployee->name, name);
    newEmployee->id = id;
    newEmployee->next = NULL;

    if (head == NULL) {
        head = newEmployee;
    } else {
        Employee* tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = newEmployee;
    }

    return head;
}

Employee* searchEmployee(Employee* head, int id) {
    Employee* current = head;
    while (current) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

int main() {
    Employee* head = NULL;

    insertEmployee(head, "John Doe", 1);
    insertEmployee(head, "Jane Doe", 2);
    insertEmployee(head, "Peter Pan", 3);

    Employee* employee = searchEmployee(head, 2);

    if (employee) {
        printf("Name: %s, ID: %d\n", employee->name, employee->id);
    } else {
        printf("Employee not found.\n");
    }

    return 0;
}