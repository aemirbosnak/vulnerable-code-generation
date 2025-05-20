//FormAI DATASET v1.0 Category: Linked list operations ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// Define struct for each node in the linked list
struct Node {
    int data;
    struct Node *next;
};
typedef struct Node node;

// Function to create a new node
node* createNode(int data) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
node* insertBeginning(node *head, int data) {
    node *newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}

// Function to insert a node at the end of the linked list
node* insertEnd(node *head, int data) {
    node *newNode = createNode(data);
    if(head == NULL) {
        head = newNode;
        return head;
    }
    node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to delete a node at the beginning of the linked list
node* deleteBeginning(node *head) {
    if(head == NULL) {
        printf("The linked list is already empty!\n");
        return head;
    }
    node *temp = head->next;
    free(head);
    head = temp;
    return head;
}

// Function to delete a node at the end of the linked list
node* deleteEnd(node *head) {
    if(head == NULL) {
        printf("The linked list is already empty!\n");
        return head;
    }
    node *temp = head;
    if(temp->next == NULL) {
        free(head);
        head = NULL;
        return head;
    }
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Function to print the linked list
void printList(node* head) {
    printf("Linked list: ");
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function to test the linked list operations
int main() {
    node *head = NULL;
    head = insertBeginning(head, 1);
    head = insertBeginning(head, 2);
    head = insertBeginning(head, 3);
    head = insertEnd(head, 4);
    printList(head);
    head = deleteBeginning(head);
    printList(head);
    head = deleteEnd(head);
    printList(head);
    return 0;
}