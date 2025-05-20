//FormAI DATASET v1.0 Category: Data structures visualization ; Style: lively
#include<stdio.h>
#include<stdlib.h>

// Structure to represent a Node in Linked List
struct node {
    int data;
    struct node* next;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to traverse and print the linked list
void printLinkedList(struct node* head) {
    printf(" Linked List : ");
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to insert a new node at the beginning of the linked list
struct node* insertAtBeginning(struct node* head, int data) {
    struct node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}

// Function to insert a new node at the end of the linked list
struct node* insertAtEnd(struct node* head, int data) {
    struct node* newNode = createNode(data);
    if(head == NULL) {
        head = newNode;
    } else {
        struct node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

// Function to delete a node from the linked list
struct node* deleteNode(struct node* head, int data) {
    if(head == NULL) {
        return NULL;
    }
    if(head->data == data) {
        struct node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct node* curr = head;
    while(curr->next != NULL && curr->next->data != data) {
        curr = curr->next;
    }
    if(curr->next == NULL) {
        return head;
    }
    struct node* temp = curr->next;
    curr->next = temp->next;
    free(temp);
    return head;
}

int main() {
    struct node* head = NULL;

    // Inserting initial nodes to the linked list
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);

    printf(" Initial ");
    printLinkedList(head);

    // Inserting a new node at the beginning of the linked list
    head = insertAtBeginning(head, 0);

    printf(" After inserting 0 at the beginning ");
    printLinkedList(head);

    // Deleting a node from the linked list
    head = deleteNode(head, 2);

    printf(" After deleting 2 ");
    printLinkedList(head);

    return 0;
}