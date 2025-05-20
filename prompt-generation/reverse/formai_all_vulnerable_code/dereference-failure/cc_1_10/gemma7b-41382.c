//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 10

typedef struct Record {
    char name[20];
    int account_number;
    double balance;
    struct Record* next;
} Record;

Record* create_record(char* name, int account_number, double balance) {
    Record* new_record = (Record*)malloc(sizeof(Record));

    strcpy(new_record->name, name);
    new_record->account_number = account_number;
    new_record->balance = balance;
    new_record->next = NULL;

    return new_record;
}

void add_record(Record* head, char* name, int account_number, double balance) {
    Record* new_record = create_record(name, account_number, balance);

    if (head == NULL) {
        head = new_record;
    } else {
        new_record->next = head;
        head = new_record;
    }
}

void print_records(Record* head) {
    Record* current_record = head;

    printf("----------------------------------------------------------------------------\n");
    printf("List of Records:\n");

    while (current_record) {
        printf("Name: %s\n", current_record->name);
        printf("Account Number: %d\n", current_record->account_number);
        printf("Balance: %.2lf\n", current_record->balance);
        printf("\n");
        current_record = current_record->next;
    }

    printf("----------------------------------------------------------------------------\n");
}

int main() {
    Record* head = NULL;

    add_record(head, "Sherlock Holmes", 12345, 1000.0);
    add_record(head, "John Watson", 67890, 2000.0);
    add_record(head, "Dr. Watson", 32154, 3000.0);

    print_records(head);

    return 0;
}