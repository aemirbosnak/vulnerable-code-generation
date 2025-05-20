//FormAI DATASET v1.0 Category: Data structures visualization ; Style: brave
#include <stdio.h>
#include <stdlib.h>

/* Declaration of a struct */
struct Node {
    int data;
    struct Node* next;
};

/* Function to create a new node */
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* Function to display the linked list */
void display(struct Node* node) {
    while(node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

/* Function to insert a node at the beginning */
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}

/* Function to insert a node at the end */
struct Node* insertAtEnd(struct Node* head, int data) {
    if(head == NULL) {
        head = createNode(data);
        return head;
    }
    struct Node* node = head;
    while(node->next != NULL) {
        node = node->next;
    }
    node->next = createNode(data);
    return head;
}

/* Function to insert a node at a particular position */
struct Node* insertAtPosition(struct Node* head, int data, int position) {
    if(head == NULL && position > 1) {
        printf("Sorry, the list is empty so no nodes can be inserted at the given position.\n");
        return head;
    }
    if(position == 1) {
        head = insertAtBeginning(head, data);
        return head;
    }
    struct Node* node = head;
    int count = 1;
    while(node != NULL && count < position - 1) {
        node = node->next;
        count++;
    }
    if(node == NULL) {
        printf("Sorry, the given position is out of bounds.\n");
        return head;
    }
    struct Node* newNode = createNode(data);
    newNode->next = node->next;
    node->next = newNode;
    return head;
}

/* Function to delete a node at the beginning */
struct Node* deleteAtBeginning(struct Node* head) {
    if(head == NULL) {
        printf("Sorry, the list is empty so no nodes can be deleted.\n");
        return head;
    }
    struct Node* node = head;
    head = head->next;
    free(node);
    return head;
}

/* Function to delete a node at the end */
struct Node* deleteAtEnd(struct Node* head) {
    if(head == NULL) {
        printf("Sorry, the list is empty so no nodes can be deleted.\n");
        return head;
    }
    if(head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* node = head;
    while(node->next->next != NULL) {
        node = node->next;
    }
    free(node->next);
    node->next = NULL;
    return head;
}

/* Function to delete a node at a particular position */
struct Node* deleteAtPosition(struct Node* head, int position) {
    if(head == NULL) {
        printf("Sorry, the list is empty so no nodes can be deleted.\n");
        return head;
    }
    if(position == 1) {
        head = deleteAtBeginning(head);
        return head;
    }
    struct Node* node = head;
    int count = 1;
    while(node != NULL && count < position - 1) {
        node = node->next;
        count++;
    }
    if(node == NULL || node->next == NULL) {
        printf("Sorry, the given position is out of bounds.\n");
        return head;
    }
    struct Node* toDelete = node->next;
    node->next = toDelete->next;
    free(toDelete);
    return head;
}

int main() {
    struct Node* head = NULL;
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);

    printf("List after inserting elements at the end: \n");
    display(head);

    head = insertAtBeginning(head, 0);
    head = insertAtPosition(head, -1, 2);
    head = insertAtPosition(head, 6, 7);

    printf("List after inserting elements at the beginning and at particular positions: \n");
    display(head);

    head = deleteAtBeginning(head);
    head = deleteAtEnd(head);
    head = deleteAtPosition(head, 3);

    printf("List after deleting elements from the beginning, end and a particular position: \n");
    display(head);

    return 0;
}