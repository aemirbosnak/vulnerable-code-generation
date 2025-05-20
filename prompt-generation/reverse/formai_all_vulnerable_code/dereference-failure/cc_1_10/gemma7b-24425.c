//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 10

struct Record {
    char name[50];
    int account_no;
    double balance;
    struct Record* next;
};

struct Record* insert_record(struct Record* head) {
    struct Record* new_record = (struct Record*)malloc(sizeof(struct Record));
    printf("Enter name: ");
    scanf("%s", new_record->name);
    printf("Enter account number: ");
    scanf("%d", &new_record->account_no);
    printf("Enter balance: ");
    scanf("%lf", &new_record->balance);

    if (head == NULL) {
        head = new_record;
    } else {
        new_record->next = head;
        head = new_record;
    }

    return head;
}

void print_records(struct Record* head) {
    struct Record* current = head;
    printf("List of records:\n");
    while (current) {
        printf("Name: %s\n", current->name);
        printf("Account number: %d\n", current->account_no);
        printf("Balance: %.2lf\n", current->balance);
        printf("\n");
        current = current->next;
    }
}

int main() {
    struct Record* head = NULL;

    // Insert records
    head = insert_record(head);
    insert_record(head);
    insert_record(head);

    // Print records
    print_records(head);

    return 0;
}