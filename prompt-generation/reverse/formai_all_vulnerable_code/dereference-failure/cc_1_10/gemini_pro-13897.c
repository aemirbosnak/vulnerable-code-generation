//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

struct Transaction {
    int id;
    int num_items;
    int *items;
};

struct Item {
    int id;
    char *name;
    int support_count;
    int num_transactions;
    struct Transaction **transactions;
};

struct AssociationRule {
    struct Item *antecedent;
    struct Item *consequent;
    double confidence;
    double support;
};

double calculate_support(struct Item *item, int num_transactions) {
    return (double)item->support_count / num_transactions;
}

double calculate_confidence(struct AssociationRule *rule) {
    return (double)rule->antecedent->support_count / rule->consequent->support_count;
}

void print_transaction(struct Transaction *transaction) {
    printf("Transaction ID: %d\n", transaction->id);
    printf("Number of items: %d\n", transaction->num_items);
    for (int i = 0; i < transaction->num_items; i++) {
        printf("Item %d: %d\n", i + 1, transaction->items[i]);
    }
    printf("\n");
}

void print_item(struct Item *item) {
    printf("Item ID: %d\n", item->id);
    printf("Item name: %s\n", item->name);
    printf("Support count: %d\n", item->support_count);
    printf("Number of transactions: %d\n", item->num_transactions);
    for (int i = 0; i < item->num_transactions; i++) {
        print_transaction(item->transactions[i]);
    }
    printf("\n");
}

void print_association_rule(struct AssociationRule *rule) {
    printf("Antecedent: %s\n", rule->antecedent->name);
    printf("Consequent: %s\n", rule->consequent->name);
    printf("Confidence: %.2f%%\n", rule->confidence * 100);
    printf("Support: %.2f%%\n", rule->support * 100);
    printf("\n");
}

int main() {
    // Create a list of transactions.
    struct Transaction transactions[] = {
        {1, 3, {1, 2, 3}},
        {2, 4, {1, 2, 4, 5}},
        {3, 2, {2, 3}},
        {4, 3, {1, 3, 4}},
        {5, 2, {2, 5}}
    };

    // Create a list of items.
    struct Item items[] = {
        {1, "Item 1"},
        {2, "Item 2"},
        {3, "Item 3"},
        {4, "Item 4"},
        {5, "Item 5"}
    };

    // Calculate the support count for each item.
    int num_transactions = sizeof(transactions) / sizeof(transactions[0]);
    for (int i = 0; i < sizeof(items) / sizeof(items[0]); i++) {
        items[i].support_count = 0;
        for (int j = 0; j < num_transactions; j++) {
            for (int k = 0; k < transactions[j].num_items; k++) {
                if (transactions[j].items[k] == items[i].id) {
                    items[i].support_count++;
                    break;
                }
            }
        }
    }

    // Create a list of association rules.
    struct AssociationRule association_rules[] = {
        {{1, "Item 1"}, {2, "Item 2"}, 0.0, 0.0},
        {{1, "Item 1"}, {3, "Item 3"}, 0.0, 0.0},
        {{1, "Item 1"}, {4, "Item 4"}, 0.0, 0.0},
        {{1, "Item 1"}, {5, "Item 5"}, 0.0, 0.0},
        {{2, "Item 2"}, {3, "Item 3"}, 0.0, 0.0},
        {{2, "Item 2"}, {4, "Item 4"}, 0.0, 0.0},
        {{2, "Item 2"}, {5, "Item 5"}, 0.0, 0.0},
        {{3, "Item 3"}, {4, "Item 4"}, 0.0, 0.0},
        {{3, "Item 3"}, {5, "Item 5"}, 0.0, 0.0},
        {{4, "Item 4"}, {5, "Item 5"}, 0.0, 0.0}
    };

    // Calculate the confidence and support for each association rule.
    for (int i = 0; i < sizeof(association_rules) / sizeof(association_rules[0]); i++) {
        association_rules[i].confidence = calculate_confidence(&association_rules[i]);
        association_rules[i].support = calculate_support(association_rules[i].consequent, num_transactions);
    }

    // Print the transactions.
    printf("Transactions:\n");
    for (int i = 0; i < num_transactions; i++) {
        print_transaction(&transactions[i]);
    }

    // Print the items.
    printf("Items:\n");
    for (int i = 0; i < sizeof(items) / sizeof(items[0]); i++) {
        print_item(&items[i]);
    }

    // Print the association rules.
    printf("Association rules:\n");
    for (int i = 0; i < sizeof(association_rules) / sizeof(association_rules[0]); i++) {
        print_association_rule(&association_rules[i]);
    }

    return 0;
}