//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct account {
    char name[50];
    int balance;
};

struct transaction {
    char date[20];
    char description[100];
    int amount;
    char type[10];
};

void add_account(struct account *acc) {
    printf("Enter account name: ");
    scanf("%s", acc->name);
    printf("Enter account balance: ");
    scanf("%d", &acc->balance);
}

void add_transaction(struct transaction *trans) {
    printf("Enter transaction date (DD/MM/YYYY): ");
    scanf("%s", trans->date);
    printf("Enter transaction description: ");
    scanf("%s", trans->description);
    printf("Enter transaction amount: ");
    scanf("%d", &trans->amount);
    printf("Enter transaction type (deposit/withdrawal): ");
    scanf("%s", trans->type);
}

void display_accounts(struct account *acc, int num_acc) {
    printf("Account name\tBalance\n");
    for (int i = 0; i < num_acc; i++) {
        printf("%s\t\t%d\n", acc[i].name, acc[i].balance);
    }
}

void display_transactions(struct transaction *trans, int num_trans) {
    printf("Date\tDescription\tAmount\tType\n");
    for (int i = 0; i < num_trans; i++) {
        printf("%s\t\t%s\t\t%d\t\t%s\n", trans[i].date, trans[i].description, trans[i].amount, trans[i].type);
    }
}

int main() {
    int num_acc, num_trans;
    printf("Enter number of accounts: ");
    scanf("%d", &num_acc);
    struct account acc[num_acc];
    for (int i = 0; i < num_acc; i++) {
        add_account(&acc[i]);
    }
    printf("Enter number of transactions: ");
    scanf("%d", &num_trans);
    struct transaction trans[num_trans];
    for (int i = 0; i < num_trans; i++) {
        add_transaction(&trans[i]);
    }
    printf("Accounts:\n");
    display_accounts(acc, num_acc);
    printf("Transactions:\n");
    display_transactions(trans, num_trans);
    return 0;
}