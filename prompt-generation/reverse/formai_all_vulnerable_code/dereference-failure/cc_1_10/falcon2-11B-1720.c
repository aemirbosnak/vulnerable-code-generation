//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct account
{
    char name[20];
    int balance;
};

struct account* create_account()
{
    struct account* new_account = (struct account*)malloc(sizeof(struct account));
    printf("Enter Account Name: ");
    fgets(new_account->name, sizeof(new_account->name), stdin);
    printf("Enter Initial Balance: ");
    scanf("%d", &new_account->balance);
    return new_account;
}

void deposit(struct account* account, int amount)
{
    account->balance += amount;
}

void withdraw(struct account* account, int amount)
{
    if (amount > account->balance)
    {
        printf("Insufficient Balance!\n");
        return;
    }
    account->balance -= amount;
}

void display(struct account* account)
{
    printf("Name: %s\n", account->name);
    printf("Balance: %d\n", account->balance);
}

int main()
{
    struct account* account = create_account();
    deposit(account, 1000);
    display(account);
    withdraw(account, 500);
    display(account);
    free(account);
    return 0;
}