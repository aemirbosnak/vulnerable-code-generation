//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char *name;
    int age;
} Person;

typedef struct {
    int id;
    char *name;
    char *address;
} Company;

typedef struct {
    int id;
    char *name;
    int salary;
} Employee;

typedef union {
    Person person;
    Company company;
    Employee employee;
} Data;

typedef struct {
    int id;
    char *type;
    Data data;
} Record;

int main() {
    // Create a database
    Record *database = malloc(sizeof(Record) * 100);

    // Insert some data into the database
    database[0].id = 1;
    database[0].type = "Person";
    database[0].data.person.id = 1;
    database[0].data.person.name = "John Doe";
    database[0].data.person.age = 30;

    database[1].id = 2;
    database[1].type = "Company";
    database[1].data.company.id = 2;
    database[1].data.company.name = "Acme Corporation";
    database[1].data.company.address = "123 Main Street";

    database[2].id = 3;
    database[2].type = "Employee";
    database[2].data.employee.id = 3;
    database[2].data.employee.name = "Jane Doe";
    database[2].data.employee.salary = 50000;

    // Print the data in the database
    for (int i = 0; i < 3; i++) {
        printf("Record %d:\n", database[i].id);
        printf("  Type: %s\n", database[i].type);
        if (strcmp(database[i].type, "Person") == 0) {
            printf("  Person:\n");
            printf("    ID: %d\n", database[i].data.person.id);
            printf("    Name: %s\n", database[i].data.person.name);
            printf("    Age: %d\n", database[i].data.person.age);
        } else if (strcmp(database[i].type, "Company") == 0) {
            printf("  Company:\n");
            printf("    ID: %d\n", database[i].data.company.id);
            printf("    Name: %s\n", database[i].data.company.name);
            printf("    Address: %s\n", database[i].data.company.address);
        } else if (strcmp(database[i].type, "Employee") == 0) {
            printf("  Employee:\n");
            printf("    ID: %d\n", database[i].data.employee.id);
            printf("    Name: %s\n", database[i].data.employee.name);
            printf("    Salary: %d\n", database[i].data.employee.salary);
        }
    }

    // Free the memory allocated for the database
    free(database);

    return 0;
}