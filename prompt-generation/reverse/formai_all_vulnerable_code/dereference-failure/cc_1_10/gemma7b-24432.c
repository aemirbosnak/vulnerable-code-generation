//Gemma-7B DATASET v1.0 Category: Database querying ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_RECORDS 100

typedef struct Record {
  char name[50];
  int age;
  double salary;
  struct Record* next;
} Record;

Record* insertRecord(Record* head, char* name, int age, double salary) {
  Record* newRecord = malloc(sizeof(Record));
  strcpy(newRecord->name, name);
  newRecord->age = age;
  newRecord->salary = salary;
  newRecord->next = NULL;

  if (head == NULL) {
    return newRecord;
  }

  head->next = newRecord;
  return newRecord;
}

Record* searchRecord(Record* head, char* name) {
  while (head) {
    if (strcmp(head->name, name) == 0) {
      return head;
    }
    head = head->next;
  }

  return NULL;
}

int main() {
  Record* head = NULL;
  head = insertRecord(head, "John Doe", 25, 50000);
  head = insertRecord(head, "Jane Doe", 30, 60000);
  head = insertRecord(head, "Jack Doe", 40, 70000);

  Record* foundRecord = searchRecord(head, "Jane Doe");
  if (foundRecord) {
    printf("Name: %s\n", foundRecord->name);
    printf("Age: %d\n", foundRecord->age);
    printf("Salary: %.2lf\n", foundRecord->salary);
  } else {
    printf("Record not found.\n");
  }

  return 0;
}