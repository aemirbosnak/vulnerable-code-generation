//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DATABASE_SIZE 100

typedef struct DatabaseEntry {
  char name[50];
  int age;
  double salary;
  struct DatabaseEntry* next;
} DatabaseEntry;

DatabaseEntry* head = NULL;

void insertEntry(char* name, int age, double salary) {
  DatabaseEntry* newEntry = (DatabaseEntry*)malloc(sizeof(DatabaseEntry));
  strcpy(newEntry->name, name);
  newEntry->age = age;
  newEntry->salary = salary;
  newEntry->next = NULL;

  if (head == NULL) {
    head = newEntry;
  } else {
    head->next = newEntry;
    head = newEntry;
  }
}

void searchEntry(char* name) {
  DatabaseEntry* currentEntry = head;

  while (currentEntry) {
    if (strcmp(currentEntry->name, name) == 0) {
      printf("Name: %s\n", currentEntry->name);
      printf("Age: %d\n", currentEntry->age);
      printf("Salary: %.2lf\n", currentEntry->salary);
      return;
    }
    currentEntry = currentEntry->next;
  }

  printf("Entry not found.\n");
}

int main() {
  insertEntry("John Doe", 25, 50000);
  insertEntry("Jane Doe", 22, 60000);
  insertEntry("Peter Pan", 12, 20000);

  searchEntry("John Doe");
  searchEntry("Jane Doe");
  searchEntry("Peter Pan");
  searchEntry("Bob Smith");

  return 0;
}