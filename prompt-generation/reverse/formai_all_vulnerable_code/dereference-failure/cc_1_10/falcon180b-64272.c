//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
    double salary;
} employee_t;

void read_data(employee_t *data, int num_employees) {
    for (int i = 0; i < num_employees; i++) {
        data[i].name = (char *) malloc(MAX_SIZE * sizeof(char));
        printf("Enter name for employee %d: ", i + 1);
        scanf("%s", data[i].name);

        printf("Enter age for employee %s: ", data[i].name);
        scanf("%d", &data[i].age);

        printf("Enter salary for employee %s: ", data[i].name);
        scanf("%lf", &data[i].salary);
    }
}

void print_data(employee_t *data, int num_employees) {
    for (int i = 0; i < num_employees; i++) {
        printf("Name: %s\nAge: %d\nSalary: $%.2lf\n\n", data[i].name, data[i].age, data[i].salary);
    }
}

void sort_data(employee_t *data, int num_employees, int (*compare)(const void *, const void *)) {
    qsort(data, num_employees, sizeof(employee_t), compare);
}

int compare_age(const void *a, const void *b) {
    employee_t *emp1 = (employee_t *) a;
    employee_t *emp2 = (employee_t *) b;

    if (emp1->age > emp2->age)
        return 1;
    else if (emp1->age < emp2->age)
        return -1;
    else
        return 0;
}

int compare_salary(const void *a, const void *b) {
    employee_t *emp1 = (employee_t *) a;
    employee_t *emp2 = (employee_t *) b;

    if (emp1->salary > emp2->salary)
        return 1;
    else if (emp1->salary < emp2->salary)
        return -1;
    else
        return 0;
}

int main() {
    int num_employees;
    printf("Enter number of employees: ");
    scanf("%d", &num_employees);

    employee_t *data = (employee_t *) malloc(num_employees * sizeof(employee_t));

    read_data(data, num_employees);

    printf("Unsorted Data:\n");
    print_data(data, num_employees);

    sort_data(data, num_employees, compare_age);

    printf("\nSorted by Age:\n");
    print_data(data, num_employees);

    sort_data(data, num_employees, compare_salary);

    printf("\nSorted by Salary:\n");
    print_data(data, num_employees);

    free(data);

    return 0;
}