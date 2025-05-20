//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct Record {
  char name[50];
  char address[100];
  char phone[20];
  struct Record* next;
} Record;

Record* head = NULL;

void insertRecord(char* name, char* address, char* phone) {
  Record* newRecord = (Record*)malloc(sizeof(Record));
  strcpy(newRecord->name, name);
  strcpy(newRecord->address, address);
  strcpy(newRecord->phone, phone);
  newRecord->next = NULL;

  if (head == NULL) {
    head = newRecord;
  } else {
    Record* temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newRecord;
  }
}

void searchRecord(char* name) {
  Record* temp = head;
  while (temp) {
    if (strcmp(temp->name, name) == 0) {
      printf("Name: %s\n", temp->name);
      printf("Address: %s\n", temp->address);
      printf("Phone: %s\n", temp->phone);
      return;
    }
    temp = temp->next;
  }
  printf("Record not found.\n");
}

int main() {
  insertRecord("Sherlock Holmes", "221B Baker St.", "020 1234 5678");
  insertRecord("John Watson", "221B Baker St.", "020 5468 9241");
  insertRecord("Dr. Watson", "221B Baker St.", "020 1234 5678");
  insertRecord("Mr. Gregson", "124B Park St.", "020 4123 6842");

  searchRecord("Mr. Gregson");

  return 0;
}