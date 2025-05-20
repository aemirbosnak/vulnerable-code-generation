//FormAI DATASET v1.0 Category: Expense Tracker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
  char category[20];
  float amount;
  struct expense *next;
};

void add_expense(struct expense **head, char category[20], float amount) {
  struct expense *new_node = (struct expense *) malloc(sizeof(struct expense));
  strcpy(new_node->category, category);
  new_node->amount = amount;
  new_node->next = NULL;

  if (*head == NULL) {
    *head = new_node;
    printf("New expense added: %s %.2f\n", new_node->category, new_node->amount);
  } else {
    struct expense *curr = *head;
    while (curr->next != NULL) {
      curr = curr->next;
    }
    curr->next = new_node;
    printf("New expense added: %s %.2f\n", new_node->category, new_node->amount);
  }
}

void print_expenses(struct expense *head) {
  if (head == NULL) {
    printf("No expenses to display\n");
  } else {
    printf("--------------------------------\n");
    printf("%-20s     %s\n", "Category", "Amount");
    printf("--------------------------------\n");
    struct expense *curr = head;
    while (curr != NULL) {
      printf("%-20s     %.2f\n", curr->category, curr->amount);
      curr = curr->next;
    }
    printf("--------------------------------\n");
  }
}

int main() {
  struct expense *expenses = NULL;
  char category[20];
  float amount;
  int option;

  do {
    printf("\n1. Add expense\n");
    printf("2. Print expenses\n");
    printf("3. Exit\n");
    printf("Enter option: ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        printf("Enter category: ");
        scanf("%s", category);
        printf("Enter amount: ");
        scanf("%f", &amount);
        add_expense(&expenses, category, amount);
        break;
      case 2:
        print_expenses(expenses);
        break;
      case 3:
        printf("Exiting...\n");
        exit(0);
      default:
        printf("Invalid option\n");
        break;
    }
  } while (option != 3);

  return 0;
}