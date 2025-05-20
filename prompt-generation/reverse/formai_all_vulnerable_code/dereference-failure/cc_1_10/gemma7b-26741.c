//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Record {
    char name[50];
    int account_number;
    double balance;
    struct Record* next;
};

struct Record* insert(struct Record* head, char* name, int account_number, double balance) {
    struct Record* new_node = (struct Record*)malloc(sizeof(struct Record));
    strcpy(new_node->name, name);
    new_node->account_number = account_number;
    new_node->balance = balance;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        struct Record* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    return head;
}

struct Record* search(struct Record* head, int account_number) {
    struct Record* temp = head;
    while (temp) {
        if (temp->account_number == account_number) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

int main() {
    struct Record* head = NULL;
    head = insert(head, "John Doe", 123456, 1000.0);
    head = insert(head, "Jane Doe", 654912, 2000.0);
    head = insert(head, "Peter Pan", 984123, 3000.0);

    struct Record* found_record = search(head, 654912);
    if (found_record) {
        printf("Name: %s\n", found_record->name);
        printf("Account Number: %d\n", found_record->account_number);
        printf("Balance: %.2lf\n", found_record->balance);
    } else {
        printf("Record not found.\n");
    }

    return 0;
}