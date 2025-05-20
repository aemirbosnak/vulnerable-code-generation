//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100
#define MAX_CATEGORIES 10

typedef struct {
    char* name;
    char* description;
    double amount;
    char* category;
    struct transaction* next;
} transaction;

typedef struct {
    char* name;
    double budget;
    double actual;
    struct category* next;
} category;

void add_transaction(transaction** head, char* name, char* description, double amount, char* category);
void print_transactions(transaction* head);
void add_category(category** head, char* name, double budget);
void print_categories(category* head);

int main() {
    transaction* transactions = NULL;
    category* categories = NULL;

    // Add some transactions
    add_transaction(&transactions, "Rent", "Rent for March 2023", -1200.00, "Housing");
    add_transaction(&transactions, "Groceries", "Groceries for the week", -50.00, "Food");
    add_transaction(&transactions, "Gas", "Gas for the car", -20.00, "Transportation");

    // Add some categories
    add_category(&categories, "Housing", 1500.00);
    add_category(&categories, "Food", 300.00);
    add_category(&categories, "Transportation", 200.00);

    // Print the transactions
    printf("Transactions:\n");
    print_transactions(transactions);

    // Print the categories
    printf("\nCategories:\n");
    print_categories(categories);

    return 0;
}

void add_transaction(transaction** head, char* name, char* description, double amount, char* category) {
    transaction* new_transaction = malloc(sizeof(transaction));
    new_transaction->name = strdup(name);
    new_transaction->description = strdup(description);
    new_transaction->amount = amount;
    new_transaction->category = strdup(category);
    new_transaction->next = *head;
    *head = new_transaction;
}

void print_transactions(transaction* head) {
    transaction* current = head;
    while (current != NULL) {
        printf("  %s: %s (%.2f) - %s\n", current->name, current->description, current->amount, current->category);
        current = current->next;
    }
}

void add_category(category** head, char* name, double budget) {
    category* new_category = malloc(sizeof(category));
    new_category->name = strdup(name);
    new_category->budget = budget;
    new_category->actual = 0.00;
    new_category->next = *head;
    *head = new_category;
}

void print_categories(category* head) {
    category* current = head;
    while (current != NULL) {
        printf("  %s: %.2f (%.2f)\n", current->name, current->actual, current->budget);
        current = current->next;
    }
}