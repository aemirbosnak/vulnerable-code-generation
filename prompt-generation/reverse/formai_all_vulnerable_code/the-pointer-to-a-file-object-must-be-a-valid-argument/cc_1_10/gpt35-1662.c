//FormAI DATASET v1.0 Category: Data mining ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FIELD_LENGTH 100

typedef struct {
    int age;
    int salary;
    char name[MAX_FIELD_LENGTH];
} Employee;

int main() {
    FILE *inputFile;
    Employee employees[100];
    int numEmployees = 0;

    // Open input file
    inputFile = fopen("employee_data.txt", "r");
    
    // Read data from input file
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, inputFile) != NULL) {
        char *token;
        int fieldNum = 0;
        char *fields[3];

        // Parse line into fields using strtok
        token = strtok(line, ",");
        while (token != NULL) {
            fields[fieldNum] = token;
            fieldNum++;
            token = strtok(NULL, ",");
        }

        // Convert fields to Employee struct
        Employee employee;
        strcpy(employee.name, fields[0]);
        employee.age = atoi(fields[1]);
        employee.salary = atoi(fields[2]);
        employees[numEmployees] = employee;
        numEmployees++;
    }

    // Close input file
    fclose(inputFile);

    // Print employee data
    for (int i = 0; i < numEmployees; i++) {
        printf("Name: %s\n", employees[i].name);
        printf("Age: %d\n", employees[i].age);
        printf("Salary: %d\n", employees[i].salary);
        printf("\n");
    }

    return 0;
}