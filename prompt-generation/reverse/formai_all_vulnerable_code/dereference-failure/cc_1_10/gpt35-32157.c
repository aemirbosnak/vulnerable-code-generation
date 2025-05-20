//FormAI DATASET v1.0 Category: Banking Record System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
    char name[50];
    int acc_no;
    float balance;
};

typedef struct account Account;

Account *create_account(char *name, int acc_no, float balance) {
    Account *new_acc = (Account *) malloc(sizeof(Account));
    strcpy(new_acc->name, name);
    new_acc->acc_no = acc_no;
    new_acc->balance = balance;
    return new_acc;
}

void transaction(Account *acc, float amount) {
    if (amount < 0 && acc->balance < -amount) {
        printf("Insufficient funds\n");
        return;
    } else {
        acc->balance += amount;
        printf("New balance of account %d is %f\n", acc->acc_no, acc->balance);
    }
}

void display_account(Account *acc) {
    printf("Account name: %s\n", acc->name);
    printf("Account number: %d\n", acc->acc_no);
    printf("Account balance: %f\n", acc->balance);
}

void delete_account(Account *acc) {
    free(acc);
}

int main() {
    Account *acc1 = create_account("John Smith", 123456, 1000.00);
    Account *acc2 = create_account("Jane Doe", 789012, 5000.00);

    printf("Initial account details:\n");
    display_account(acc1);
    display_account(acc2);

    transaction(acc1, -500.00);
    transaction(acc2, 1000.00);

    printf("Updated account details:\n");
    display_account(acc1);
    display_account(acc2);

    delete_account(acc1);
    delete_account(acc2);

    return 0;
}