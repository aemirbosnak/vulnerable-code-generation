//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Account {
    char name[50];
    int account_no;
    double balance;
    struct Account* next;
} Account;

Account* insertAccount(Account* head, Account* newAccount) {
    if (head == NULL) {
        head = newAccount;
    } else {
        head->next = insertAccount(head->next, newAccount);
    }
    return head;
}

void displayAccount(Account* head) {
    Account* currentAccount = head;
    while (currentAccount) {
        printf("Account Name: %s\n", currentAccount->name);
        printf("Account Number: %d\n", currentAccount->account_no);
        printf("Balance: %.2lf\n", currentAccount->balance);
        printf("\n");
        currentAccount = currentAccount->next;
    }
}

int main() {
    Account* head = NULL;
    Account* newAccount = NULL;

    newAccount = (Account*)malloc(sizeof(Account));
    newAccount->name[0] = 'A';
    newAccount->account_no = 1234;
    newAccount->balance = 1000.0;

    insertAccount(head, newAccount);

    newAccount = (Account*)malloc(sizeof(Account));
    newAccount->name[0] = 'B';
    newAccount->account_no = 5678;
    newAccount->balance = 2000.0;

    insertAccount(head, newAccount);

    displayAccount(head);

    return 0;
}