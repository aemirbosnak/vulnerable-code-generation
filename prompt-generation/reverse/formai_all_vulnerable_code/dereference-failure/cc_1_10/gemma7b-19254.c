//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct node {
    int item_no;
    char item_name[20];
    int quantity;
    struct node* next;
};

void insert_at_tail(struct node** head, int item_no, char item_name[], int quantity) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->item_no = item_no;
    strcpy(new_node->item_name, item_name);
    new_node->quantity = quantity;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        (*head)->next = new_node;
        *head = new_node;
    }
}

void search(struct node* head, int item_no) {
    while (head) {
        if (head->item_no == item_no) {
            printf("Item Name: %s\n", head->item_name);
            printf("Quantity: %d\n", head->quantity);
            return;
        }
        head = head->next;
    }

    printf("Item not found.\n");
}

int main() {
    struct node* head = NULL;

    insert_at_tail(&head, 1, "Apple", 10);
    insert_at_tail(&head, 2, "Orange", 20);
    insert_at_tail(&head, 3, "Banana", 30);

    search(head, 2);

    return 0;
}