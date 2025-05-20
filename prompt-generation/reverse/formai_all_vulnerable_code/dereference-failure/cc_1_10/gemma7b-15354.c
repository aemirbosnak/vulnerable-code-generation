//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Transaction {
  char name[MAX];
  int amount;
  char type;
  struct Transaction* next;
};

struct Budget {
  char category[MAX];
  int target_amount;
  struct Budget* next;
};

void add_transaction(struct Transaction** head, char* name, int amount, char type) {
  struct Transaction* new_trans = malloc(sizeof(struct Transaction));
  strcpy(new_trans->name, name);
  new_trans->amount = amount;
  new_trans->type = type;
  new_trans->next = NULL;

  if (*head == NULL) {
    *head = new_trans;
  } else {
    (*head)->next = new_trans;
  }
}

void add_budget(struct Budget** head, char* category, int target_amount) {
  struct Budget* new_budget = malloc(sizeof(struct Budget));
  strcpy(new_budget->category, category);
  new_budget->target_amount = target_amount;
  new_budget->next = NULL;

  if (*head == NULL) {
    *head = new_budget;
  } else {
    (*head)->next = new_budget;
  }
}

int main() {
  struct Transaction* head_trans = NULL;
  struct Budget* head_budget = NULL;

  add_transaction(&head_trans, "Groceries", 50, 'D');
  add_transaction(&head_trans, "Eating Out", 20, 'C');
  add_transaction(&head_trans, "Clothing", 30, 'S');

  add_budget(&head_budget, "Food", 100);
  add_budget(&head_budget, "Entertainment", 50);
  add_budget(&head_budget, "Clothing", 20);

  printf("Transactions:\n");
  for (struct Transaction* current = head_trans; current; current = current->next) {
    printf("%s: %d, %c\n", current->name, current->amount, current->type);
  }

  printf("Budgets:\n");
  for (struct Budget* current = head_budget; current; current = current->next) {
    printf("%s: %d\n", current->category, current->target_amount);
  }

  return 0;
}