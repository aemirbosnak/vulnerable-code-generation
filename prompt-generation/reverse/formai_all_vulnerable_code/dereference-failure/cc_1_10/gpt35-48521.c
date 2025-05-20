//FormAI DATASET v1.0 Category: Database querying ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int id;
  char name[50];
  float salary;
} Employee;

int main() {
  int n = 5; // number of employees
  Employee *employees = (Employee *)malloc(n * sizeof(Employee)); // allocating memory for employees array

  // initializing employees array
  employees[0].id = 1;
  strcpy(employees[0].name, "John");
  employees[0].salary = 5000.0;

  employees[1].id = 2;
  strcpy(employees[1].name, "Emma");
  employees[1].salary = 6000.0;

  employees[2].id = 3;
  strcpy(employees[2].name, "Ryan");
  employees[2].salary = 7000.0;

  employees[3].id = 4;
  strcpy(employees[3].name, "Grace");
  employees[3].salary = 8000.0;

  employees[4].id = 5;
  strcpy(employees[4].name, "Tom");
  employees[4].salary = 9000.0;

  // finding employee with id 3
  int i;
  for (i = 0; i < n; i++) {
    if (employees[i].id == 3) {
      printf("Employee with id %d found!\n", employees[i].id);
      printf("Name: %s\n", employees[i].name);
      printf("Salary: %.2f\n", employees[i].salary);
      break;
    }
  }

  // finding employees with salary greater than 7000
  printf("\nEmployees with salary greater than 7000:\n");
  for (i = 0; i < n; i++) {
    if (employees[i].salary > 7000.0) {
      printf("Id: %d\n", employees[i].id);
      printf("Name: %s\n", employees[i].name);
      printf("Salary: %.2f\n", employees[i].salary);
    }
  }

  // freeing memory
  free(employees);

  return 0;
}