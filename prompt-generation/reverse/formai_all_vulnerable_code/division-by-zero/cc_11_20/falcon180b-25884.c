//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ACCOUNTS 10
#define MAX_TRANSACTIONS 100
#define MAX_CATEGORIES 20

typedef struct {
    char name[50];
    int balance;
} Account;

typedef struct {
    char description[100];
    int amount;
    char category[50];
} Transaction;

typedef struct {
    char name[50];
    int id;
} Category;

int main() {
    srand(time(NULL));

    Account accounts[MAX_ACCOUNTS];
    int num_accounts = 0;

    Category categories[MAX_CATEGORIES];
    int num_categories = 0;

    Transaction transactions[MAX_TRANSACTIONS];
    int num_transactions = 0;

    int choice;
    do {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add Account\n");
        printf("2. Add Transaction\n");
        printf("3. Add Category\n");
        printf("4. View Account Balance\n");
        printf("5. View Transactions by Category\n");
        printf("6. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_accounts >= MAX_ACCOUNTS) {
                    printf("Maximum number of accounts reached.\n");
                } else {
                    printf("Enter account name: ");
                    scanf("%s", accounts[num_accounts].name);
                    accounts[num_accounts].balance = rand() % 1000;
                    num_accounts++;
                }
                break;
            case 2:
                if (num_transactions >= MAX_TRANSACTIONS) {
                    printf("Maximum number of transactions reached.\n");
                } else {
                    printf("Enter transaction description: ");
                    scanf("%s", transactions[num_transactions].description);
                    printf("Enter transaction amount: ");
                    scanf("%d", &transactions[num_transactions].amount);
                    printf("Enter transaction category: ");
                    scanf("%s", transactions[num_transactions].category);
                    num_transactions++;
                }
                break;
            case 3:
                if (num_categories >= MAX_CATEGORIES) {
                    printf("Maximum number of categories reached.\n");
                } else {
                    printf("Enter category name: ");
                    scanf("%s", categories[num_categories].name);
                    categories[num_categories].id = rand() % 100;
                    num_categories++;
                }
                break;
            case 4:
                printf("Enter account name: ");
                scanf("%s", accounts[num_accounts-1].name);
                printf("Account Balance: $%d\n", accounts[num_accounts-1].balance);
                break;
            case 5:
                printf("Enter category name or id: ");
                scanf("%s", categories[num_categories-1].name);
                int category_id = rand() % num_categories;
                printf("Transactions for category %s:\n", categories[category_id].name);
                for (int i = 0; i < num_transactions; i++) {
                    if (strcmp(transactions[i].category, categories[category_id].name) == 0) {
                        printf("- %s: $%d\n", transactions[i].description, transactions[i].amount);
                    }
                }
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 6);

    return 0;
}