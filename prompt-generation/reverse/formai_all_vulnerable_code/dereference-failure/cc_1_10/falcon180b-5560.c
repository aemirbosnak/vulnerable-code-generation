//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    char *name;
    int age;
    char city[50];
    float salary;
} Employee;

typedef struct {
    Employee *data;
    int num_rows;
    int num_cols;
} Database;

void init_database(Database *db) {
    db->data = (Employee *) malloc(MAX_ROWS * sizeof(Employee));
    db->num_rows = 0;
    db->num_cols = 4;
}

void add_employee(Database *db, char *name, int age, char *city, float salary) {
    Employee emp;
    strcpy(emp.name, name);
    emp.age = age;
    strcpy(emp.city, city);
    emp.salary = salary;

    db->data[db->num_rows] = emp;
    db->num_rows++;
}

void print_employee(Employee emp) {
    printf("Name: %s\n", emp.name);
    printf("Age: %d\n", emp.age);
    printf("City: %s\n", emp.city);
    printf("Salary: %.2f\n", emp.salary);
}

void print_database(Database db) {
    int i, j;

    for(i=0; i<db.num_rows; i++) {
        for(j=0; j<db.num_cols; j++) {
            switch(j) {
                case 0:
                    printf("%s\t", db.data[i].name);
                    break;
                case 1:
                    printf("%d\t", db.data[i].age);
                    break;
                case 2:
                    printf("%s\t", db.data[i].city);
                    break;
                case 3:
                    printf("%.2f\t", db.data[i].salary);
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    Database db;
    init_database(&db);

    add_employee(&db, "John Doe", 25, "New York", 50000);
    add_employee(&db, "Jane Smith", 30, "Los Angeles", 60000);

    print_database(db);

    return 0;
}