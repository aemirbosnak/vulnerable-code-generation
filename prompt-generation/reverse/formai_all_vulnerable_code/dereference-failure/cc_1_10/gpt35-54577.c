//FormAI DATASET v1.0 Category: Database querying ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold employee data
typedef struct Employee {
    int emp_id;
    char emp_name[50];
    int emp_age;
    char emp_department[50];
} Employee;

// Function to print employee data
void printEmployeeData(Employee emp) {
    printf("%d\t%s\t%d\t%s\n", emp.emp_id, emp.emp_name, emp.emp_age, emp.emp_department);
}

// Function to search for employee by department name
Employee* getEmployeeByDepartment(char* department, Employee* employees, int num_employees) {
    Employee* result = (Employee*)malloc(num_employees * sizeof(Employee));
    int index = 0;
    for (int i = 0; i < num_employees; i++) {
        if (strcmp(employees[i].emp_department, department) == 0) {
            result[index++] = employees[i];
        }
    }
    return result;
}

int main() {
    // Initialize employee data
    Employee employees[5] = {
        {1, "John Doe", 25, "Sales"},
        {2, "Jane Smith", 30, "Marketing"},
        {3, "Bob Johnson", 28, "IT"},
        {4, "Sarah Lee", 35, "HR"},
        {5, "Mike Brown", 40, "Sales"}
    };
    int num_employees = sizeof(employees) / sizeof(employees[0]);

    // Get all employees in Sales department
    Employee* sales_employees = getEmployeeByDepartment("Sales", employees, num_employees);
    int sales_count = sizeof(sales_employees) / sizeof(sales_employees[0]);

    // Print all employees in Sales department
    printf("Employees in Sales department:\n");
    printf("ID\tName\tAge\tDepartment\n");
    for (int i = 0; i < sales_count; i++) {
        printEmployeeData(sales_employees[i]);
    }

    // Free dynamically allocated memory
    free(sales_employees);

    return 0;
}