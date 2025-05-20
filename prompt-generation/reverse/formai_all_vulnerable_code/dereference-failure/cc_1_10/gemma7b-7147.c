//Gemma-7B DATASET v1.0 Category: Database querying ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Employee {
    char name[50];
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

void searchEmployee(Employee* head, char* name) {
    Employee* currentEmployee = head;

    while (currentEmployee) {
        if (strcmp(currentEmployee->name, name) == 0) {
            printf("Name: %s\n", currentEmployee->name);
            printf("ID: %d\n", currentEmployee->id);
            printf("Salary: %.2lf\n", currentEmployee->salary);
            return;
        }

        currentEmployee = currentEmployee->next;
    }

    printf("Employee not found.\n");
}

int main() {
    Employee* head = NULL;

    insertEmployee(head, "John Doe", 1, 50000);
    insertEmployee(head, "Jane Doe", 2, 60000);
    insertEmployee(head, "Peter Pan", 3, 70000);

    searchEmployee(head, "Jane Doe");

    return 0;
}