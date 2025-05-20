//GEMINI-pro DATASET v1.0 Category: Educational ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of employees and the maximum length of an employee's name
#define MAX_EMPLOYEES 100
#define MAX_NAME_LENGTH 50

// Define the structure of an employee
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    double salary;
} Employee;

// Create an array of employees
Employee employees[MAX_EMPLOYEES];

// Get the number of employees from the user
int get_num_employees() {
    int num_employees;
    printf("Enter the number of employees: ");
    scanf("%d", &num_employees);
    return num_employees;
}

// Get the details of an employee from the user
void get_employee_details(Employee *employee) {
    printf("Enter the employee's ID: ");
    scanf("%d", &employee->id);
    printf("Enter the employee's name: ");
    scanf("%s", employee->name);
    printf("Enter the employee's salary: ");
    scanf("%lf", &employee->salary);
}

// Print the details of an employee
void print_employee_details(Employee *employee) {
    printf("Employee ID: %d\n", employee->id);
    printf("Employee Name: %s\n", employee->name);
    printf("Employee Salary: %.2lf\n", employee->salary);
}

// Find the employee with the highest salary
Employee *find_employee_with_highest_salary(Employee *employees, int num_employees) {
    Employee *highest_salary_employee = NULL;
    double highest_salary = 0;
    for (int i = 0; i < num_employees; i++) {
        if (employees[i].salary > highest_salary) {
            highest_salary = employees[i].salary;
            highest_salary_employee = &employees[i];
        }
    }
    return highest_salary_employee;
}

// Main function
int main() {
    // Get the number of employees from the user
    int num_employees = get_num_employees();

    // Get the details of each employee from the user
    for (int i = 0; i < num_employees; i++) {
        get_employee_details(&employees[i]);
    }

    // Find the employee with the highest salary
    Employee *highest_salary_employee = find_employee_with_highest_salary(employees, num_employees);

    // Print the details of the employee with the highest salary
    printf("The employee with the highest salary is:\n");
    print_employee_details(highest_salary_employee);

    return 0;
}