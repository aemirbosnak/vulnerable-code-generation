//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMPLOYEES 100

typedef struct Employee {
    char name[MAX_NAME_LENGTH];
    int id;
    int numSubordinates;
    struct Employee* subordinates[MAX_EMPLOYEES]; // Array of pointers to subordinates
} Employee;

Employee* createEmployee(const char* name, int id) {
    Employee* emp = (Employee*)malloc(sizeof(Employee));
    strncpy(emp->name, name, MAX_NAME_LENGTH);
    emp->id = id;
    emp->numSubordinates = 0;
    return emp;
}

void addSubordinate(Employee* manager, Employee* subordinate) {
    if (manager->numSubordinates < MAX_EMPLOYEES) {
        manager->subordinates[manager->numSubordinates++] = subordinate;
    } else {
        printf("Error: Max subordinate limit reached for employee %s\n", manager->name);
    }
}

void printEmployee(Employee* emp, int level) {
    if (emp == NULL) return;

    for (int i = 0; i < level; i++) {
        printf("\t");
    }
    printf("ID: %d, Name: %s\n", emp->id, emp->name);
    
    for (int i = 0; i < emp->numSubordinates; i++) {
        printEmployee(emp->subordinates[i], level + 1);
    }
}

void freeEmployee(Employee* emp) {
    if (emp == NULL) return;

    for (int i = 0; i < emp->numSubordinates; i++) {
        freeEmployee(emp->subordinates[i]);
    }
    free(emp);
}

int countEmployees(Employee* emp) {
    if (emp == NULL) return 0;

    int count = 1; // Counting the current employee
    for (int i = 0; i < emp->numSubordinates; i++) {
        count += countEmployees(emp->subordinates[i]);
    }
    return count;
}

int main() {
    Employee* ceo = createEmployee("John Doe", 1);
    Employee* manager1 = createEmployee("Jane Smith", 2);
    Employee* manager2 = createEmployee("Michael Johnson", 3);
    
    Employee* emp1 = createEmployee("Sara Connor", 4);
    Employee* emp2 = createEmployee("Kyle Reese", 5);
    Employee* emp3 = createEmployee("Wade Wilson", 6);
    
    addSubordinate(ceo, manager1);
    addSubordinate(ceo, manager2);
    
    addSubordinate(manager1, emp1);
    addSubordinate(manager1, emp2);
    addSubordinate(manager2, emp3);
    
    printf("Employee Hierarchy:\n");
    printEmployee(ceo, 0);
    
    int totalEmployees = countEmployees(ceo);
    printf("\nTotal Number of Employees: %d\n", totalEmployees);
    
    freeEmployee(ceo); // Free all allocated memory
    return 0;
}