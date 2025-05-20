//Gemma-7B DATASET v1.0 Category: Database querying ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Employee {
    char name[50];
    int id;
    float salary;
    struct Employee* next;
} Employee;

void insertEmployee(Employee** head, char* name, int id, float salary) {
    Employee* newEmployee = (Employee*)malloc(sizeof(Employee));
    strcpy(newEmployee->name, name);
    newEmployee->id = id;
    newEmployee->salary = salary;
    newEmployee->next = NULL;

    if (*head == NULL) {
        *head = newEmployee;
    } else {
        (*head)->next = newEmployee;
    }
}

void searchEmployee(Employee* head, int id) {
    while (head) {
        if (head->id == id) {
            printf("Name: %s\n", head->name);
            printf("ID: %d\n", head->id);
            printf("Salary: %.2f\n", head->salary);
            return;
        }
        head = head->next;
    }
    printf("Employee not found.\n");
}

int main() {
    Employee* head = NULL;

    insertEmployee(&head, "John Doe", 1, 50000);
    insertEmployee(&head, "Jane Doe", 2, 60000);
    insertEmployee(&head, "Peter Pan", 3, 70000);

    searchEmployee(head, 2);

    return 0;
}