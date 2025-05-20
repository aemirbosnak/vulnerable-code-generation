//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: minimalist
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void insert(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* current = *head;

    while (current!= NULL && current->data < data) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void deleteNode(Node** head, int data) {
    Node* current = *head;
    Node* previous = NULL;

    while (current!= NULL && current->data!= data) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with data %d not found\n", data);
        return;
    }

    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
}

void printList(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    insert(&head, 1);
    insert(&head, 3);
    insert(&head, 5);
    insert(&head, 7);

    printf("Linked List: ");
    printList(head);

    deleteNode(&head, 5);

    printf("\nLinked List after deleting node with data 5: ");
    printList(head);

    return 0;
}