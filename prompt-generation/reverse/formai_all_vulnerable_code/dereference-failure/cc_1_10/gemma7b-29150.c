//Gemma-7B DATASET v1.0 Category: Database querying ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUERY_SIZE 1024

typedef struct Employee {
  char name[50];
  int age;
  double salary;
  struct Employee* next;
} Employee;

Employee* insert_employee(Employee* head, char* name, int age, double salary) {
  Employee* new_employee = (Employee*)malloc(sizeof(Employee));
  strcpy(new_employee->name, name);
  new_employee->age = age;
  new_employee->salary = salary;
  new_employee->next = NULL;

  if (head == NULL) {
    head = new_employee;
  } else {
    head->next = new_employee;
  }

  return head;
}

Employee* find_employee(Employee* head, char* name) {
  Employee* current = head;

  while (current) {
    if (strcmp(current->name, name) == 0) {
      return current;
    }
    current = current->next;
  }

  return NULL;
}

int main() {
  Employee* head = NULL;

  insert_employee(&head, "John Doe", 25, 50000);
  insert_employee(&head, "Jane Doe", 30, 60000);
  insert_employee(&head, "Peter Pan", 12, 70000);

  Employee* employee = find_employee(head, "Jane Doe");

  if (employee) {
    printf("Name: %s, Age: %d, Salary: %.2lf\n", employee->name, employee->age, employee->salary);
  } else {
    printf("Employee not found.\n");
  }

  return 0;
}