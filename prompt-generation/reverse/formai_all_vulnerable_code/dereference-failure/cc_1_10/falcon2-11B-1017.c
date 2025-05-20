//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <pthread.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
    double salary;
} Employee;

Employee* createEmployee(char name[], int age, double salary) {
    Employee* emp = (Employee*)malloc(sizeof(Employee));
    strcpy(emp->name, name);
    emp->age = age;
    emp->salary = salary;
    return emp;
}

void printEmployee(Employee* emp) {
    printf("Name: %s\n", emp->name);
    printf("Age: %d\n", emp->age);
    printf("Salary: %f\n", emp->salary);
}

void sortEmployees(Employee* employees, int numEmployees) {
    for (int i = 0; i < numEmployees; i++) {
        for (int j = i + 1; j < numEmployees; j++) {
            if (employees[i].salary < employees[j].salary) {
                Employee temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }
}

void* threadFunction(void* arg) {
    Employee* employee = (Employee*)arg;
    printf("Name: %s\n", employee->name);
    printf("Age: %d\n", employee->age);
    printf("Salary: %f\n", employee->salary);
    return NULL;
}

int main() {
    Employee* employees[MAX_SIZE];
    int numEmployees = 0;
    pthread_t threads[MAX_SIZE];

    // Create employees
    char names[MAX_SIZE][MAX_SIZE] = {"John", "Jane", "Bob"};
    int ages[MAX_SIZE] = {30, 25, 35};
    double salaries[MAX_SIZE] = {50000.0, 60000.0, 70000.0};
    for (int i = 0; i < MAX_SIZE; i++) {
        employees[i] = createEmployee(names[i], ages[i], salaries[i]);
        numEmployees++;
    }

    // Sort employees
    sortEmployees(employees, numEmployees);

    // Print sorted employees
    for (int i = 0; i < numEmployees; i++) {
        printEmployee(employees[i]);
    }

    // Start multithreading
    for (int i = 0; i < numEmployees; i++) {
        pthread_create(&threads[i], NULL, threadFunction, (void*)employees[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < numEmployees; i++) {
        pthread_join(threads[i], NULL);
    }

    // Free memory
    for (int i = 0; i < numEmployees; i++) {
        free(employees[i]);
    }

    return 0;
}