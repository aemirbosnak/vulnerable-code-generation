//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUDGET_ITEMS 100
#define MAX_CATEGORIES 20
#define MAX_ACCOUNT_TYPES 10

typedef struct {
    char name[50];
    float amount;
    int category;
} BudgetItem;

typedef struct {
    char name[50];
    int num_items;
} Category;

typedef struct {
    char name[50];
    float balance;
    int account_type;
} Account;

int main() {
    int num_budget_items, num_categories, num_accounts;
    scanf("%d", &num_budget_items);
    scanf("%d", &num_categories);
    scanf("%d", &num_accounts);

    BudgetItem budget_items[num_budget_items];
    Category categories[num_categories];
    Account accounts[num_accounts];

    for (int i = 0; i < num_budget_items; i++) {
        scanf("%s", budget_items[i].name);
        scanf("%f", &budget_items[i].amount);
        scanf("%d", &budget_items[i].category);
    }

    for (int i = 0; i < num_categories; i++) {
        scanf("%s", categories[i].name);
        scanf("%d", &categories[i].num_items);
    }

    for (int i = 0; i < num_accounts; i++) {
        scanf("%s", accounts[i].name);
        scanf("%f", &accounts[i].balance);
        scanf("%d", &accounts[i].account_type);
    }

    return 0;
}