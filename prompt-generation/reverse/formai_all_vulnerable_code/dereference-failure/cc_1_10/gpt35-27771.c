//FormAI DATASET v1.0 Category: Banking Record System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct Record {
    int account;
    char name[20];
    double balance;
    struct Record* next;
} Record;

Record* head = NULL;

void addRecord(int account, char name[], double balance) {
    Record* newRecord = (Record*)malloc(sizeof(Record));
    newRecord->account = account;
    strcpy(newRecord->name, name);
    newRecord->balance = balance;
    newRecord->next = head;
    head = newRecord;
}

void printRecords(Record* current) {
    if(current == NULL) {
        return;
    }
    printf("Account Number: %d\n", current->account);
    printf("Name: %s\n", current->name);
    printf("Balance: %.2f\n", current->balance);
    printf("\n");
    printRecords(current->next);
}

double findBalance(int account, Record* current) {
    if(current == NULL) {
        return -1.00;
    }
    if(current->account == account) {
        return current->balance;
    }
    return findBalance(account, current->next);
}

void updateRecord(int account, double newBalance, Record* current) {
    if(current == NULL) {
        return;
    }
    if(current->account == account) {
        current->balance = newBalance;
        return;
    }
    updateRecord(account, newBalance, current->next);
}

int main() {
    addRecord(1234, "John Doe", 1000.00);
    addRecord(5678, "Jane Smith", 2000.00);
    addRecord(9123, "Bob Johnson", 1500.00);
    
    printf("Initial Records:\n");
    printRecords(head);
    
    printf("Balance for account 5678: %.2f\n", findBalance(5678, head));
    
    updateRecord(5678, 2500.00, head);
    printf("Updated Records:\n");
    printRecords(head);
    
    return 0;
}