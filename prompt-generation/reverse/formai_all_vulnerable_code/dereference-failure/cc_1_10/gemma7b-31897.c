//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct BankRecord {
    char name[20];
    int account_no;
    double balance;
    struct BankRecord* next;
} BankRecord;

void insert_at_tail(BankRecord** head, BankRecord* new_node) {
    if (*head == NULL) {
        *head = new_node;
    } else {
        ((*head)->next = new_node);
        *head = new_node;
    }
}

void display_records(BankRecord* head) {
    while (head) {
        printf("%s (%d) - Balance: %.2lf\n", head->name, head->account_no, head->balance);
        head = head->next;
    }
}

int main() {
    BankRecord* head = NULL;
    BankRecord* new_node = NULL;

    // Inserting records
    new_node = (BankRecord*)malloc(sizeof(BankRecord));
    strcpy(new_node->name, "John Doe");
    new_node->account_no = 12345;
    new_node->balance = 1000.0;
    insert_at_tail(&head, new_node);

    new_node = (BankRecord*)malloc(sizeof(BankRecord));
    strcpy(new_node->name, "Jane Doe");
    new_node->account_no = 54321;
    new_node->balance = 2000.0;
    insert_at_tail(&head, new_node);

    // Displaying records
    display_records(head);

    return 0;
}