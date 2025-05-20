//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_RECORDS 1024

typedef struct Record {
    char name[256];
    char account_number[20];
    double balance;
    struct Record* next;
} Record;

Record* insertRecord(Record* head, char* name, char* account_number, double balance) {
    Record* new_record = (Record*)malloc(sizeof(Record));
    strcpy(new_record->name, name);
    strcpy(new_record->account_number, account_number);
    new_record->balance = balance;
    new_record->next = NULL;

    if (head == NULL) {
        head = new_record;
    } else {
        new_record->next = head;
        head = new_record;
    }

    return head;
}

double getBalance(Record* head, char* account_number) {
    while (head) {
        if (strcmp(head->account_number, account_number) == 0) {
            return head->balance;
        }
        head = head->next;
    }

    return -1;
}

void transfer(Record* head, char* from_account_number, char* to_account_number, double amount) {
    double from_balance = getBalance(head, from_account_number);
    double to_balance = getBalance(head, to_account_number);

    if (from_balance < amount) {
        printf("Error: insufficient funds.\n");
        return;
    }

    from_balance -= amount;
    to_balance += amount;

    insertRecord(head, NULL, from_account_number, from_balance);
    insertRecord(head, NULL, to_account_number, to_balance);

    printf("Transfer successful.\n");
}

int main() {
    Record* head = NULL;

    insertRecord(head, "John Doe", "123456", 1000);
    insertRecord(head, "Jane Doe", "456789", 2000);
    insertRecord(head, "Peter Pan", "692348", 3000);

    transfer(head, "123456", "456789", 500);

    double balance = getBalance(head, "456789");

    printf("Balance: %f\n", balance);

    return 0;
}