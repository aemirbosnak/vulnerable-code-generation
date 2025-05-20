//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Define a struct to store bank record data
typedef struct BankRecord {
    char name[50];
    int account_no;
    double balance;
} BankRecord;

// Declare a linked list to store bank records
struct Node {
    BankRecord record;
    struct Node* next;
};

// Function to insert a new bank record at the end of the linked list
void insert_record(struct Node** head, BankRecord record) {
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->record = record;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        (*head)->next = new_node;
    }
}

// Function to search for a bank record by account number
struct Node* search_record(struct Node* head, int account_no) {
    while (head) {
        if (head->record.account_no == account_no) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

int main() {
    // Create a linked list to store bank records
    struct Node* head = NULL;

    // Insert some sample bank records
    BankRecord record1 = {"John Doe", 123456, 1000.0};
    insert_record(&head, record1);

    BankRecord record2 = {"Jane Doe", 654321, 2000.0};
    insert_record(&head, record2);

    BankRecord record3 = {"Peter Pan", 321468, 3000.0};
    insert_record(&head, record3);

    // Search for a bank record by account number
    struct Node* found_node = search_record(head, 123456);

    // Print the found bank record data
    if (found_node) {
        printf("Name: %s\n", found_node->record.name);
        printf("Account No: %d\n", found_node->record.account_no);
        printf("Balance: %f\n", found_node->record.balance);
    } else {
        printf("Record not found\n");
    }

    return 0;
}