//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 100
#define MAX_RECORD_LENGTH 255

typedef struct Record {
    char name[MAX_RECORD_LENGTH];
    int account_number;
    double balance;
    struct Record* next;
} Record;

void initialize_record_system(Record** head) {
    *head = NULL;
}

void add_record(Record** head, char* name, int account_number, double balance) {
    Record* new_record = malloc(sizeof(Record));
    strcpy(new_record->name, name);
    new_record->account_number = account_number;
    new_record->balance = balance;
    new_record->next = NULL;

    if (*head == NULL) {
        *head = new_record;
    } else {
        (*head)->next = new_record;
    }
}

void print_records(Record* head) {
    while (head) {
        printf("Name: %s, Account Number: %d, Balance: %.2lf\n", head->name, head->account_number, head->balance);
        head = head->next;
    }
}

int main() {
    Record* head = NULL;
    initialize_record_system(&head);

    add_record(&head, "Alice", 12345, 1000.0);
    add_record(&head, "Bob", 67890, 2000.0);
    add_record(&head, "Charlie", 34569, 3000.0);

    print_records(head);

    return 0;
}