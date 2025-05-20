//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
    float salary;
} Employee;

typedef struct {
    Employee data[MAX_SIZE];
    int size;
} EmployeeList;

EmployeeList *createEmployeeList() {
    EmployeeList *list = (EmployeeList *)malloc(sizeof(EmployeeList));
    if (list == NULL) {
        printf("Error: Out of memory.\n");
        exit(EXIT_FAILURE);
    }
    list->size = 0;
    return list;
}

void destroyEmployeeList(EmployeeList *list) {
    for (int i = 0; i < list->size; i++) {
        free(list->data[i].name);
    }
    free(list);
}

void addEmployee(EmployeeList *list, const char *name, int age, float salary) {
    if (list->size >= MAX_SIZE) {
        printf("Error: List is full.\n");
        return;
    }
    Employee *newEmployee = (Employee *)malloc(sizeof(Employee));
    if (newEmployee == NULL) {
        printf("Error: Out of memory.\n");
        exit(EXIT_FAILURE);
    }
    newEmployee->name = strdup(name);
    newEmployee->age = age;
    newEmployee->salary = salary;
    list->data[list->size++] = *newEmployee;
}

void printEmployeeList(EmployeeList *list) {
    for (int i = 0; i < list->size; i++) {
        printf("%s, %d years old, salary: $%.2f\n", list->data[i].name, list->data[i].age, list->data[i].salary);
    }
}

int main() {
    EmployeeList *list = createEmployeeList();
    addEmployee(list, "John Doe", 30, 50000);
    addEmployee(list, "Jane Smith", 28, 55000);
    printEmployeeList(list);
    destroyEmployeeList(list);
    return 0;
}