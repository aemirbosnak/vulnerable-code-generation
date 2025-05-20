//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_TRANSACTIONS 100

// Structure to store a category
typedef struct {
    char name[50];
    double budget;
    double balance;
} Category;

// Structure to store a transaction
typedef struct {
    char date[11];
    char description[100];
    double amount;
    int category;
} Transaction;

// Function to create a new category
Category* create_category(char* name, double budget) {
    Category* category = malloc(sizeof(Category));
    strcpy(category->name, name);
    category->budget = budget;
    category->balance = 0;
    return category;
}

// Function to add a transaction to a category
void add_transaction(Category* category, Transaction* transaction) {
    category->balance += transaction->amount;
}

// Function to print a category
void print_category(Category* category) {
    printf("%s: $%.2f / $%.2f\n", category->name, category->balance, category->budget);
}

// Function to print a transaction
void print_transaction(Transaction* transaction) {
    printf("%s: %s: $%.2f\n", transaction->date, transaction->description, transaction->amount);
}

// Function to read a line from a file
char* read_line(FILE* file) {
    char* line = malloc(1024);
    fgets(line, 1024, file);
    return line;
}

// Function to parse a transaction
Transaction* parse_transaction(char* line) {
    Transaction* transaction = malloc(sizeof(Transaction));
    char* tokens[4];
    strtok(line, ",");
    for (int i = 0; i < 4; i++) {
        tokens[i] = strtok(NULL, ",");
    }
    strcpy(transaction->date, tokens[0]);
    strcpy(transaction->description, tokens[1]);
    transaction->amount = atof(tokens[2]);
    transaction->category = atoi(tokens[3]);
    return transaction;
}

// Function to load transactions from a file
Transaction** load_transactions(char* filename, int* num_transactions) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }
    char* line = read_line(file);
    *num_transactions = atoi(line);
    Transaction** transactions = malloc(*num_transactions * sizeof(Transaction*));
    for (int i = 0; i < *num_transactions; i++) {
        line = read_line(file);
        transactions[i] = parse_transaction(line);
    }
    fclose(file);
    return transactions;
}

// Function to create categories from a file
Category** create_categories(char* filename, int* num_categories) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }
    char* line = read_line(file);
    *num_categories = atoi(line);
    Category** categories = malloc(*num_categories * sizeof(Category*));
    for (int i = 0; i < *num_categories; i++) {
        line = read_line(file);
        char* tokens[2];
        strtok(line, ",");
        for (int j = 0; j < 2; j++) {
            tokens[j] = strtok(NULL, ",");
        }
        categories[i] = create_category(tokens[0], atof(tokens[1]));
    }
    fclose(file);
    return categories;
}

// Function to assign transactions to categories
void assign_transactions(Category** categories, int num_categories, Transaction** transactions, int num_transactions) {
    for (int i = 0; i < num_transactions; i++) {
        add_transaction(categories[transactions[i]->category], transactions[i]);
    }
}

// Function to print a report
void print_report(Category** categories, int num_categories) {
    for (int i = 0; i < num_categories; i++) {
        print_category(categories[i]);
    }
}

// Function to free memory
void free_memory(Category** categories, int num_categories, Transaction** transactions, int num_transactions) {
    for (int i = 0; i < num_categories; i++) {
        free(categories[i]);
    }
    free(categories);
    for (int i = 0; i < num_transactions; i++) {
        free(transactions[i]);
    }
    free(transactions);
}

// Main function
int main() {
    int num_categories, num_transactions;
    Category** categories = create_categories("categories.csv", &num_categories);
    Transaction** transactions = load_transactions("transactions.csv", &num_transactions);
    assign_transactions(categories, num_categories, transactions, num_transactions);
    print_report(categories, num_categories);
    free_memory(categories, num_categories, transactions, num_transactions);
    return 0;
}