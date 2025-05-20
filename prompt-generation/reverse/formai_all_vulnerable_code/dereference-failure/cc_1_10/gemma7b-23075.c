//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CUSTOMERS 10

typedef struct Customer {
    char name[50];
    int room_number;
    char status;
    struct Customer* next;
} Customer;

Customer* create_customer(char* name, int room_number, char status) {
    Customer* new_customer = (Customer*)malloc(sizeof(Customer));
    strcpy(new_customer->name, name);
    new_customer->room_number = room_number;
    new_customer->status = status;
    new_customer->next = NULL;
    return new_customer;
}

void add_customer(Customer* head, char* name, int room_number, char status) {
    Customer* new_customer = create_customer(name, room_number, status);
    if (head == NULL) {
        head = new_customer;
    } else {
        Customer* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_customer;
    }
}

void print_customers(Customer* head) {
    Customer* current = head;
    while (current) {
        printf("%s, room number %d, status %c\n", current->name, current->room_number, current->status);
        current = current->next;
    }
}

int main() {
    Customer* head = NULL;
    add_customer(head, "John Doe", 101, 'O');
    add_customer(head, "Jane Doe", 102, 'A');
    add_customer(head, "Peter Pan", 103, 'R');
    print_customers(head);

    return 0;
}