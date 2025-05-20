//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define NAME_LENGTH 50
#define FILE_NAME "employees.dat"

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float salary;
} Employee;

void addEmployee(FILE *file);
void listEmployees(FILE *file);
void deleteEmployee(FILE *file);
Employee createEmployee(int id, const char *name, float salary);
void writeEmployee(FILE *file, Employee emp);
void readEmployee(FILE *file, Employee *emp);
void clearBuffer();

int main() {
    FILE *file;
    int choice;

    do {
        printf("\n--- Employee Database Simulation ---\n");
        printf("1. Add Employee\n");
        printf("2. List Employees\n");
        printf("3. Delete Employee\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();

        file = fopen(FILE_NAME, "a+b");
        if (file == NULL) {
            perror("Error opening file");
            return 1;
        }

        switch (choice) {
            case 1:
                addEmployee(file);
                break;
            case 2:
                listEmployees(file);
                break;
            case 3:
                deleteEmployee(file);
                break;
            case 4:
                fclose(file);
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
        
        fclose(file);
        
    } while (choice != 4);

    return 0;
}

void addEmployee(FILE *file) {
    int id;
    char name[NAME_LENGTH];
    float salary;

    printf("Enter Employee ID: ");
    scanf("%d", &id);
    clearBuffer();

    printf("Enter Employee Name: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character

    printf("Enter Employee Salary: ");
    scanf("%f", &salary);
    
    Employee emp = createEmployee(id, name, salary);
    writeEmployee(file, emp);
    printf("Employee added successfully!\n");
}

void listEmployees(FILE *file) {
    Employee emp;

    printf("\nList of Employees:\n");
    printf("%-10s %-25s %s\n", "ID", "Name", "Salary");
    
    while (fread(&emp, sizeof(Employee), 1, file)) {
        printf("%-10d %-25s %.2f\n", emp.id, emp.name, emp.salary);
    }
}

void deleteEmployee(FILE *file) {
    int id;
    printf("Enter the Employee ID to delete: ");
    scanf("%d", &id);
    clearBuffer();
    
    FILE *tempFile = fopen("temp.dat", "w+b");
    if (tempFile == NULL) {
        perror("Error opening temp file");
        return;
    }

    Employee emp;
    int found = 0;

    while (fread(&emp, sizeof(Employee), 1, file)) {
        if (emp.id != id) {
            fwrite(&emp, sizeof(Employee), 1, tempFile);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILE_NAME);
        rename("temp.dat", FILE_NAME);
        printf("Employee with ID %d deleted successfully!\n", id);
    } else {
        remove("temp.dat");
        printf("Employee with ID %d not found!\n", id);
    }
}

Employee createEmployee(int id, const char *name, float salary) {
    Employee emp;
    emp.id = id;
    strncpy(emp.name, name, NAME_LENGTH);
    emp.salary = salary;
    return emp;
}

void writeEmployee(FILE *file, Employee emp) {
    fwrite(&emp, sizeof(Employee), 1, file);
}

void readEmployee(FILE *file, Employee *emp) {
    fread(emp, sizeof(Employee), 1, file);
}

void clearBuffer() {
    while (getchar() != '\n');
}