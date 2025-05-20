//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100
#define MAX_CATEGORIES 10

typedef struct {
    char category[30];
    double amount;
} Transaction;

typedef struct {
    char name[30];
    double budget;
    Transaction transactions[MAX_TRANSACTIONS];
    int transaction_count;
} User;

void addTransaction(User *user) {
    if (user->transaction_count >= MAX_TRANSACTIONS) {
        printf("Transaction limit reached!\n");
        return;
    }
    Transaction new_transaction;
    printf("Enter category: ");
    getchar(); // clear buffer
    fgets(new_transaction.category, 30, stdin);
    new_transaction.category[strcspn(new_transaction.category, "\n")] = 0; // remove newline

    printf("Enter amount: ");
    scanf("%lf", &new_transaction.amount);

    user->transactions[user->transaction_count++] = new_transaction;
}

void viewTransactions(User *user) {
    printf("\n--- Transactions for %s ---\n", user->name);
    for (int i = 0; i < user->transaction_count; i++) {
        printf("Category: %s | Amount: %.2f\n", user->transactions[i].category, user->transactions[i].amount);
    }
    printf("--- End of Transactions ---\n\n");
}

void viewBudget(User *user) {
    printf("\n--- Budget for %s ---\n", user->name);
    printf("Total Budget: %.2f\n", user->budget);
    printf("--- End of Budget ---\n\n");
}

void updateBudget(User *user) {
    printf("Current Budget: %.2f\n", user->budget);
    printf("Enter new budget: ");
    scanf("%lf", &user->budget);
}

void summary(User *user) {
    double total_spent = 0.0;
    for (int i = 0; i < user->transaction_count; i++) {
        total_spent += user->transactions[i].amount;
    }
    double remaining_budget = user->budget - total_spent;

    printf("\n--- Summary for %s ---\n", user->name);
    printf("Total Spent: %.2f\n", total_spent);
    printf("Remaining Budget: %.2f\n", remaining_budget);
    printf("--- End of Summary ---\n\n");
}

void displayMenu() {
    printf("1. Add Transaction\n");
    printf("2. View Transactions\n");
    printf("3. Update Budget\n");
    printf("4. View Budget\n");
    printf("5. Summary\n");
    printf("6. Exit\n");
}

int main() {
    User user;
    user.transaction_count = 0;

    printf("Welcome to your Personal Finance Planner!\n");
    printf("Enter your name: ");
    fgets(user.name, 30, stdin);
    user.name[strcspn(user.name, "\n")] = 0; // trim newline
    printf("Enter your budget: ");
    scanf("%lf", &user.budget);

    int option;
    do {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addTransaction(&user);
                break;
            case 2:
                viewTransactions(&user);
                break;
            case 3:
                updateBudget(&user);
                break;
            case 4:
                viewBudget(&user);
                break;
            case 5:
                summary(&user);
                break;
            case 6:
                printf("Exiting the planner...\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (option != 6);

    return 0;
}