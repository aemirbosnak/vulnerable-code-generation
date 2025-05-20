//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define MAX_RECORD_SIZE 1024

typedef struct Record {
  char name[MAX_RECORD_SIZE];
  int account_number;
  double balance;
  struct Record* next;
} Record;

Record* InsertRecord(Record* head, char* name, int account_number, double balance) {
  Record* new_record = malloc(sizeof(Record));
  strcpy(new_record->name, name);
  new_record->account_number = account_number;
  new_record->balance = balance;
  new_record->next = NULL;

  if (head == NULL) {
    head = new_record;
  } else {
    head->next = new_record;
  }

  return head;
}

void PrintRecords(Record* head) {
  Record* current_record = head;
  while (current_record) {
    printf("Name: %s, Account Number: %d, Balance: %.2lf\n", current_record->name, current_record->account_number, current_record->balance);
    current_record = current_record->next;
  }
}

int main() {
  Record* head = NULL;

  // Insert records
  InsertRecord(head, "John Doe", 123456, 1000.0);
  InsertRecord(head, "Jane Doe", 654912, 2000.0);
  InsertRecord(head, "Bob Smith", 348269, 3000.0);

  // Print records
  PrintRecords(head);

  return 0;
}