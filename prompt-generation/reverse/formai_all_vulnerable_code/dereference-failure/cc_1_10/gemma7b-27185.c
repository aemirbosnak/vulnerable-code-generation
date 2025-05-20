//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct Node {
    char item[20];
    int quantity;
    struct Node* next;
};

void insertAtTail(struct Node** head, char item, int quantity) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->item, item);
    newNode->quantity = quantity;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void traverseList(struct Node* head) {
    while (head) {
        printf("%s - %d\n", head->item, head->quantity);
        head = head->next;
    }
}

int findItem(struct Node* head, char item) {
    while (head) {
        if (strcmp(head->item, item) == 0) {
            return head->quantity;
        }
        head = head->next;
    }

    return -1;
}

int main() {
    struct Node* head = NULL;

    insertAtTail(&head, "Apple", 10);
    insertAtTail(&head, "Banana", 20);
    insertAtTail(&head, "Orange", 30);

    traverseList(head);

    int quantity = findItem(head, "Apple");

    if (quantity != -1) {
        printf("Quantity of Apple: %d\n", quantity);
    } else {
        printf("Item not found.\n");
    }

    return 0;
}