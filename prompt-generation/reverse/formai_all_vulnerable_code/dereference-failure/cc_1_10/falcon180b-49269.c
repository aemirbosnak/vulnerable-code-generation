//Falcon-180B DATASET v1.0 Category: File handling ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float salary;
} Employee;

void read_employees(Employee* employees, int size) {
    FILE* file = fopen("employees.dat", "rb");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        fread(&employees[i], sizeof(Employee), 1, file);
    }

    fclose(file);
}

void write_employees(Employee* employees, int size) {
    FILE* file = fopen("employees.dat", "wb");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        fwrite(&employees[i], sizeof(Employee), 1, file);
    }

    fclose(file);
}

int main() {
    Employee employees[5];

    // Initialize employees
    for (int i = 0; i < 5; i++) {
        strcpy(employees[i].name, "Employee ");
        char num[2];
        sprintf(num, "%d", i + 1);
        strcat(employees[i].name, num);
        employees[i].age = i * 10;
        employees[i].salary = i * 1000;
    }

    // Write employees to file
    write_employees(employees, 5);

    // Read employees from file
    Employee temp_employees[5];
    read_employees(temp_employees, 5);

    // Print employees
    for (int i = 0; i < 5; i++) {
        printf("Name: %s\nAge: %d\nSalary: $%.2f\n\n", temp_employees[i].name, temp_employees[i].age, temp_employees[i].salary);
    }

    return 0;
}