//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the main data structures
typedef struct {
  char *name;
  double balance;
} account_t;

typedef struct {
  char *name;
  double income;
  double expenses;
  account_t *accounts;
  int num_accounts;
} person_t;

// Create a new person
person_t *new_person(char *name) {
  person_t *p = malloc(sizeof(person_t));
  p->name = strdup(name);
  p->income = 0;
  p->expenses = 0;
  p->accounts = NULL;
  p->num_accounts = 0;
  return p;
}

// Free the memory allocated for a person
void free_person(person_t *p) {
  free(p->name);
  for (int i = 0; i < p->num_accounts; i++) {
    free(p->accounts[i].name);
  }
  free(p->accounts);
  free(p);
}

// Add an account to a person
void add_account(person_t *p, char *name, double balance) {
  p->accounts = realloc(p->accounts, (p->num_accounts + 1) * sizeof(account_t));
  p->accounts[p->num_accounts].name = strdup(name);
  p->accounts[p->num_accounts].balance = balance;
  p->num_accounts++;
}

// Print the details of a person
void print_person(person_t *p) {
  printf("Name: %s\n", p->name);
  printf("Income: %.2f\n", p->income);
  printf("Expenses: %.2f\n", p->expenses);
  printf("Accounts:\n");
  for (int i = 0; i < p->num_accounts; i++) {
    printf("  %s: %.2f\n", p->accounts[i].name, p->accounts[i].balance);
  }
}

// Main function
int main() {
  // Create a new person
  person_t *p = new_person("John Doe");

  // Add some income and expenses
  p->income = 5000;
  p->expenses = 3000;

  // Add some accounts
  add_account(p, "Checking", 1000);
  add_account(p, "Savings", 2000);

  // Print the details of the person
  print_person(p);

  // Free the memory allocated for the person
  free_person(p);

  return 0;
}