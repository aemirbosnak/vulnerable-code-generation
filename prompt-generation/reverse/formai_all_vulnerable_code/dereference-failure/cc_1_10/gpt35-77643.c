//FormAI DATASET v1.0 Category: File handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    double salary;
} Employee;

void writeEmployeeToFile(FILE *filePtr, Employee *employeePtr);
void readEmployeeFromFile(FILE *filePtr, Employee *employeePtr);

int main() {
    FILE *filePtr;
    Employee employee = {"John Doe", 30, 50000.0};

    filePtr = fopen("employee.txt", "w+");
    if (filePtr == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    writeEmployeeToFile(filePtr, &employee);
    memset(&employee, 0, sizeof(Employee)); 

    rewind(filePtr);

    readEmployeeFromFile(filePtr, &employee);

    printf("Employee name: %s\n", employee.name);
    printf("Employee age: %d\n", employee.age);
    printf("Employee salary: %.2f\n", employee.salary);

    fclose(filePtr);
    return 0;
}

void writeEmployeeToFile(FILE *filePtr, Employee *employeePtr) {
    if (fwrite(employeePtr, sizeof(Employee), 1, filePtr) != 1) {
        printf("Error writing to file!\n");
        exit(1);
    }
}

void readEmployeeFromFile(FILE *filePtr, Employee *employeePtr) {
    if (fread(employeePtr, sizeof(Employee), 1, filePtr) != 1) {
        printf("Error reading from file!\n");
        exit(1);
    }
}