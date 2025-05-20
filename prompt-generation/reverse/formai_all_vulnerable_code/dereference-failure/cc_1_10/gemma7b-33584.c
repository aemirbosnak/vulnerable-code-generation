//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 10

typedef struct Record {
    char name[50];
    int account_number;
    double balance;
    struct Record* next;
} Record;

Record* head = NULL;

void add_record(char* name, int account_number, double balance) {
    Record* new_record = (Record*)malloc(sizeof(Record));
    strcpy(new_record->name, name);
    new_record->account_number = account_number;
    new_record->balance = balance;
    new_record->next = NULL;

    if (head == NULL) {
        head = new_record;
    } else {
        Record* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_record;
    }
}

void print_records() {
    Record* current = head;
    while (current) {
        printf("Name: %s\n", current->name);
        printf("Account Number: %d\n", current->account_number);
        printf("Balance: %.2lf\n", current->balance);
        printf("\n");
        current = current->next;
    }
}

int main() {
    add_record("John Doe", 12345, 1000.0);
    add_record("Jane Doe", 67890, 500.0);
    add_record("Bob Smith", 34127, 200.0);

    print_records();

    return 0;
}