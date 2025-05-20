//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100

typedef struct {
  char date[11];
  char description[50];
  float amount;
} transaction_t;

typedef struct {
  float income;
  float expenses;
  float balance;
  transaction_t transactions[MAX_TRANSACTIONS];
  int num_transactions;
} finance_t;

void print_help() {
  printf("Usage: finance [command] [arguments]\n");
  printf("Commands:\n");
  printf("  add <amount> <description>\n");
  printf("  list\n");
  printf("  balance\n");
  printf("  quit\n");
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    print_help();
    return 1;
  }

  finance_t finance = {0};

  while (1) {
    if (!strcmp(argv[1], "add")) {
      if (argc < 4) {
        printf("Error: missing arguments\n");
        continue;
      }

      transaction_t transaction;
      strcpy(transaction.date, "2023-03-08"); // Today's date
      strcpy(transaction.description, argv[3]);
      transaction.amount = atof(argv[2]);

      finance.transactions[finance.num_transactions++] = transaction;
      finance.balance += transaction.amount;

      printf("Transaction added\n");
    } else if (!strcmp(argv[1], "list")) {
      for (int i = 0; i < finance.num_transactions; i++) {
        printf("%s %s %f\n", finance.transactions[i].date, finance.transactions[i].description, finance.transactions[i].amount);
      }
    } else if (!strcmp(argv[1], "balance")) {
      printf("Balance: %f\n", finance.balance);
    } else if (!strcmp(argv[1], "quit")) {
      break;
    } else {
      printf("Error: unknown command\n");
    }

    // Get the next command
    argv++;
    argc--;
  }

  return 0;
}