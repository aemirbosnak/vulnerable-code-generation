//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RECORD_SIZE 1024

typedef struct Record {
  char name[MAX_RECORD_SIZE];
  int account_number;
  double balance;
  struct Record* next;
} Record;

Record* insert_record(Record* head, char* name, int account_number, double balance) {
  Record* new_record = malloc(sizeof(Record));
  strcpy(new_record->name, name);
  new_record->account_number = account_number;
  new_record->balance = balance;
  new_record->next = NULL;

  if (head == NULL) {
    return new_record;
  }

  head->next = new_record;
  return head;
}

void delete_record(Record* head, int account_number) {
  Record* previous = NULL;
  Record* current = head;

  while (current) {
    if (current->account_number == account_number) {
      if (previous) {
        previous->next = current->next;
      } else {
        head = current->next;
      }
      free(current);
      return;
    }

    previous = current;
    current = current->next;
  }

  return;
}

void update_balance(Record* head, int account_number, double new_balance) {
  Record* current = head;

  while (current) {
    if (current->account_number == account_number) {
      current->balance = new_balance;
      return;
    }

    current = current->next;
  }

  return;
}

int main() {
  Record* head = NULL;
  head = insert_record(head, "John Doe", 123456, 1000.0);
  insert_record(head, "Jane Doe", 654321, 2000.0);
  insert_record(head, "Bob Smith", 345213, 3000.0);

  update_balance(head, 123456, 2000.0);
  delete_record(head, 654321);

  Record* current = head;
  while (current) {
    printf("Name: %s, Account Number: %d, Balance: %.2lf\n", current->name, current->account_number, current->balance);
    current = current->next;
  }

  return 0;
}