//FormAI DATASET v1.0 Category: Banking Record System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BankRecord 
{
    char name[50];
    int account_number;
    float balance;
} BankRecord;

BankRecord* createRecord(char* name, int account_number, float balance) 
{
    BankRecord* record = (BankRecord*)malloc(sizeof(BankRecord));
    strcpy(record->name, name);
    record->account_number = account_number;
    record->balance = balance;
    return record;
}

void printRecord(BankRecord* record) 
{
    printf("Name: %s\nAccount Number: %d\nBalance: %.2f\n", record->name, record->account_number, record->balance);
}

void deposit(BankRecord* record, float amount) 
{
    record->balance += amount;
}

void withdraw(BankRecord* record, float amount) 
{
    if(record->balance - amount < 0) 
    {
        printf("Error: Insufficient balance!\n");
    }
    else 
    {
        record->balance -= amount;
    }
}

int main() 
{
    BankRecord* record = createRecord("John Doe", 1234, 1000.00);
    printRecord(record);

    deposit(record, 500.00);
    printf("After deposit:\n");
    printRecord(record);

    withdraw(record, 2000.00);
    printf("After withdrawal:\n");
    printRecord(record);

    free(record);
    return 0;
}