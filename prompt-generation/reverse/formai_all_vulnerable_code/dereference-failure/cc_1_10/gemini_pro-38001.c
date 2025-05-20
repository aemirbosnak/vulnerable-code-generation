//GEMINI-pro DATASET v1.0 Category: File handling ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store employee data
typedef struct employee {
  int id;
  char name[50];
  float salary;
} employee;

// Function to read employee data from a file
void read_employees(FILE *fp, employee **employees, int *num_employees) {
  // Get the number of employees
  fscanf(fp, "%d", num_employees);

  // Allocate memory for the employees
  *employees = (employee *)malloc(sizeof(employee) * (*num_employees));

  // Read the employee data
  for (int i = 0; i < *num_employees; i++) {
    fscanf(fp, "%d %s %f", &(*employees)[i].id, (*employees)[i].name, &(*employees)[i].salary);
  }
}

// Function to write employee data to a file
void write_employees(FILE *fp, employee *employees, int num_employees) {
  // Write the number of employees
  fprintf(fp, "%d\n", num_employees);

  // Write the employee data
  for (int i = 0; i < num_employees; i++) {
    fprintf(fp, "%d %s %f\n", employees[i].id, employees[i].name, employees[i].salary);
  }
}

// Function to compare two employees by ID
int compare_employees(const void *a, const void *b) {
  employee *e1 = (employee *)a;
  employee *e2 = (employee *)b;
  return e1->id - e2->id;
}

// Function to print employee data
void print_employees(employee *employees, int num_employees) {
  printf("Employees:\n");
  for (int i = 0; i < num_employees; i++) {
    printf("%d %s %.2f\n", employees[i].id, employees[i].name, employees[i].salary);
  }
}

int main() {
  // Open the input file
  FILE *fp = fopen("employees.txt", "r");
  if (fp == NULL) {
    perror("Error opening input file");
    return EXIT_FAILURE;
  }

  // Read the employee data
  employee *employees;
  int num_employees;
  read_employees(fp, &employees, &num_employees);

  // Close the input file
  fclose(fp);

  // Sort the employees by ID
  qsort(employees, num_employees, sizeof(employee), compare_employees);

  // Print the employee data
  print_employees(employees, num_employees);

  // Open the output file
  fp = fopen("employees_sorted.txt", "w");
  if (fp == NULL) {
    perror("Error opening output file");
    return EXIT_FAILURE;
  }

  // Write the employee data
  write_employees(fp, employees, num_employees);

  // Close the output file
  fclose(fp);

  // Free the memory allocated for the employees
  free(employees);

  return EXIT_SUCCESS;
}