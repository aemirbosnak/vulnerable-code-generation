//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_RECORDS 100

typedef struct Record {
    char name[20];
    int account_no;
    double balance;
    struct Record* next;
} Record;

Record* create_record(char* name, int account_no, double balance) {
    Record* new_record = (Record*)malloc(sizeof(Record));
    strcpy(new_record->name, name);
    new_record->account_no = account_no;
    new_record->balance = balance;
    new_record->next = NULL;
    return new_record;
}

void add_record(Record* head, char* name, int account_no, double balance) {
    Record* new_record = create_record(name, account_no, balance);
    if (head == NULL) {
        head = new_record;
    } else {
        new_record->next = head;
        head = new_record;
    }
}

Record* search_record(Record* head, int account_no) {
    while (head) {
        if (head->account_no == account_no) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void update_record(Record* head, int account_no, double new_balance) {
    Record* record = search_record(head, account_no);
    if (record) {
        record->balance = new_balance;
    }
}

void delete_record(Record* head, int account_no) {
    Record* previous = NULL;
    Record* current = head;
    while (current) {
        if (current->account_no == account_no) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    return;
}

int main() {
    Record* head = NULL;
    add_record(head, "John Doe", 12345, 1000.0);
    add_record(head, "Jane Doe", 67890, 2000.0);
    add_record(head, "Peter Pan", 32146, 3000.0);

    Record* record = search_record(head, 12345);
    if (record) {
        printf("Name: %s\n", record->name);
        printf("Account No: %d\n", record->account_no);
        printf("Balance: %.2lf\n", record->balance);
    }

    update_record(head, 67890, 2500.0);
    record = search_record(head, 67890);
    if (record) {
        printf("Name: %s\n", record->name);
        printf("Account No: %d\n", record->account_no);
        printf("Balance: %.2lf\n", record->balance);
    }

    delete_record(head, 32146);
    record = search_record(head, 32146);
    if (record) {
        printf("Name: %s\n", record->name);
        printf("Account No: %d\n", record->account_no);
        printf("Balance: %.2lf\n", record->balance);
    }

    return 0;
}