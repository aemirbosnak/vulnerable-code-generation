//Falcon-180B DATASET v1.0 Category: Memory management ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int id;
    char name[20];
    int age;
    float salary;
} Employee;

Employee *createEmployee(int id, char *name, int age, float salary) {
    Employee *emp = (Employee *)malloc(sizeof(Employee));
    emp->id = id;
    strcpy(emp->name, name);
    emp->age = age;
    emp->salary = salary;
    return emp;
}

void displayEmployee(Employee emp) {
    printf("ID: %d\n", emp.id);
    printf("Name: %s\n", emp.name);
    printf("Age: %d\n", emp.age);
    printf("Salary: %.2f\n", emp.salary);
}

void deleteEmployee(Employee *emp) {
    free(emp);
}

int main() {
    srand(time(NULL));

    Employee *employees[MAX_SIZE];
    int count = 0;

    while (count < MAX_SIZE) {
        int id = rand() % MAX_SIZE;
        if (id!= 0) {
            char name[20];
            sprintf(name, "Employee %d", id);
            int age = rand() % 50 + 20;
            float salary = rand() % 1000 + 1000;

            employees[id] = createEmployee(id, name, age, salary);
            count++;
        }
    }

    printf("List of employees:\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (employees[i]!= NULL) {
            displayEmployee(*employees[i]);
        }
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        if (employees[i]!= NULL) {
            deleteEmployee(employees[i]);
        }
    }

    return 0;
}