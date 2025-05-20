//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Define the Banking Record System (BRS) structure
typedef struct BRS {
  char name[50];
  int account_number;
  double balance;
  struct BRS *next;
} BRS;

// Function to insert a new record into the BRS
void insert_record(BRS *head) {
  BRS *new_record = (BRS *)malloc(sizeof(BRS));
  printf("Enter your name: ");
  scanf("%s", new_record->name);
  printf("Enter your account number: ");
  scanf("%d", &new_record->account_number);
  printf("Enter your initial balance: ");
  scanf("%lf", &new_record->balance);
  new_record->next = NULL;

  if (head == NULL) {
    head = new_record;
  } else {
    new_record->next = head;
    head = new_record;
  }
}

// Function to display all records in the BRS
void display_records(BRS *head) {
  BRS *current_record = head;

  while (current_record) {
    printf("Name: %s\n", current_record->name);
    printf("Account Number: %d\n", current_record->account_number);
    printf("Balance: %.2lf\n", current_record->balance);
    printf("\n");
    current_record = current_record->next;
  }
}

// Function to search for a record in the BRS
void search_record(BRS *head) {
  BRS *current_record = head;
  int account_number;

  printf("Enter the account number of the record you want to find: ");
  scanf("%d", &account_number);

  while (current_record) {
    if (current_record->account_number == account_number) {
      printf("Name: %s\n", current_record->name);
      printf("Account Number: %d\n", current_record->account_number);
      printf("Balance: %.2lf\n", current_record->balance);
      break;
    }
    current_record = current_record->next;
  }

  if (current_record == NULL) {
    printf("No record found.\n");
  }
}

int main() {
  BRS *head = NULL;

  // Insert a new record
  insert_record(head);

  // Insert another new record
  insert_record(head);

  // Display all records
  display_records(head);

  // Search for a record
  search_record(head);

  return 0;
}