//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
    int account_number;
    char name[100];
    double balance;
};

struct banking_record {
    struct account account;
    char transaction_type[50];
    double amount;
    struct banking_record *next;
};

struct banking_record *head = NULL;

void create_account() {
    struct account account;
    printf("Enter account number: ");
    scanf("%d", &account.account_number);
    printf("Enter name: ");
    scanf(" %[^\n]", account.name);
    printf("Enter balance: ");
    scanf("%lf", &account.balance);

    struct banking_record *new_record = (struct banking_record *)malloc(sizeof(struct banking_record));
    new_record->account = account;
    new_record->next = NULL;

    if (head == NULL) {
        head = new_record;
    } else {
        struct banking_record *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_record;
    }
}

void deposit() {
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);

    struct banking_record *temp = head;
    while (temp != NULL) {
        if (temp->account.account_number == account_number) {
            double amount;
            printf("Enter amount to deposit: ");
            scanf("%lf", &amount);
            temp->account.balance += amount;
            printf("Deposit successful!\n");
            return;
        }
        temp = temp->next;
    }

    printf("Account not found!\n");
}

void withdraw() {
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);

    struct banking_record *temp = head;
    while (temp != NULL) {
        if (temp->account.account_number == account_number) {
            double amount;
            printf("Enter amount to withdraw: ");
            scanf("%lf", &amount);
            if (amount <= temp->account.balance) {
                temp->account.balance -= amount;
                printf("Withdrawal successful!\n");
                return;
            } else {
                printf("Insufficient balance!\n");
                return;
            }
        }
        temp = temp->next;
    }

    printf("Account not found!\n");
}

void transfer() {
    int from_account_number, to_account_number;
    printf("Enter from account number: ");
    scanf("%d", &from_account_number);
    printf("Enter to account number: ");
    scanf("%d", &to_account_number);

    struct banking_record *from_account = NULL;
    struct banking_record *to_account = NULL;

    struct banking_record *temp = head;
    while (temp != NULL) {
        if (temp->account.account_number == from_account_number) {
            from_account = temp;
        } else if (temp->account.account_number == to_account_number) {
            to_account = temp;
        }
        temp = temp->next;
    }

    if (from_account == NULL || to_account == NULL) {
        printf("Account not found!\n");
        return;
    }

    double amount;
    printf("Enter amount to transfer: ");
    scanf("%lf", &amount);
    if (amount <= from_account->account.balance) {
        from_account->account.balance -= amount;
        to_account->account.balance += amount;
        printf("Transfer successful!\n");
    } else {
        printf("Insufficient balance!\n");
    }
}

void print_record() {
    struct banking_record *temp = head;
    while (temp != NULL) {
        printf("Account number: %d\n", temp->account.account_number);
        printf("Name: %s\n", temp->account.name);
        printf("Balance: %.2lf\n", temp->account.balance);
        printf("\n");
        temp = temp->next;
    }
}

int main() {
    int choice;
    do {
        printf("1. Create account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Transfer\n");
        printf("5. Print record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                transfer();
                break;
            case 5:
                print_record();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}