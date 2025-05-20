//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a bank record
typedef struct bank_record {
    char name[50];
    int account_number;
    double balance;
} bank_record;

// Function to create a new bank record
bank_record *create_bank_record() {
    bank_record *new_record = (bank_record *)malloc(sizeof(bank_record));
    new_record->name[0] = '\0';
    new_record->account_number = 0;
    new_record->balance = 0.0;
    return new_record;
}

// Function to deposit money into a bank record
void deposit(bank_record *record, double amount) {
    record->balance += amount;
}

// Function to withdraw money from a bank record
void withdraw(bank_record *record, double amount) {
    if (amount <= record->balance) {
        record->balance -= amount;
    } else {
        printf("Insufficient funds\n");
    }
}

// Function to transfer money between bank records
void transfer(bank_record *record1, bank_record *record2, double amount) {
    if (amount <= record1->balance) {
        deposit(record2, amount);
        withdraw(record1, amount);
    } else {
        printf("Insufficient funds\n");
    }
}

int main() {
    // Create two bank records
    bank_record *record1 = create_bank_record();
    bank_record *record2 = create_bank_record();

    // Deposit money into the first bank record
    deposit(record1, 1000);

    // Withdraw money from the first bank record
    withdraw(record1, 500);

    // Transfer money between bank records
    transfer(record1, record2, 200);

    // Print the balances of the bank records
    printf("Balance of record1: %f\n", record1->balance);
    printf("Balance of record2: %f\n", record2->balance);

    return 0;
}