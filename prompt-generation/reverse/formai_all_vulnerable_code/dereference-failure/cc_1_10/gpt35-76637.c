//FormAI DATASET v1.0 Category: Memory management ; Style: safe
#include <stdio.h>
#include <stdlib.h>

/* Node of the singly linked list */
struct Node {
    int data;
    struct Node* next;
};

/* Global head pointer to store the starting address of the linked list */
struct Node* head = NULL;

/* Function to create a new node with given data */
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

/* Function to add a node at the front of the linked list */
void addFront(int data)
{
    /* Create a new node */
    struct Node* newNode = createNode(data);

    /* Set the next of new node to head */
    newNode->next = head;

    /* Update head to point to the new node */
    head = newNode;
}

/* Function to delete a node from the linked list */
void deleteNode(int key)
{
    struct Node* temp = head;
    struct Node* prev = NULL;

    /* If head node itself holds the key to be deleted */
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return;
    }

    /* Search for the key to be deleted */
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    /* If key was not present in linked list */
    if (temp == NULL) {
        printf("Key not found in the list!\n");
        return;
    }

    /* Unlink the node from linked list */
    prev->next = temp->next;

    /* Free the memory allocated to the node */
    free(temp);
}

/* Function to display the linked list */
void displayList()
{
    struct Node* temp = head;

    if (temp == NULL) {
        printf("Linked list is empty!\n");
        return;
    }

    printf("Linked list: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

/* Function to free the memory allocated to the linked list */
void freeList()
{
    struct Node* temp;

    /* Traverse the linked list and free each node */
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

/* Main function */
int main()
{
    addFront(3);
    addFront(5);
    addFront(8);
    displayList();

    deleteNode(5);
    displayList();

    deleteNode(10);
    displayList();

    freeList();

    return 0;
}