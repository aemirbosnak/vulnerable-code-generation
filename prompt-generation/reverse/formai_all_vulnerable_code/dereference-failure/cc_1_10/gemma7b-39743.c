//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: puzzling
#include <stdio.h>
#include <string.h>

struct BankRecord {
    char name[20];
    int account_no;
    double balance;
    struct BankRecord* next;
};

struct BankRecord* insert_record(struct BankRecord* head, char* name, int account_no, double balance) {
    struct BankRecord* new_record = malloc(sizeof(struct BankRecord));
    strcpy(new_record->name, name);
    new_record->account_no = account_no;
    new_record->balance = balance;
    new_record->next = NULL;

    if (head == NULL) {
        return new_record;
    }

    head->next = new_record;
    return head;
}

struct BankRecord* search_record(struct BankRecord* head, int account_no) {
    struct BankRecord* current = head;

    while (current) {
        if (current->account_no == account_no) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

void print_records(struct BankRecord* head) {
    struct BankRecord* current = head;

    while (current) {
        printf("Name: %s, Account No: %d, Balance: %.2lf\n", current->name, current->account_no, current->balance);
        current = current->next;
    }
}

int main() {
    struct BankRecord* head = NULL;

    insert_record(head, "John Doe", 123456, 1000.0);
    insert_record(head, "Jane Doe", 654321, 2000.0);
    insert_record(head, "Peter Pan", 984123, 3000.0);

    print_records(head);

    struct BankRecord* record = search_record(head, 654321);

    if (record) {
        printf("Name: %s, Account No: %d, Balance: %.2lf\n", record->name, record->account_no, record->balance);
    } else {
        printf("Record not found.\n");
    }

    return 0;
}