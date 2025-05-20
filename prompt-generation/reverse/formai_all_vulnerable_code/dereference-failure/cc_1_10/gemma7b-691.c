//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: intelligent
#include <stdio.h>
#include <string.h>

// Define a structure to store bank records
struct bank_record {
    char name[50];
    int account_number;
    double balance;
    char account_type;
    struct bank_record* next;
};

// Create a linked list of bank records
struct bank_record* head = NULL;

// Function to insert a new bank record into the linked list
void insert_record(char* name, int account_number, double balance, char account_type) {
    struct bank_record* new_record = (struct bank_record*)malloc(sizeof(struct bank_record));
    strcpy(new_record->name, name);
    new_record->account_number = account_number;
    new_record->balance = balance;
    new_record->account_type = account_type;
    new_record->next = NULL;

    if (head == NULL) {
        head = new_record;
    } else {
        struct bank_record* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_record;
    }
}

// Function to search for a bank record
struct bank_record* search_record(int account_number) {
    struct bank_record* temp = head;
    while (temp) {
        if (temp->account_number == account_number) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to update a bank record
void update_record(int account_number, double new_balance) {
    struct bank_record* record = search_record(account_number);
    if (record) {
        record->balance = new_balance;
    }
}

// Function to delete a bank record
void delete_record(int account_number) {
    struct bank_record* record = search_record(account_number);
    if (record) {
        struct bank_record* temp = head;
        if (record == head) {
            head = record->next;
        } else {
            while (temp->next != record) {
                temp = temp->next;
            }
            temp->next = record->next;
        }
        free(record);
    }
}

// Main function
int main() {
    insert_record("John Doe", 123456, 1000.0, 'S');
    insert_record("Jane Doe", 654321, 500.0, 'C');
    insert_record("Peter Pan", 984123, 2000.0, 'A');

    struct bank_record* record = search_record(123456);
    if (record) {
        printf("Name: %s\n", record->name);
        printf("Account Number: %d\n", record->account_number);
        printf("Balance: %.2lf\n", record->balance);
        printf("Account Type: %c\n", record->account_type);
    }

    update_record(654321, 1000.0);

    record = search_record(654321);
    if (record) {
        printf("Updated Balance: %.2lf\n", record->balance);
    }

    delete_record(984123);

    record = search_record(984123);
    if (record) {
        printf("Record not found.\n");
    }

    return 0;
}