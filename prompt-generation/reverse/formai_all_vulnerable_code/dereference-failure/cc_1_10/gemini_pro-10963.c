//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int value;
} entry;

typedef struct {
    char *name;
    int size;
    entry *entries;
} ledger;

ledger *create_ledger(char *name) {
    ledger *l = malloc(sizeof(ledger));
    l->name = strdup(name);
    l->size = 0;
    l->entries = NULL;
    return l;
}

entry *create_entry(char *name, int value) {
    entry *e = malloc(sizeof(entry));
    e->name = strdup(name);
    e->value = value;
    return e;
}

void add_entry(ledger *l, entry *e) {
    l->entries = realloc(l->entries, (l->size + 1) * sizeof(entry));
    l->entries[l->size++] = *e;
}

void print_ledger(ledger *l) {
    printf("Ledger: %s\n", l->name);
    for (int i = 0; i < l->size; i++) {
        printf("\t%s: %d\n", l->entries[i].name, l->entries[i].value);
    }
}

int main() {
    ledger *l = create_ledger("My Ledger");
    add_entry(l, create_entry("Income", 1000));
    add_entry(l, create_entry("Expenses", -500));
    add_entry(l, create_entry("Savings", 250));
    print_ledger(l);
    return 0;
}