//Gemma-7B DATASET v1.0 Category: Database querying ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUERY_LEN 255

typedef struct Employee {
  char name[50];
  int id;
  double salary;
  struct Employee* next;
} Employee;

Employee* insertEmployee(Employee* head, char* name, int id, double salary) {
  Employee* newNode = malloc(sizeof(Employee));
  strcpy(newNode->name, name);
  newNode->id = id;
  newNode->salary = salary;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

Employee* findEmployee(Employee* head, int id) {
  Employee* current = head;

  while (current) {
    if (current->id == id) {
      return current;
    }
    current = current->next;
  }

  return NULL;
}

int main() {
  Employee* head = NULL;

  // Insert employees
  insertEmployee(head, "John Doe", 1, 50000);
  insertEmployee(head, "Jane Doe", 2, 60000);
  insertEmployee(head, "Peter Pan", 3, 70000);

  // Find employee by ID
  Employee* employee = findEmployee(head, 2);

  // Print employee details
  if (employee) {
    printf("Name: %s\n", employee->name);
    printf("ID: %d\n", employee->id);
    printf("Salary: %.2lf\n", employee->salary);
  } else {
    printf("Employee not found.\n");
  }

  return 0;
}