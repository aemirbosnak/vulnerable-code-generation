//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char name[50];
    float amount;
    struct Node *next;
} Transaction;

typedef struct Node {
    Transaction data;
    struct Node *next;
} Node;

Node *head = NULL;
float income_total = 0.0;
float expense_total = 0.0;
float savings_total = 0.0;
float current_balance = 0.0;

void add_transaction(char *name, float amount, bool is_income) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    Transaction new_transaction;

    strcpy(new_transaction.name, name);
    new_transaction.amount = amount;

    new_node->data = new_transaction;
    new_node->next = head;
    head = new_node;

    if (is_income) {
        income_total += amount;
        current_balance += amount;
    } else {
        expense_total += amount;
        current_balance -= amount;
    }
}

void print_transactions() {
    Node *current = head;

    printf("\n--- TRANSACTIONS ---\n");
    printf("| Name             | Amount |\n");
    printf("|------------------|--------|\n");

    while (current != NULL) {
        printf("| %-50s | %.2f |\n", current->data.name, current->data.amount);
        current = current->next;
    }

    printf("|------------------|--------|\n");
}

void print_reports() {
    printf("\n--- REPORTS ---\n");
    printf("|                  | Total  |\n");
    printf("|------------------|--------|\n");
    printf("| Income           | %.2f  |\n", income_total);
    printf("| Expenses         | %.2f  |\n", expense_total);
    printf("| Savings          | %.2f  |\n", savings_total);
    printf("| Current Balance  | %.2f  |\n", current_balance);
    printf("|------------------|--------|\n");
}

int main() {
    char name[50];
    float amount;
    bool is_income;

    while (true) {
        printf("Enter transaction name (or 'q' to quit): ");
        scanf("%s", name);

        if (strcmp(name, "q") == 0) {
            break;
        }

        printf("Enter transaction amount: ");
        scanf("%f", &amount);

        printf("Is this an income or expense (i/e)? ");
        scanf("%c", &is_income);

        add_transaction(name, amount, is_income == 'i');
    }

    print_transactions();
    print_reports();

    return 0;
}