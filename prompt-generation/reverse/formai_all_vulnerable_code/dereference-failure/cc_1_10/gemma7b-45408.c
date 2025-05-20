//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

struct BankRecord {
    char name[50];
    int accountNo;
    double balance;
    struct BankRecord* next;
};

void insertRecord(struct BankRecord** head, char* name, int accountNo, double balance) {
    struct BankRecord* newNode = (struct BankRecord*)malloc(sizeof(struct BankRecord));
    strcpy(newNode->name, name);
    newNode->accountNo = accountNo;
    newNode->balance = balance;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int searchRecord(struct BankRecord* head, int accountNo) {
    while (head) {
        if (head->accountNo == accountNo) {
            return 1;
        } else {
            head = head->next;
        }
    }

    return 0;
}

int main() {
    struct BankRecord* head = NULL;

    insertRecord(&head, "John Doe", 1234, 1000);
    insertRecord(&head, "Jane Doe", 5678, 2000);
    insertRecord(&head, "Peter Pan", 9841, 3000);

    if (searchRecord(head, 1234)) {
        printf("Account No: 1234, Balance: $1000\n");
    }

    if (searchRecord(head, 5678)) {
        printf("Account No: 5678, Balance: $2000\n");
    }

    return 0;
}