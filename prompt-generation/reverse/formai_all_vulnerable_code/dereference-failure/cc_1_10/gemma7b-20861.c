//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct Record {
  char name[20];
  int account_number;
  double balance;
  struct Record* next;
} Record;

Record* create_record(char* name, int account_number, double balance) {
  Record* new_record = (Record*)malloc(sizeof(Record));
  strcpy(new_record->name, name);
  new_record->account_number = account_number;
  new_record->balance = balance;
  new_record->next = NULL;
  return new_record;
}

void print_records(Record* head) {
  while (head) {
    printf("%s (%d) - Balance: %.2lf\n", head->name, head->account_number, head->balance);
    head = head->next;
  }
}

void search_records(Record* head, char* name) {
  while (head) {
    if (strcmp(head->name, name) == 0) {
      printf("%s (%d) - Balance: %.2lf\n", head->name, head->account_number, head->balance);
      return;
    }
    head = head->next;
  }
  printf("Record not found.\n");
}

int main() {
  Record* head = NULL;
  head = create_record("John Doe", 123456, 1000.0);
  head = create_record("Jane Doe", 654321, 2000.0);
  head = create_record("Peter Pan", 984123, 3000.0);

  print_records(head);

  search_records(head, "Jane Doe");

  return 0;
}