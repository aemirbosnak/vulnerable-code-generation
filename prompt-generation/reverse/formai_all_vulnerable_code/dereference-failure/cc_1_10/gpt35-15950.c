//FormAI DATASET v1.0 Category: Database querying ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Employee structure definition
typedef struct Employee {
    int id;
    char name[50];
    int age;
    float salary;
} Employee;

// Function declaration
void printEmployee(Employee e);
int compareByAge(const void *a, const void *b);
int compareByName(const void *a, const void *b);
Employee* getBySalary(Employee* employees, int size, float salary);
Employee* getByAgeRange(Employee* employees, int size, int startAge, int endAge);
Employee* getByNameStartsWith(Employee* employees, int size, char letter);

int main() {
    // Employee array
    Employee employees[] = {
        {1, "John", 25, 35000.00},
        {2, "Jane", 30, 42000.00},
        {3, "Bob", 28, 38000.00},
        {4, "Sarah", 35, 52000.00},
        {5, "Tom", 32, 45000.00},
        {6, "Emma", 27, 40000.00},
        {7, "Alex", 29, 39000.00},
        {8, "Oliver", 31, 47000.00},
        {9, "Lucy", 26, 36000.00},
        {10, "Harry", 33, 50000.00}
    };
    int size = sizeof(employees) / sizeof(Employee);

    // Query by salary
    printf("Query by salary:\n");
    Employee* resultBySalary = getBySalary(employees, size, 42000.00);
    for(int i = 0; i < size; i++) {
        if(resultBySalary[i].id != -1) {
            printEmployee(resultBySalary[i]);
        }
    }
    free(resultBySalary);
    printf("\n");

    // Query by age range
    printf("Query by age range:\n");
    Employee* resultByAgeRange = getByAgeRange(employees, size, 27, 31);
    for(int i = 0; i < size; i++) {
        if(resultByAgeRange[i].id != -1) {
            printEmployee(resultByAgeRange[i]);
        }
    }
    free(resultByAgeRange);
    printf("\n");

    // Query by name starts with
    printf("Query by name starts with:\n");
    Employee* resultByNameStartsWith = getByNameStartsWith(employees, size, 'J');
    for(int i = 0; i < size; i++) {
        if(resultByNameStartsWith[i].id != -1) {
            printEmployee(resultByNameStartsWith[i]);
        }
    }
    free(resultByNameStartsWith);

    return 0;
}

// Function to print an employee's information
void printEmployee(Employee e) {
    printf("ID: %d, Name: %s, Age: %d, Salary: %.2f\n", e.id, e.name, e.age, e.salary);
}

// Age comparator function for qsort
int compareByAge(const void *a, const void *b) {
    const Employee *e1 = a, *e2 = b;
    if(e1->age < e2->age) return -1;
    if(e1->age > e2->age) return 1;
    return 0;
}

// Name comparator function for qsort
int compareByName(const void *a, const void *b) {
    const Employee *e1 = a, *e2 = b;
    return strcmp(e1->name, e2->name);
}

// Query employees by salary
Employee* getBySalary(Employee* employees, int size, float salary) {
    Employee* result = (Employee*) calloc(size, sizeof(Employee));
    int resultIndex = 0;
    for(int i = 0; i < size; i++) {
        if(employees[i].salary == salary) {
            result[resultIndex++] = employees[i];
        }
    }
    return result;
}

// Query employees by age range
Employee* getByAgeRange(Employee* employees, int size, int startAge, int endAge) {
    Employee* result = (Employee*) calloc(size, sizeof(Employee));
    int resultIndex = 0;
    for(int i = 0; i < size; i++) {
        if(employees[i].age >= startAge && employees[i].age <= endAge) {
            result[resultIndex++] = employees[i];
        }
    }
    return result;
}

// Query employees by name starts with
Employee* getByNameStartsWith(Employee* employees, int size, char letter) {
    qsort(employees, size, sizeof(Employee), compareByName);
    Employee* result = (Employee*) calloc(size, sizeof(Employee));
    int resultIndex = 0, lastIndex = 0;
    while(lastIndex < size && employees[lastIndex].name[0] < letter) lastIndex++;
    for(int i = lastIndex; i < size; i++) {
        if(employees[i].name[0] == letter) {
            result[resultIndex++] = employees[i];
        } else {
            break;
        }
    }
    return result;
}