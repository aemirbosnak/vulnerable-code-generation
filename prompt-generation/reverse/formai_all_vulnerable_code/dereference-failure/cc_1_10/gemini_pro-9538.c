//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *name;
    double amount;
} entry_t;

typedef struct {
    int num_entries;
    entry_t *entries;
} ledger_t;

void add_entry(ledger_t *ledger, char *name, double amount) {
    ledger->entries = realloc(ledger->entries, (ledger->num_entries + 1) * sizeof(entry_t));
    ledger->entries[ledger->num_entries].name = strdup(name);
    ledger->entries[ledger->num_entries].amount = amount;
    ledger->num_entries++;
}

void print_ledger(ledger_t *ledger) {
    for (int i = 0; i < ledger->num_entries; i++) {
        printf("%s: %.2f\n", ledger->entries[i].name, ledger->entries[i].amount);
    }
}

void free_ledger(ledger_t *ledger) {
    for (int i = 0; i < ledger->num_entries; i++) {
        free(ledger->entries[i].name);
    }
    free(ledger->entries);
    free(ledger);
}

int main() {
    ledger_t *ledger = malloc(sizeof(ledger_t));
    ledger->num_entries = 0;
    ledger->entries = NULL;

    add_entry(ledger, "Salary", 2500.00);
    add_entry(ledger, "Rent", -1000.00);
    add_entry(ledger, "Groceries", -200.00);
    add_entry(ledger, "Entertainment", -100.00);
    add_entry(ledger, "Savings", 500.00);

    print_ledger(ledger);

    free_ledger(ledger);

    return 0;
}