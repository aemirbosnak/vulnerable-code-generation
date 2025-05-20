//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int item_id;
    char item_name[50];
    int quantity;
    struct Node* next;
} Node;

Node* InsertAtTail(Node* head, int item_id, char item_name[], int quantity) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item_id = item_id;
    strcpy(newNode->item_name, item_name);
    newNode->quantity = quantity;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

int SearchItem(Node* head, int item_id) {
    while (head) {
        if (head->item_id == item_id) {
            return 1;
        }
        head = head->next;
    }

    return 0;
}

void UpdateQuantity(Node* head, int item_id, int new_quantity) {
    while (head) {
        if (head->item_id == item_id) {
            head->quantity = new_quantity;
            return;
        }
        head = head->next;
    }

    return;
}

void PrintInventory(Node* head) {
    printf("Inventory:\n");
    while (head) {
        printf("%d. %s - %d\n", head->item_id, head->item_name, head->quantity);
        head = head->next;
    }
}

int main() {
    Node* head = NULL;

    InsertAtTail(head, 1, "Apple", 10);
    InsertAtTail(head, 2, "Banana", 5);
    InsertAtTail(head, 3, "Orange", 7);

    PrintInventory(head);

    UpdateQuantity(head, 2, 12);

    PrintInventory(head);

    if (SearchItem(head, 3)) {
        printf("Item found.\n");
    } else {
        printf("Item not found.\n");
    }

    return 0;
}