//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* prev;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

Node* insertNode(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        return head;
    } else {
        newNode->next = head;
        head->prev = newNode;
        newNode->prev = NULL;
        newNode->next = newNode;
        return head;
    }
}

void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    Node* current = head;
    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    Node* node1 = insertNode(head, 1);
    Node* node2 = insertNode(node1, 2);
    Node* node3 = insertNode(node2, 3);
    Node* node4 = insertNode(node3, 4);
    Node* node5 = insertNode(node4, 5);
    Node* node6 = insertNode(node5, 6);
    Node* node7 = insertNode(node6, 7);
    Node* node8 = insertNode(node7, 8);
    Node* node9 = insertNode(node8, 9);
    Node* node10 = insertNode(node9, 10);

    printList(head);

    return 0;
}