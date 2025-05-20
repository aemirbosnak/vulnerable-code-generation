//FormAI DATASET v1.0 Category: Banking Record System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

struct bank_record {
    int id;
    char name[20];
    float balance;
};

struct node {
    struct bank_record record;
    struct node* next;
};

void add_record(struct node** head, struct bank_record rec) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->record = rec;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void print_records(struct node* head) {
    printf("\nBank Records:\n");
    while (head != NULL) {
        printf("ID: %d\nName: %s\nBalance: $%.2f\n\n",
               head->record.id,
               head->record.name,
               head->record.balance);
        head = head->next;
    }
}

int main() {
    struct node* records = NULL;
    struct bank_record rec1 = {1, "John Smith", 1000.0};
    struct bank_record rec2 = {2, "Jane Doe", 500.0};
    struct bank_record rec3 = {3, "Bob Johnson", 250.0};
    add_record(&records, rec1);
    add_record(&records, rec2);
    add_record(&records, rec3);
    print_records(records);
    return 0;
}