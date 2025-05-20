//Gemma-7B DATASET v1.0 Category: Database querying ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUERY_LENGTH 255

typedef struct Employee {
    char name[255];
    int id;
    struct Employee* next;
} Employee;

Employee* insertEmployee(Employee* head, char* name, int id) {
    Employee* newEmployee = malloc(sizeof(Employee));
    strcpy(newEmployee->name, name);
    newEmployee->id = id;
    newEmployee->next = NULL;

    if (head == NULL) {
        head = newEmployee;
    } else {
        head->next = newEmployee;
    }

    return head;
}

Employee* findEmployee(Employee* head, int id) {
    Employee* currentEmployee = head;

    while (currentEmployee) {
        if (currentEmployee->id == id) {
            return currentEmployee;
        }

        currentEmployee = currentEmployee->next;
    }

    return NULL;
}

int main() {
    Employee* head = NULL;

    insertEmployee(head, "John Doe", 1);
    insertEmployee(head, "Jane Doe", 2);
    insertEmployee(head, "Peter Pan", 3);

    Employee* employee = findEmployee(head, 2);

    if (employee) {
        printf("Name: %s\n", employee->name);
        printf("ID: %d\n", employee->id);
    } else {
        printf("Employee not found.\n");
    }

    return 0;
}