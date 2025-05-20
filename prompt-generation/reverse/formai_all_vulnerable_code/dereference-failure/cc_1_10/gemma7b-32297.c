//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of categories
#define MAX_CATEGORIES 10

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the categories structure
typedef struct Category {
    char name[20];
    int total_amount;
    struct Category* next;
} Category;

// Define the transactions structure
typedef struct Transaction {
    char description[50];
    int amount;
    struct Transaction* next;
} Transaction;

// Function to insert a category
void insert_category(Category** head, char* name, int total_amount) {
    Category* new_category = (Category*)malloc(sizeof(Category));
    strcpy(new_category->name, name);
    new_category->total_amount = total_amount;
    new_category->next = NULL;

    if (*head == NULL) {
        *head = new_category;
    } else {
        (*head)->next = new_category;
    }
}

// Function to insert a transaction
void insert_transaction(Transaction** head, char* description, int amount) {
    Transaction* new_transaction = (Transaction*)malloc(sizeof(Transaction));
    strcpy(new_transaction->description, description);
    new_transaction->amount = amount;
    new_transaction->next = NULL;

    if (*head == NULL) {
        *head = new_transaction;
    } else {
        (*head)->next = new_transaction;
    }
}

// Function to calculate total spending
int calculate_total_spending(Transaction* head) {
    int total_spending = 0;
    while (head) {
        total_spending += head->amount;
        head = head->next;
    }
    return total_spending;
}

// Function to calculate total income
int calculate_total_income(Transaction* head) {
    int total_income = 0;
    while (head) {
        if (head->amount > 0) {
            total_income += head->amount;
        }
        head = head->next;
    }
    return total_income;
}

// Function to display categories
void display_categories(Category* head) {
    while (head) {
        printf("%s: %d\n", head->name, head->total_amount);
        head = head->next;
    }
}

// Function to display transactions
void display_transactions(Transaction* head) {
    while (head) {
        printf("%s: %d\n", head->description, head->amount);
        head = head->next;
    }
}

int main() {
    // Create a list of categories
    Category* categories = NULL;
    insert_category(&categories, "Groceries", 500);
    insert_category(&categories, "Eating out", 200);
    insert_category(&categories, "Clothing", 100);

    // Create a list of transactions
    Transaction* transactions = NULL;
    insert_transaction(&transactions, "Bought groceries for $200", 200);
    insert_transaction(&transactions, "Eaten out at a restaurant for $50", -50);
    insert_transaction(&transactions, "Bought a new shirt for $25", 25);

    // Calculate total spending and income
    int total_spending = calculate_total_spending(transactions);
    int total_income = calculate_total_income(transactions);

    // Display categories and transactions
    display_categories(categories);
    display_transactions(transactions);

    // Display total spending and income
    printf("Total spending: $%d\n", total_spending);
    printf("Total income: $%d\n", total_income);

    return 0;
}