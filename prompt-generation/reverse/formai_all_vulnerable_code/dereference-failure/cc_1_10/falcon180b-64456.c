//Falcon-180B DATASET v1.0 Category: Memory management ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_NUM_EMPLOYEES 100

// Define structures for employee data
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    int employeeID;
} Employee;

typedef struct {
    Employee* data;
    int numEmployees;
    int capacity;
} EmployeeList;

// Function to initialize an empty employee list
void initEmployeeList(EmployeeList* list) {
    list->data = NULL;
    list->numEmployees = 0;
    list->capacity = 0;
}

// Function to add an employee to the list
void addEmployee(EmployeeList* list, const char* name, int age, int employeeID) {
    if (list->numEmployees >= list->capacity) {
        // If the list is full, double its capacity
        list->capacity *= 2;
        Employee* newData = realloc(list->data, list->capacity * sizeof(Employee));
        if (newData == NULL) {
            printf("Error: failed to reallocate memory for employee list\n");
            exit(1);
        }
        list->data = newData;
    }

    // Add the new employee to the end of the list
    int index = list->numEmployees;
    strncpy(list->data[index].name, name, MAX_NAME_LENGTH);
    list->data[index].age = age;
    list->data[index].employeeID = employeeID;
    list->numEmployees++;
}

// Function to print the entire employee list
void printEmployeeList(EmployeeList* list) {
    for (int i = 0; i < list->numEmployees; i++) {
        printf("Name: %s\nAge: %d\nEmployee ID: %d\n", list->data[i].name, list->data[i].age, list->data[i].employeeID);
    }
}

// Main function to test the employee list
int main() {
    EmployeeList employeeList;
    initEmployeeList(&employeeList);

    addEmployee(&employeeList, "John Doe", 30, 12345);
    addEmployee(&employeeList, "Jane Smith", 28, 67890);

    printEmployeeList(&employeeList);

    return 0;
}