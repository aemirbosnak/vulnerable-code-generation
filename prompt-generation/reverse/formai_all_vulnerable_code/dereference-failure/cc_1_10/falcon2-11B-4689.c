//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

typedef struct bank_record {
    int account_number;
    char name[50];
    char address[100];
    int balance;
} BankRecord;

void add_account(BankRecord *bank_records, int account_number, char *name, char *address, int balance) {
    BankRecord new_record = {account_number, name, address, balance};
    bank_records[account_number] = new_record;
}

void display_accounts(BankRecord *bank_records, int account_number) {
    if (account_number < 0 || account_number >= sizeof(bank_records)) {
        printf("Invalid account number\n");
        return;
    }

    printf("Account number: %d\n", account_number);
    printf("Name: %s\n", bank_records[account_number].name);
    printf("Address: %s\n", bank_records[account_number].address);
    printf("Balance: %d\n", bank_records[account_number].balance);
}

int main() {
    BankRecord bank_records[100];

    int account_number;
    char name[50], address[100];
    int balance;

    printf("Enter account number: ");
    scanf("%d", &account_number);

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter address: ");
    scanf("%s", address);

    printf("Enter balance: ");
    scanf("%d", &balance);

    add_account(bank_records, account_number, name, address, balance);

    printf("Account details:\n");
    display_accounts(bank_records, account_number);

    return 0;
}