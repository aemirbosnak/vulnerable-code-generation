//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 10

typedef struct {
  char name[50];
  int age;
  float salary;
} Employee;

typedef struct {
  Employee employees[MAX_ROWS];
  int num_rows;
  int num_cols;
} Database;

Database* create_database() {
  Database* db = malloc(sizeof(Database));
  db->num_rows = 0;
  db->num_cols = 3;
  return db;
}

void destroy_database(Database* db) {
  free(db);
}

int add_employee(Database* db, Employee* employee) {
  if (db->num_rows >= MAX_ROWS) {
    return -1;
  }
  db->employees[db->num_rows++] = *employee;
  return 0;
}

int remove_employee(Database* db, int index) {
  if (index < 0 || index >= db->num_rows) {
    return -1;
  }
  for (int i = index + 1; i < db->num_rows; i++) {
    db->employees[i - 1] = db->employees[i];
  }
  db->num_rows--;
  return 0;
}

Employee* get_employee(Database* db, int index) {
  if (index < 0 || index >= db->num_rows) {
    return NULL;
  }
  return &db->employees[index];
}

int main() {
  Database* db = create_database();

  Employee employee1 = {"John Doe", 30, 50000.0};
  Employee employee2 = {"Jane Doe", 25, 40000.0};
  Employee employee3 = {"Bob Smith", 40, 60000.0};

  add_employee(db, &employee1);
  add_employee(db, &employee2);
  add_employee(db, &employee3);

  Employee* employee = get_employee(db, 1);
  printf("Employee: %s, %d, %f\n", employee->name, employee->age, employee->salary);

  remove_employee(db, 1);

  employee = get_employee(db, 1);
  printf("Employee: %s, %d, %f\n", employee->name, employee->age, employee->salary);

  destroy_database(db);

  return 0;
}