//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Create a struct to store the account details
typedef struct account {
  int account_number;
  char *name;
  double balance;
} account_t;

// Create a linked list to store the accounts
typedef struct node {
  account_t *data;
  struct node *next;
} node_t;

// Create a function to create a new account
node_t *create_account(int account_number, char *name, double balance) {
  // Allocate memory for the new account
  account_t *new_account = (account_t *)malloc(sizeof(account_t));
  if (new_account == NULL) {
    printf("Error: Could not allocate memory for new account.\n");
    return NULL;
  }

  // Initialize the new account
  new_account->account_number = account_number;
  new_account->name = name;
  new_account->balance = balance;

  // Allocate memory for the new node
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  if (new_node == NULL) {
    printf("Error: Could not allocate memory for new node.\n");
    free(new_account);
    return NULL;
  }

  // Initialize the new node
  new_node->data = new_account;
  new_node->next = NULL;

  return new_node;
}

// Create a function to insert a new account into the linked list
void insert_account(node_t **head, node_t *new_node) {
  if (*head == NULL) {
    // The linked list is empty, so the new node becomes the head
    *head = new_node;
  } else {
    // The linked list is not empty, so we need to find the last node and insert the new node after it
    node_t *current_node = *head;
    while (current_node->next != NULL) {
      current_node = current_node->next;
    }
    current_node->next = new_node;
  }
}

// Create a function to search for an account by account number
node_t *search_account(node_t *head, int account_number) {
  node_t *current_node = head;
  while (current_node != NULL) {
    if (current_node->data->account_number == account_number) {
      return current_node;
    }
    current_node = current_node->next;
  }
  return NULL;
}

// Create a function to deposit money into an account
void deposit_money(node_t *account, double amount) {
  account->data->balance += amount;
}

// Create a function to withdraw money from an account
void withdraw_money(node_t *account, double amount) {
  if (account->data->balance >= amount) {
    account->data->balance -= amount;
  } else {
    printf("Error: Insufficient funds.\n");
  }
}

// Create a function to print the details of an account
void print_account(node_t *account) {
  printf("Account number: %d\n", account->data->account_number);
  printf("Name: %s\n", account->data->name);
  printf("Balance: %.2f\n", account->data->balance);
}

// Create a function to destroy the linked list
void destroy_list(node_t *head) {
  node_t *current_node = head;
  while (current_node != NULL) {
    node_t *next_node = current_node->next;
    free(current_node->data);
    free(current_node);
    current_node = next_node;
  }
}

// Create a function to test the banking record system
void test_banking_record_system() {
  // Create a linked list to store the accounts
  node_t *head = NULL;

  // Create a few accounts
  node_t *account1 = create_account(123456, "John Doe", 1000.00);
  insert_account(&head, account1);
  node_t *account2 = create_account(654321, "Jane Doe", 2000.00);
  insert_account(&head, account2);

  // Search for an account by account number
  node_t *found_account = search_account(head, 123456);
  if (found_account != NULL) {
    printf("Found account:\n");
    print_account(found_account);
  } else {
    printf("Account not found.\n");
  }

  // Deposit money into an account
  deposit_money(account1, 500.00);
  printf("Deposited $500.00 into account 123456.\n");

  // Withdraw money from an account
  withdraw_money(account2, 1000.00);
  printf("Withdrew $1000.00 from account 654321.\n");

  // Print the details of an account
  print_account(account1);

  // Destroy the linked list
  destroy_list(head);
}

// Main function
int main() {
  test_banking_record_system();
  return 0;
}