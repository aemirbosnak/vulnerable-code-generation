//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertNode(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

Node* deleteNode(Node* head, int data) {
    Node* temp = head;
    Node* prev = NULL;

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return head;
    }

    if (prev == NULL) {
        head = temp->next;
        free(temp);
        return head;
    }

    prev->next = temp->next;
    free(temp);
    return head;
}

Node* searchNode(Node* head, int data) {
    Node* temp = head;

    while (temp!= NULL) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

int main() {
    Node* head = NULL;

    insertNode(head, 10);
    insertNode(head, 20);
    insertNode(head, 30);

    printf("Linked list before deletion: ");
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");

    Node* deletedNode = deleteNode(head, 20);

    printf("Linked list after deletion: ");
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");

    Node* foundNode = searchNode(head, 30);

    if (foundNode!= NULL) {
        printf("Node with data %d found at index %lu\n", foundNode->data, (unsigned long) foundNode);
    } else {
        printf("Node with data %d not found\n", foundNode->data);
    }

    return 0;
}