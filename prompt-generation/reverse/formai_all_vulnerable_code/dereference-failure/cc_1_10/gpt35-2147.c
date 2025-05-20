//FormAI DATASET v1.0 Category: Data structures visualization ; Style: portable
#include<stdio.h>
#include<stdlib.h>

// Struct for a Node in the List
struct node {
    int value;
    struct node *next;
};

// Function to create a new node with given value
struct node* createNode(int value) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to add a new node to the end of the List
struct node* append(struct node *head, int value) {
    if(head == NULL) {
        head = createNode(value);
    } else {
        struct node *newNode = createNode(value);
        struct node *currentNode = head;
        while(currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
    return head;
}

// Function to print the List
void printList(struct node *head) {
    struct node *currentNode = head;
    while(currentNode != NULL) {
        printf("%d ", currentNode->value);
        currentNode = currentNode->next;
    }
    printf("\n");
}

// Function to reverse the List
struct node* reverseList(struct node *head) {
    struct node *prevNode = NULL;
    struct node *currentNode = head;
    struct node *nextNode = NULL;
    while(currentNode != NULL) {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    head = prevNode;
    return head;
}

int main() {
    // Initial List : 
    struct node *head = createNode(1);
    head = append(head, 2);
    head = append(head, 3);
    head = append(head, 4);
    head = append(head, 5);
    printf("Initial List : ");
    printList(head);
    
    // Reversed List : 
    head = reverseList(head);
    printf("Reversed List : ");
    printList(head);
    
    return 0;
}