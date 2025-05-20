//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    char *gender;
    double salary;
} Employee;

void read_csv(FILE *file, Employee *employees, int *num_employees) {
    char buffer[1024];
    fgets(buffer, 1024, file);  // Read header row (ignoring it)
    
    while (fgets(buffer, 1024, file)) {
        // Parse a row into variables
        char *name = strtok(buffer, ",");
        int age = atoi(strtok(NULL, ","));
        char *gender = strtok(NULL, ",");
        double salary = atof(strtok(NULL, ","));
        
        // Allocate memory for a new employee and add it to the array
        employees[*num_employees].name = (char *) malloc(strlen(name)+1);
        strcpy(employees[*num_employees].name, name);
        employees[*num_employees].age = age;
        employees[*num_employees].gender = (char *) malloc(strlen(gender)+1);
        strcpy(employees[*num_employees].gender, gender);
        employees[*num_employees].salary = salary;
        
        // Increment the number of employees in the array
        *num_employees = *num_employees + 1;
    }
}

int main() {
    FILE *file = fopen("employees.csv", "r");
    if (!file) {
        printf("Error: Could not open employees.csv\n");
        return 1;
    }
    
    // Allocate memory for an array of Employee structs
    Employee *employees = (Employee *) malloc(sizeof(Employee)*100);
    int num_employees = 0;
    
    // Read the CSV file and populate the array of employees
    read_csv(file, employees, &num_employees);
    fclose(file);
    
    // Print the contents of the Employee array
    printf("Name\tAge\tGender\tSalary\n");
    for (int i=0; i<num_employees; i++) {
        printf("%s\t%d\t%s\t%.2f\n", employees[i].name, employees[i].age, employees[i].gender, employees[i].salary);
        
        // Free memory for each employee's name and gender string
        free(employees[i].name);
        free(employees[i].gender);
    }
    
    // Free memory for the array of Employee structs
    free(employees);
    
    return 0;
}