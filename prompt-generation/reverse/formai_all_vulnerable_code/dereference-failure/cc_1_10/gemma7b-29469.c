//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    char item_name[50];
    int quantity;
    struct Node* next;
} Node;

void insert_at_tail(Node** head, char item_name, int quantity) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->item_name, item_name);
    newNode->quantity = quantity;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void search_item(Node* head, char item_name) {
    while (head) {
        if (strcmp(head->item_name, item_name) == 0) {
            printf("Item name: %s, Quantity: %d\n", head->item_name, head->quantity);
            return;
        }
        head = head->next;
    }

    printf("Item not found.\n");
}

int main() {
    Node* head = NULL;

    insert_at_tail(&head, "Sherlock Holmes", 10);
    insert_at_tail(&head, "John Watson", 5);
    insert_at_tail(&head, "Inspector Lestrade", 2);

    search_item(head, "Sherlock Holmes");
    search_item(head, "John Watson");
    search_item(head, "Inspector Lestrade");
    search_item(head, "Mr. Bojangle");

    return 0;
}