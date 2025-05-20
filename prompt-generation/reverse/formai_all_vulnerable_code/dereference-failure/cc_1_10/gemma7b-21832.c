//Gemma-7B DATASET v1.0 Category: Database querying ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUERY_SIZE 10

typedef struct Employee {
    char name[50];
    int age;
    double salary;
    struct Employee* next;
} Employee;

Employee* insertEmployee(Employee* head, char* name, int age, double salary) {
    Employee* newEmployee = (Employee*)malloc(sizeof(Employee));
    strcpy(newEmployee->name, name);
    newEmployee->age = age;
    newEmployee->salary = salary;
    newEmployee->next = NULL;

    if (head == NULL) {
        head = newEmployee;
    } else {
        head->next = newEmployee;
    }

    return head;
}

void queryEmployees(Employee* head, char* query) {
    char* keyword = strtok(query, " ");
    char* filter = strtok(NULL, " ");

    while (keyword && filter) {
        if (strcmp(keyword, filter) == 0) {
            printf("%s, %d, %.2lf\n", head->name, head->age, head->salary);
        }

        keyword = strtok(NULL, " ");
        filter = strtok(NULL, " ");
    }
}

int main() {
    Employee* head = NULL;

    insertEmployee(head, "John Doe", 30, 50000);
    insertEmployee(head, "Jane Doe", 25, 60000);
    insertEmployee(head, "Peter Pan", 12, 40000);

    queryEmployees(head, "John Doe 30");

    return 0;
}