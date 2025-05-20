//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 255

typedef struct PersonalFinanceRecord {
  char name[MAX_NAME_LENGTH];
  int account_number;
  double balance;
  double income;
  double expenses;
  struct PersonalFinanceRecord* next;
} PersonalFinanceRecord;

PersonalFinanceRecord* insert_record(PersonalFinanceRecord* head, char* name, int account_number, double balance, double income, double expenses) {
  PersonalFinanceRecord* new_record = malloc(sizeof(PersonalFinanceRecord));

  strcpy(new_record->name, name);
  new_record->account_number = account_number;
  new_record->balance = balance;
  new_record->income = income;
  new_record->expenses = expenses;
  new_record->next = NULL;

  if (head == NULL) {
    head = new_record;
  } else {
    head->next = new_record;
  }

  return head;
}

void print_records(PersonalFinanceRecord* head) {
  PersonalFinanceRecord* current_record = head;

  while (current_record) {
    printf("Name: %s\n", current_record->name);
    printf("Account Number: %d\n", current_record->account_number);
    printf("Balance: %.2lf\n", current_record->balance);
    printf("Income: %.2lf\n", current_record->income);
    printf("Expenses: %.2lf\n", current_record->expenses);
    printf("\n");
    current_record = current_record->next;
  }
}

int main() {
  PersonalFinanceRecord* head = NULL;

  insert_record(head, "John Doe", 123456, 1000.0, 2000.0, 500.0);
  insert_record(head, "Jane Doe", 654321, 2000.0, 3000.0, 700.0);
  insert_record(head, "Mike Smith", 342168, 3000.0, 4000.0, 900.0);

  print_records(head);

  return 0;
}