//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *description;
    float amount;
    struct tm *date;
} Transaction;

typedef struct {
    int num_transactions;
    Transaction *transactions;
} ExpenseTracker;

void add_transaction(ExpenseTracker *tracker, const char *description, float amount, struct tm *date) {
    tracker->transactions = realloc(tracker->transactions, sizeof(Transaction) * (tracker->num_transactions + 1));
    tracker->transactions[tracker->num_transactions].description = strdup(description);
    tracker->transactions[tracker->num_transactions].amount = amount;
    tracker->transactions[tracker->num_transactions].date = date;
    tracker->num_transactions++;
}

void print_transactions(const ExpenseTracker *tracker) {
    for (int i = 0; i < tracker->num_transactions; i++) {
        printf("%s: %.2f\n", tracker->transactions[i].description, tracker->transactions[i].amount);
    }
}

void free_transactions(ExpenseTracker *tracker) {
    for (int i = 0; i < tracker->num_transactions; i++) {
        free(tracker->transactions[i].description);
    }
    free(tracker->transactions);
}

int main() {
    ExpenseTracker tracker = {0};

    // Add some sample transactions
    add_transaction(&tracker, "Groceries", 100.0, localtime(NULL));
    add_transaction(&tracker, "Gas", 50.0, localtime(NULL));
    add_transaction(&tracker, "Rent", 1200.0, localtime(NULL));

    // Print the transactions
    print_transactions(&tracker);

    // Free the memory allocated for the transactions
    free_transactions(&tracker);

    return 0;
}