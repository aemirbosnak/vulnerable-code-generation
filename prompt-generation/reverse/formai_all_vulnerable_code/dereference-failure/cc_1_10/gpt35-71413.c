//FormAI DATASET v1.0 Category: Database querying ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    char name[50];
    int age, salary, employee_id;
    struct Employee *manager;
};

int search_employee(struct Employee **employees, int n, int employee_id) {
    int i, index = -1;
    for (i = 0; i < n; i++) {
        if (employees[i]->employee_id == employee_id) {
            index = i;
            break;
        }
    }
    return index;
}

void insert_employee(struct Employee **employees, int n, struct Employee *employee) {
    int i = search_employee(employees, n, employee->employee_id);
    if (i != -1) {
        printf("Employee with ID %d already exists\n", employee->employee_id);
    } else {
        employees[n] = employee;
    }
}

void create_hierarchy(struct Employee **employees, int n, int manager_id, int employee_id) {
    struct Employee *employee = employees[search_employee(employees, n, employee_id)];
    struct Employee *manager = employees[search_employee(employees, n, manager_id)];
    if (employee->manager != NULL) {
        printf("Employee already has a manager\n");
        return;
    }
    if (employee == manager) {
        printf("Employee cannot be its own manager\n");
        return;
    }
    employee->manager = manager;
}

int calculate_total_salary(struct Employee **employees, int n, int manager_id) {
    int i, total_salary = 0;
    for (i = 0; i < n; i++) {
        if (employees[i]->manager != NULL && employees[i]->manager->employee_id == manager_id) {
            total_salary += employees[i]->salary + calculate_total_salary(employees, n, employees[i]->employee_id);
        }
    }
    return total_salary;
}

int main() {
    struct Employee **employees = calloc(10, sizeof(struct Employee *));
    int n = 0;
    
    struct Employee *employee1 = malloc(sizeof(struct Employee));
    strcpy(employee1->name, "Alice");
    employee1->age = 32;
    employee1->salary = 50000;
    employee1->employee_id = 1;
    employee1->manager = NULL;
    insert_employee(employees, n++, employee1);
    
    struct Employee *employee2 = malloc(sizeof(struct Employee));
    strcpy(employee2->name, "Bob");
    employee2->age = 28;
    employee2->salary = 45000;
    employee2->employee_id = 2;
    employee2->manager = NULL;
    insert_employee(employees, n++, employee2);
    
    struct Employee *employee3 = malloc(sizeof(struct Employee));
    strcpy(employee3->name, "Charlie");
    employee3->age = 35;
    employee3->salary = 55000;
    employee3->employee_id = 3;
    employee3->manager = NULL;
    insert_employee(employees, n++, employee3);
    
    create_hierarchy(employees, n, 1, 2);
    create_hierarchy(employees, n, 1, 3);
    create_hierarchy(employees, n, 2, 4); // this will fail since employee with ID 4 does not exist
    create_hierarchy(employees, n, 1, 1); // this will fail since employee cannot be its own manager
    
    int total_salary = calculate_total_salary(employees, n, 1);
    printf("Total salary for employees under Alice: %d\n", total_salary);
    
    return 0;
}