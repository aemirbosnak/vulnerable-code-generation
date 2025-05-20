//FormAI DATASET v1.0 Category: Linked list operations ; Style: real-life
#include<stdlib.h>
#include<stdio.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node *insertAtBegin(struct Node *head, int data) {
    struct Node *newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}

void insertAtEnd(struct Node *head, int data) {
    struct Node *newNode = createNode(data);
    struct Node *temp = head;
    if(head == NULL) {
        head = newNode;
        return;
    }
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}

struct Node *deleteAtBegin(struct Node *head) {
    if(head == NULL) {
        printf("List is empty\n");
        return head;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

void deleteAtEnd(struct Node *head) {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    if(head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    struct Node *lastNode = temp->next;
    temp->next = NULL;
    free(lastNode);
    return;
}

void displayList(struct Node *head) {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    while(temp!= NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;

    head = insertAtBegin(head, 10);
    head = insertAtBegin(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    printf("Linked List: ");
    displayList(head);

    head = deleteAtBegin(head);
    deleteAtEnd(head);

    printf("Linked List after deletion: ");
    displayList(head);
    
    return 0;
}