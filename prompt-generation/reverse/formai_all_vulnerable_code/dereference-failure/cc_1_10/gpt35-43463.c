//FormAI DATASET v1.0 Category: Database simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Employee {
   int id;
   char name[20];
   char department[20];
   double salary;
} Employee;

Employee* database[MAX_SIZE];
int size = 0;

void add_employee(int id, char* name, char* department, double salary) {
   Employee* new_employee = (Employee*) malloc(sizeof(Employee));
   new_employee->id = id;
   strcpy(new_employee->name, name);
   strcpy(new_employee->department, department);
   new_employee->salary = salary;
   database[size++] = new_employee;
}

void delete_employee(int id) {
   int index = -1;
   for (int i=0; i<size; i++) {
      if (database[i]->id == id) {
         index = i;
         break;
      }
   }
   if (index != -1) {
      free(database[index]);
      for (int i=index; i<size-1; i++) {
         database[i] = database[i+1];
      }
      size--;
   }
}

void print_database() {
   printf("ID\tName\tDepartment\tSalary\n");
   for (int i=0; i<size; i++) {
      printf("%d\t%s\t%s\t%.2f\n", database[i]->id, database[i]->name, 
         database[i]->department, database[i]->salary);
   }
}

int main() {
   add_employee(1001, "John Doe", "Sales", 5000.0);
   add_employee(1002, "Jane Doe", "Accounting", 6000.0);
   add_employee(1003, "Bob Smith", "Marketing", 5500.0);
   print_database();
   delete_employee(1002);
   printf("\nAfter deleting employee with ID 1002:\n");
   print_database();
   return 0;
}