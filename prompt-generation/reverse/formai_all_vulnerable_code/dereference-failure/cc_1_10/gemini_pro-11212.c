//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Database structure
typedef struct {
    int id;
    char *name;
    int age;
    float salary;
} Employee;

// Database operations
void createTable(Employee **employees, int *size) {
    *employees = (Employee *)malloc(sizeof(Employee) * *size);
}

void insertRecord(Employee *employees, int *size, int id, char *name, int age, float salary) {
    employees[*size].id = id;
    employees[*size].name = name;
    employees[*size].age = age;
    employees[*size].salary = salary;
    *size = *size + 1;
}

void updateRecord(Employee *employees, int *size, int id, char *name, int age, float salary) {
    for (int i = 0; i < *size; i++) {
        if (employees[i].id == id) {
            employees[i].name = name;
            employees[i].age = age;
            employees[i].salary = salary;
            break;
        }
    }
}

void deleteRecord(Employee *employees, int *size, int id) {
    for (int i = 0; i < *size; i++) {
        if (employees[i].id == id) {
            for (int j = i; j < *size - 1; j++) {
                employees[j] = employees[j + 1];
            }
            *size = *size - 1;
            break;
        }
    }
}

void printTable(Employee *employees, int *size) {
    printf("ID\tName\tAge\tSalary\n");
    for (int i = 0; i < *size; i++) {
        printf("%d\t%s\t%d\t%.2f\n", employees[i].id, employees[i].name, employees[i].age, employees[i].salary);
    }
}

// Main function
int main() {
    // Create a database
    Employee *employees;
    int size = 0;
    createTable(&employees, &size);

    // Insert records
    insertRecord(employees, &size, 1, "John Doe", 30, 50000.00);
    insertRecord(employees, &size, 2, "Jane Doe", 25, 40000.00);
    insertRecord(employees, &size, 3, "Peter Parker", 22, 30000.00);

    // Print the database
    printTable(employees, &size);

    // Update a record
    updateRecord(employees, &size, 2, "Jane Smith", 26, 45000.00);

    // Print the database
    printTable(employees, &size);

    // Delete a record
    deleteRecord(employees, &size, 3);

    // Print the database
    printTable(employees, &size);

    // Free the memory
    free(employees);

    return 0;
}