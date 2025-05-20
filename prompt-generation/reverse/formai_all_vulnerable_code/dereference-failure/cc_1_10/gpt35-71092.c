//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024 // Maximum length of a line in CSV file

typedef struct {
    int id;
    char name[50];
    int age;
    float salary;
} Employee;

int getCSVData(FILE *csvFile, Employee *empArray, int maxEmp) {
    int empCount = 0; 
    char line[MAX_LEN];
    fgets(line, MAX_LEN, csvFile); // Skip header row
    
    while(fgets(line, MAX_LEN, csvFile) != NULL && empCount < maxEmp) {
        Employee emp;
        char *token;
        token = strtok(line, ",");
        emp.id = atoi(token);
        token = strtok(NULL, ",");
        strcpy(emp.name, token);
        token = strtok(NULL, ",");
        emp.age = atoi(token);
        token = strtok(NULL, ",");
        emp.salary = atof(token);
        empArray[empCount++] = emp;
    }
    return empCount;
}

int main() {
    FILE *csvFile = fopen("employees.csv", "r");

    if(csvFile == NULL) {
        printf("Error: Could not open file!\n");
        exit(1);
    }

    Employee empArray[10]; // Maximum 10 employees
    int empCount = getCSVData(csvFile, empArray, 10);
    fclose(csvFile);
    
    // Display employee data
    printf("ID\tName\tAge\tSalary\n");
    for(int i = 0; i < empCount; i++) {
        printf("%d\t%s\t%d\t%.2f\n", empArray[i].id, empArray[i].name, empArray[i].age, empArray[i].salary);
    }
    return 0;
}