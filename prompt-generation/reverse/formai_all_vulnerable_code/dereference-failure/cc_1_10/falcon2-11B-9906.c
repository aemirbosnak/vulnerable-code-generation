//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void deleteNode(Node** head, int key) {
    if (*head == NULL) {
        return;
    }
    Node* temp = *head;
    if (temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp->next!= NULL && temp->next->data!= key) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        return;
    }
    Node* temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
}

void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    printList(head);
    deleteNode(&head, 30);
    printList(head);
    return 0;
}