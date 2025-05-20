//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int accountNumber;
    char name[100];
    float balance;
} Account;

int main() {
    Account* accounts = malloc(10 * sizeof(Account));
    if (accounts == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Welcome to the Banking Record System!\n");
    printf("Enter the account number (0 to exit): ");
    int accNum;
    while (scanf("%d", &accNum)!= EOF && accNum!= 0) {
        if (accNum >= 10 && accNum <= 99) {
            printf("Enter account holder name: ");
            fgets(accounts[accNum].name, sizeof(accounts[accNum].name), stdin);
            accounts[accNum].balance = 0.0;
            printf("Account %d opened successfully!\n", accNum);
        } else {
            printf("Invalid account number!\n");
        }
        printf("Enter deposit amount: ");
        double dep;
        scanf("%lf", &dep);
        accounts[accNum].balance += dep;
        printf("Deposit successful!\n");
        printf("Enter withdrawal amount: ");
        double wit;
        scanf("%lf", &wit);
        if (wit > accounts[accNum].balance) {
            printf("Insufficient funds!\n");
        } else {
            accounts[accNum].balance -= wit;
            printf("Withdrawal successful!\n");
        }
        printf("Account %d balance: %.2f\n", accNum, accounts[accNum].balance);
        printf("Press any key to continue...\n");
        getchar();
    }
    printf("Goodbye!\n");
    free(accounts);
    return 0;
}