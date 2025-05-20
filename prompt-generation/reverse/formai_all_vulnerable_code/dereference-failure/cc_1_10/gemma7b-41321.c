//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
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
    while (head) {
        printf("%s (%d) - $%.2lf\n", head->name, head->account_number, head->balance);
        head = head->next;
    }
}

int main() {
    Record* head = NULL;

    // Paranoia:
    add_record(head, "John Doe", 123456, 1000.0);
    add_record(head, "Jane Doe", 543219, 2000.0);
    add_record(head, "Mr. Big", 984123, 3000.0);
    add_record(head, "The Spy", 821463, 4000.0);

    print_records(head);

    return 0;
}