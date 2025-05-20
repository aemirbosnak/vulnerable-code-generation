//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORD_SIZE 100
#define MAX_RECORD_NUM 10

struct Record {
  char name[50];
  int account_number;
  double balance;
  struct Record* next;
};

struct Record* create_record() {
  struct Record* new_record = (struct Record*)malloc(sizeof(struct Record));
  new_record->next = NULL;
  return new_record;
}

void add_record(struct Record* head, char* name, int account_number, double balance) {
  struct Record* new_record = create_record();
  strcpy(new_record->name, name);
  new_record->account_number = account_number;
  new_record->balance = balance;

  if (head == NULL) {
    head = new_record;
  } else {
    new_record->next = head;
    head = new_record;
  }
}

void print_records(struct Record* head) {
  struct Record* current_record = head;
  while (current_record) {
    printf("Name: %s\n", current_record->name);
    printf("Account Number: %d\n", current_record->account_number);
    printf("Balance: %.2lf\n", current_record->balance);
    printf("\n");
    current_record = current_record->next;
  }
}

int main() {
  struct Record* head = NULL;

  add_record(head, "John Doe", 123456, 1000.0);
  add_record(head, "Jane Doe", 654321, 2000.0);
  add_record(head, "Bill Smith", 345268, 3000.0);

  print_records(head);

  return 0;
}