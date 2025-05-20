//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: creative
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void appendNode(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* temp = *head;
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void sortList(Node** head) {
    Node* curr = *head;
    Node* prev = NULL;
    while (curr!= NULL) {
        Node* next = curr->next;
        while (next!= NULL) {
            if (curr->data > next->data) {
                int temp = curr->data;
                curr->data = next->data;
                next->data = temp;
            }
            next = next->next;
        }
        curr = curr->next;
    }
}

void reverseList(Node** head) {
    Node* curr = *head;
    Node* prev = NULL;
    while (curr!= NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

int main() {
    Node* head = NULL;
    appendNode(&head, 5);
    appendNode(&head, 3);
    appendNode(&head, 7);
    appendNode(&head, 1);
    displayList(head);
    sortList(&head);
    displayList(head);
    reverseList(&head);
    displayList(head);
    return 0;
}