//FormAI DATASET v1.0 Category: Database simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int id;
    char name[50];
    int age;
    float salary;
};

void insertEmployee(struct Employee emp) {
    FILE *fp;
    fp = fopen("employees.txt", "a");
    fprintf(fp, "%d,%s,%d,%.2f\n", emp.id, emp.name, emp.age, emp.salary);
    fclose(fp);
}

struct Employee *getEmployeeById(int id) {
    FILE *fp;
    struct Employee *emp = malloc(sizeof(struct Employee));
    fp = fopen("employees.txt", "r");
    if(fp == NULL) {
        printf("Error: File Not Found\n");
        return NULL;
    }
    char line[255];
    while(fgets(line, 255, fp) != NULL) {
        char *token;
        token = strtok(line, ",");
        if(atoi(token) == id) {
            emp->id = atoi(token);
            strcpy(emp->name, strtok(NULL, ","));
            emp->age = atoi(strtok(NULL, ","));
            emp->salary = atof(strtok(NULL, ","));
            fclose(fp);
            return emp;
        }
    }
    fclose(fp);
    printf("Error: Employee Not Found\n");
    return NULL;
}

void printEmployees() {
    FILE *fp;
    fp = fopen("employees.txt", "r");
    if(fp == NULL) {
        printf("Error: File Not Found\n");
        return;
    }
    char line[255];
    printf("ID\tName\t\tAge\tSalary\n");
    printf("----------------------------------------------\n");
    while(fgets(line, 255, fp) != NULL) {
        printf("%s", line);
    }
    fclose(fp);
}

int main() {
    struct Employee emp1 = {101, "John Doe", 25, 50000};
    struct Employee emp2 = {102, "Jane Doe", 30, 60000};

    insertEmployee(emp1);
    insertEmployee(emp2);
    
    struct Employee *emp3;
    emp3 = getEmployeeById(101);
    if(emp3 != NULL) {
        printf("Employee Found: %s with a salary of %.2f\n", emp3->name, emp3->salary);
    }

    printEmployees();

    return 0;
}