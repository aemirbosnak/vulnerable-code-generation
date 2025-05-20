//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Node {
    char name[20];
    int quantity;
    struct Node* next;
} Node;

void insertAtTail(Node** head, char* name, int quantity)
{
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->quantity = quantity;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void searchByName(Node* head, char* name)
{
    while (head) {
        if (strcmp(head->name, name) == 0) {
            printf("Quantity: %d\n", head->quantity);
            return;
        }
        head = head->next;
    }

    printf("Item not found.\n");
}

int main()
{
    Node* head = NULL;

    insertAtTail(&head, "Apple", 10);
    insertAtTail(&head, "Banana", 20);
    insertAtTail(&head, "Orange", 30);

    searchByName(head, "Apple");
    searchByName(head, "Banana");
    searchByName(head, "Orange");
    searchByName(head, "Grapes");

    return 0;
}