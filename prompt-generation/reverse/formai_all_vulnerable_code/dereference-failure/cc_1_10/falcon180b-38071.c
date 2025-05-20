//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure
struct node {
    char data[MAX_SIZE];
    struct node* next;
};

// Function to add a new node at the end of the list
void addNode(struct node** head, char data[]) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to search for a node with the given data
struct node* searchNode(struct node* head, char data[]) {
    struct node* temp = head;
    while (temp!= NULL) {
        if (strcmp(temp->data, data) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to delete a node with the given data
void deleteNode(struct node** head, char data[]) {
    struct node* temp = *head;
    struct node* prev = NULL;

    if (strcmp(temp->data, data) == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && strcmp(temp->data, data)!= 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to print the list
void printList(struct node* head) {
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;

    // Adding nodes to the list
    addNode(&head, "apple");
    addNode(&head, "banana");
    addNode(&head, "cherry");
    addNode(&head, "date");

    // Printing the list
    printf("List after adding nodes:\n");
    printList(head);

    // Searching for a node
    struct node* searchResult = searchNode(head, "banana");
    if (searchResult!= NULL) {
        printf("Node found with data: %s\n", searchResult->data);
    } else {
        printf("Node not found\n");
    }

    // Deleting a node
    deleteNode(&head, "cherry");

    // Printing the list after deletion
    printf("List after deleting a node:\n");
    printList(head);

    return 0;
}