//FormAI DATASET v1.0 Category: Database querying ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct employee {
    char name[30];
    int id;
    double salary;
} Employee;

void displayAllEmployees(Employee *employees, int numEmployees);
void displayEmployee(Employee employee);
Employee *searchEmployeeById(Employee *employees, int numEmployees, int id);
Employee *getHighestPaidEmployee(Employee *employees, int numEmployees);
Employee *getLowestPaidEmployee(Employee *employees, int numEmployees);

int main() {
    int choice, numEmployees, id;
    Employee *employees, *employee, *highestPaidEmployee, *lowestPaidEmployee;
    
    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);
    
    employees = (Employee *)malloc(numEmployees * sizeof(Employee));
    if (employees == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    
    for (int i = 0; i < numEmployees; i++) {
        printf("\nEmployee %d\n", i+1);
        printf("Enter employee name: ");
        scanf("%s", employees[i].name);
        printf("Enter employee ID: ");
        scanf("%d", &employees[i].id);
        printf("Enter employee salary: ");
        scanf("%lf", &employees[i].salary);
    }
    
    do {
        printf("\n\n1. Display all employees\n");
        printf("2. Search employee by ID\n");
        printf("3. Display highest paid employee\n");
        printf("4. Display lowest paid employee\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayAllEmployees(employees, numEmployees);
                break;
            case 2:
                printf("Enter employee ID to search: ");
                scanf("%d", &id);
                employee = searchEmployeeById(employees, numEmployees, id);
                if (employee == NULL) {
                    printf("\nEmployee with ID %d not found\n", id);
                } else {
                    displayEmployee(*employee);
                }
                break;
            case 3:
                highestPaidEmployee = getHighestPaidEmployee(employees, numEmployees);
                displayEmployee(*highestPaidEmployee);
                break;
            case 4:
                lowestPaidEmployee = getLowestPaidEmployee(employees, numEmployees);
                displayEmployee(*lowestPaidEmployee);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 5);
    
    free(employees);
    
    return 0;
}

void displayAllEmployees(Employee *employees, int numEmployees) {
    printf("\nEmployee List\n");
    printf("--------------\n");
    printf("ID\tName\tSalary\n");
    printf("--------------\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("%d\t%s\t%.2lf\n", employees[i].id, employees[i].name, employees[i].salary);
    }
    printf("--------------\n");
}

void displayEmployee(Employee employee) {
    printf("\nEmployee Details\n");
    printf("-----------------\n");
    printf("Name: %s\n", employee.name);
    printf("ID: %d\n", employee.id);
    printf("Salary: %.2lf\n", employee.salary);
}

Employee *searchEmployeeById(Employee *employees, int numEmployees, int id) {
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].id == id) {
            return &employees[i];
        }
    }
    return NULL;
}

Employee *getHighestPaidEmployee(Employee *employees, int numEmployees) {
    Employee *highestPaid = &employees[0];
    for (int i = 1; i < numEmployees; i++) {
        if (employees[i].salary > highestPaid->salary) {
            highestPaid = &employees[i];
        }
    }
    return highestPaid;
}

Employee *getLowestPaidEmployee(Employee *employees, int numEmployees) {
    Employee *lowestPaid = &employees[0];
    for (int i = 1; i < numEmployees; i++) {
        if (employees[i].salary < lowestPaid->salary) {
            lowestPaid = &employees[i];
        }
    }
    return lowestPaid;
}