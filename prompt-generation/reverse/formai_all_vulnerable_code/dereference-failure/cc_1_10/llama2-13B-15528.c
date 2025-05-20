//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DATASET_SIZE 1000

// Structure to store employee information
typedef struct {
    int emp_id;
    char name[20];
    int age;
    float salary;
} employee;

// Function to read the dataset from a file
employee *read_dataset(const char *file_name) {
    int i, j;
    employee *employees = (employee *)calloc(DATASET_SIZE, sizeof(employee));

    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", file_name);
        return NULL;
    }

    for (i = 0; i < DATASET_SIZE; i++) {
        fscanf(file, "%d%19s%d%f", &employees[i].emp_id, employees[i].name, &employees[i].age, &employees[i].salary);
    }

    fclose(file);
    return employees;
}

// Function to perform basic data analysis tasks
void analyze_data(employee *employees) {
    int i, j;

    // Calculate the average salary
    float avg_salary = 0;
    for (i = 0; i < DATASET_SIZE; i++) {
        avg_salary += employees[i].salary;
    }
    avg_salary /= DATASET_SIZE;
    printf("Average salary: %f\n", avg_salary);

    // Calculate the standard deviation of salaries
    float std_dev = 0;
    for (i = 0; i < DATASET_SIZE; i++) {
        std_dev += (employees[i].salary - avg_salary) * (employees[i].salary - avg_salary);
    }
    std_dev /= DATASET_SIZE;
    std_dev = sqrt(std_dev);
    printf("Standard deviation of salaries: %f\n", std_dev);

    // Calculate the minimum and maximum salaries
    float min_salary = employees[0].salary;
    float max_salary = employees[0].salary;
    for (i = 1; i < DATASET_SIZE; i++) {
        if (employees[i].salary < min_salary) {
            min_salary = employees[i].salary;
        }
        if (employees[i].salary > max_salary) {
            max_salary = employees[i].salary;
        }
    }
    printf("Minimum salary: %f\n", min_salary);
    printf("Maximum salary: %f\n", max_salary);
}

int main() {
    // Load the dataset from a file
    employee *employees = read_dataset("employee_data.txt");
    if (employees == NULL) {
        return 1;
    }

    // Perform basic data analysis tasks
    analyze_data(employees);

    // Free the memory allocated for the dataset
    free(employees);

    return 0;
}