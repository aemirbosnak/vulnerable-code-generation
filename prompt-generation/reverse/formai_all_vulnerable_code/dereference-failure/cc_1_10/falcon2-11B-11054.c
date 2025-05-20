//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: lively
#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* next;
    int data;
};

struct node* head = NULL;

/* Function to create a new node with given data */
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* Function to insert a new node at the beginning of the list */
void insertAtHead(int data) {
    struct node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

/* Function to insert a new node at the end of the list */
void insertAtEnd(int data) {
    struct node* newNode = createNode(data);
    struct node* current = head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newNode;
}

/* Function to search for an element in the list */
int search(int data) {
    struct node* current = head;
    while (current!= NULL) {
        if (current->data == data) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

/* Function to delete a node from the list */
void deleteNode(struct node* node) {
    struct node* temp = head;
    while (temp!= NULL && temp->next!= node) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    if (temp->next == NULL) {
        temp->next = NULL;
    } else {
        temp->next = temp->next->next;
    }
    free(node);
}

/* Function to print the contents of the list */
void printList() {
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insertAtHead(5);
    insertAtHead(10);
    insertAtHead(15);
    insertAtHead(20);
    printList();
    printf("Search for 5: %d\n", search(5));
    printf("Search for 25: %d\n", search(25));
    printf("Delete 10: ");
    deleteNode(head->next);
    printList();
    return 0;
}