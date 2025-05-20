//Falcon-180B DATASET v1.0 Category: Data mining ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 1000000
#define MAX_CATEGORIES 1000
#define MAX_TRANSACTIONS 1000000
#define MAX_RULES 1000

typedef struct {
    int id;
    char name[50];
    int category;
} item_t;

typedef struct {
    int id;
    char name[50];
} category_t;

typedef struct {
    int item1;
    int item2;
    int count;
} transaction_t;

typedef struct {
    int count;
    int confidence;
    int lift;
} rule_t;

item_t items[MAX_ITEMS];
category_t categories[MAX_CATEGORIES];
transaction_t transactions[MAX_TRANSACTIONS];
rule_t rules[MAX_RULES];

int num_items = 0;
int num_categories = 0;
int num_transactions = 0;
int num_rules = 0;

void generate_data(int num_items, int num_categories, int num_transactions) {
    srand(time(NULL));

    for (int i = 0; i < num_items; i++) {
        items[i].id = i;
        items[i].category = rand() % num_categories;
        sprintf(items[i].name, "Item %d", i);
    }

    for (int i = 0; i < num_categories; i++) {
        categories[i].id = i;
        sprintf(categories[i].name, "Category %d", i);
    }

    for (int i = 0; i < num_transactions; i++) {
        transactions[i].item1 = rand() % num_items;
        transactions[i].item2 = rand() % num_items;
        transactions[i].count = rand() % 100;
    }
}

void generate_rules() {
    for (int i = 0; i < num_rules; i++) {
        rules[i].count = rand() % 100;
        rules[i].confidence = rand() % 100;
        rules[i].lift = rand() % 100;
    }
}

int main() {
    int num_items, num_categories, num_transactions, num_rules;

    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    printf("Enter the number of categories: ");
    scanf("%d", &num_categories);

    printf("Enter the number of transactions: ");
    scanf("%d", &num_transactions);

    printf("Enter the number of rules: ");
    scanf("%d", &num_rules);

    generate_data(num_items, num_categories, num_transactions);
    generate_rules();

    return 0;
}