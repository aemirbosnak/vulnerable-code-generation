//Falcon-180B DATASET v1.0 Category: Database querying ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    char *name;
    int age;
    float salary;
} employee;

employee database[MAX_ROWS];
int num_rows = 0;
int num_cols = 3;

void add_employee(char *name, int age, float salary) {
    if (num_rows >= MAX_ROWS) {
        printf("Error: Database is full.\n");
        return;
    }
    database[num_rows].name = malloc(strlen(name) + 1);
    strcpy(database[num_rows].name, name);
    database[num_rows].age = age;
    database[num_rows].salary = salary;
    num_rows++;
}

void display_database() {
    printf("Name\tAge\tSalary\n");
    for (int i = 0; i < num_rows; i++) {
        printf("%s\t%d\t%.2f\n", database[i].name, database[i].age, database[i].salary);
    }
}

void sort_database(int (*compare)(const void *, const void *)) {
    qsort(database, num_rows, sizeof(employee), compare);
}

int compare_age(const void *a, const void *b) {
    employee *e1 = (employee *)a;
    employee *e2 = (employee *)b;
    return e1->age - e2->age;
}

int compare_salary(const void *a, const void *b) {
    employee *e1 = (employee *)a;
    employee *e2 = (employee *)b;
    return e2->salary - e1->salary;
}

int main() {
    add_employee("John Doe", 30, 50000.00);
    add_employee("Jane Smith", 25, 45000.00);
    add_employee("Bob Johnson", 35, 60000.00);
    add_employee("Alice Brown", 28, 55000.00);

    display_database();

    sort_database(compare_age);
    printf("\nSorted by age:\n");
    display_database();

    sort_database(compare_salary);
    printf("\nSorted by salary:\n");
    display_database();

    return 0;
}