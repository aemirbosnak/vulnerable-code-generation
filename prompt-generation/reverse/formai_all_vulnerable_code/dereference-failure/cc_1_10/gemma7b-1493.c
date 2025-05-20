//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define NUM_ACCOUNTS 4

struct Account {
    char name[20];
    double balance;
    double interest_rate;
    struct Account *next;
};

struct Account *head = NULL;

void add_account(char *name, double balance, double interest_rate) {
    struct Account *new_account = malloc(sizeof(struct Account));
    strcpy(new_account->name, name);
    new_account->balance = balance;
    new_account->interest_rate = interest_rate;
    new_account->next = NULL;

    if (head == NULL) {
        head = new_account;
    } else {
        struct Account *current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_account;
    }
}

double calculate_interest(double balance, double interest_rate) {
    return balance * interest_rate / 100;
}

void print_accounts() {
    struct Account *current = head;
    while (current) {
        printf("Name: %s, Balance: %.2lf, Interest Rate: %.2lf\n", current->name, current->balance, current->interest_rate);
        current = current->next;
    }
}

int main() {
    add_account("Mr. Bean", 1000.0, 2.5);
    add_account("Ms. Smith", 2000.0, 3.0);
    add_account("Mr. Johnson", 3000.0, 2.0);
    add_account("Ms. Jones", 4000.0, 3.5);

    print_accounts();

    double interest_earned = calculate_interest(2000.0, 3.0);
    printf("Interest earned: %.2lf\n", interest_earned);

    return 0;
}