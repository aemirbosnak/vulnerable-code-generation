//FormAI DATASET v1.0 Category: Data mining ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold data
typedef struct {
  char name[100];
  int age;
  float salary;
} Employee;

// Define a function to print an Employee struct
void printEmployee(Employee *e) {
  printf("Name: %s\nAge: %d\nSalary: %.2f\n", e->name, e->age, e->salary);
}

int main() {

  // Create an array of Employee structs
  Employee employees[5];

  // Read in data from a file, assuming it's in the format "name, age, salary" on each line
  FILE *file;
  file = fopen("employees.txt", "r");
  char line[100];
  int i = 0;
  while (fgets(line, 100, file) != NULL) {
    char *token = strtok(line, ",");
    strcpy(employees[i].name, token);
    token = strtok(NULL, ",");
    employees[i].age = atoi(token);
    token = strtok(NULL, ",");
    employees[i].salary = atof(token);
    i++;
  }
  fclose(file);

  // Find the oldest employee
  int maxAge = 0;
  Employee *oldestEmployee;
  for (int i = 0; i < 5; i++) {
    if (employees[i].age > maxAge) {
      maxAge = employees[i].age;
      oldestEmployee = &employees[i];
    }
  }

  // Print out the oldest employee
  printf("The oldest employee is:\n");
  printEmployee(oldestEmployee);

  return 0;
}