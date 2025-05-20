//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct Record {
  char name[50];
  int age;
  struct Record* next;
} Record;

Record* insertRecord(Record* head, char* name, int age) {
  Record* newRecord = (Record*)malloc(sizeof(Record));
  strcpy(newRecord->name, name);
  newRecord->age = age;
  newRecord->next = NULL;

  if (head == NULL) {
    head = newRecord;
  } else {
    head->next = newRecord;
  }

  return head;
}

void searchRecord(Record* head, char* name) {
  while (head) {
    if (strcmp(head->name, name) == 0) {
      printf("Name: %s, Age: %d\n", head->name, head->age);
      return;
    }
    head = head->next;
  }

  printf("Record not found.\n");
}

int main() {
  Record* head = NULL;

  insertRecord(head, "John Doe", 30);
  insertRecord(head, "Jane Doe", 25);
  insertRecord(head, "Mike Smith", 40);

  searchRecord(head, "Jane Doe");

  return 0;
}