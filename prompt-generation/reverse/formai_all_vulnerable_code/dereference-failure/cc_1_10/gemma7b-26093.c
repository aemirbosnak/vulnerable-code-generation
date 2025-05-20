//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 10

typedef struct Record {
  char name[50];
  int account_no;
  double balance;
  struct Record* next;
} Record;

Record* insert_record(Record* head, char* name, int account_no, double balance) {
  Record* new_record = malloc(sizeof(Record));
  strcpy(new_record->name, name);
  new_record->account_no = account_no;
  new_record->balance = balance;
  new_record->next = NULL;

  if (head == NULL) {
    head = new_record;
  } else {
    head->next = new_record;
  }

  return head;
}

void search_record(Record* head, int account_no) {
  while (head) {
    if (head->account_no == account_no) {
      printf("Name: %s\n", head->name);
      printf("Account No: %d\n", head->account_no);
      printf("Balance: %.2lf\n", head->balance);
      return;
    }
    head = head->next;
  }

  printf("No record found for account number: %d\n", account_no);
}

int main() {
  Record* head = NULL;

  insert_record(head, "Sherlock Holmes", 12345, 10000);
  insert_record(head, "John Watson", 24681, 5000);
  insert_record(head, "Dr. Watson", 36928, 2000);

  search_record(head, 24681);

  return 0;
}