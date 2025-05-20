//FormAI DATASET v1.0 Category: Database querying ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    float salary;
} Employee;

int main() {
    // create an array of employees
    Employee employees[5] = {
        {1, "John", 28, 30000.0},
        {2, "Jane", 42, 50000.0},
        {3, "Eric", 35, 40000.0},
        {4, "Lisa", 24, 25000.0},
        {5, "Mike", 45, 55000.0}
    };

    // initialize the database with the employee array
    int num_employees = sizeof(employees) / sizeof(Employee);
    Employee *db = (Employee *) malloc(num_employees * sizeof(Employee));
    memcpy(db, employees, num_employees * sizeof(Employee));

    // query the database for employee information
    int input_id;
    printf("Enter employee ID to search: ");
    scanf("%d", &input_id);

    Employee *result = NULL;
    for (int i = 0; i < num_employees; i++) {
        if (db[i].id == input_id) {
            result = &db[i];
            break;
        }
    }

    // print the result if found, otherwise print an error message
    if (result != NULL) {
        printf("Employee ID: %d\n", result->id);
        printf("Name: %s\n", result->name);
        printf("Age: %d\n", result->age);
        printf("Salary: %.2f\n", result->salary);
    } else {
        printf("Employee not found\n");
    }

    // free the memory allocated for the database
    free(db);

    return 0;
}