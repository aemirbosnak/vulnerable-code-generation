//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct Record {
  char name[50];
  char account_number[20];
  int account_balance;
  struct Record* next;
} Record;

Record* head = NULL;

void add_record(char* name, char* account_number, int account_balance) {
  Record* new_record = (Record*)malloc(sizeof(Record));
  strcpy(new_record->name, name);
  strcpy(new_record->account_number, account_number);
  new_record->account_balance = account_balance;
  new_record->next = NULL;

  if (head == NULL) {
    head = new_record;
  } else {
    Record* last_record = head;
    while (last_record->next != NULL) {
      last_record = last_record->next;
    }
    last_record->next = new_record;
  }
}

void print_records() {
  Record* current_record = head;
  while (current_record) {
    printf("Name: %s\n", current_record->name);
    printf("Account Number: %s\n", current_record->account_number);
    printf("Account Balance: %d\n", current_record->account_balance);
    printf("\n");
    current_record = current_record->next;
  }
}

int main() {
  add_record("John Doe", "123456", 1000);
  add_record("Jane Doe", "456789", 2000);
  add_record("Bill Smith", "369281", 3000);

  print_records();

  return 0;
}