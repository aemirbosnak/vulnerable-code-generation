//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    char name[MAX];
    int quantity;
    struct Node* next;
} Node;

Node* Insert(Node* head, char* name, int quantity) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->quantity = quantity;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

void PrintInventory(Node* head) {
    printf("Inventory:\n");
    while (head) {
        printf("%s: %d\n", head->name, head->quantity);
        head = head->next;
    }
}

int main() {
    Node* head = NULL;

    Insert(head, "Apple", 10);
    Insert(head, "Banana", 5);
    Insert(head, "Orange", 7);
    Insert(head, "Peach", 8);

    PrintInventory(head);

    return 0;
}