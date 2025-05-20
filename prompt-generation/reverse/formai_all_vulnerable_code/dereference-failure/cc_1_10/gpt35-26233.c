//FormAI DATASET v1.0 Category: Data mining ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Define the structures
typedef struct {
    int id;
    char name[50];
    int age;
    float salary;
} Employee;

typedef struct {
    int id;
    int num_employees;
    Employee *employees;
} Company;

// Function to read the data from a file
Company read_data(char *filename)
{
    Company company;
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    // Read the company information
    fscanf(fp, "%d", &company.id);
    fscanf(fp, "%d", &company.num_employees);

    // Allocated memory for the employees
    company.employees = (Employee *) malloc(company.num_employees * sizeof(Employee));

    // Read the employee information
    for (int i = 0; i < company.num_employees; i++) {
        fscanf(fp, "%d", &company.employees[i].id);
        fscanf(fp, "%s", company.employees[i].name);
        fscanf(fp, "%d", &company.employees[i].age);
        fscanf(fp, "%f", &company.employees[i].salary);
    }

    fclose(fp);
    return company;
}

// Function to print the data
void print_data(Company company)
{
    printf("Company ID: %d\n", company.id);
    printf("Number of Employees: %d\n", company.num_employees);
    printf("Employees:\n");
    for (int i = 0; i < company.num_employees; i++) {
        printf("%d\t%s\t%d\t%.2f\n", company.employees[i].id,
                                     company.employees[i].name,
                                     company.employees[i].age,
                                     company.employees[i].salary);
    }
}

int main()
{
    char *filename = "company_data.txt";
    Company company = read_data(filename);
    print_data(company);
    return 0;
}