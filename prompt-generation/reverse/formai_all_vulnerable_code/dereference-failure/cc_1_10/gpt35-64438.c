//FormAI DATASET v1.0 Category: Linked list operations ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

/* Define a struct to hold our linked list nodes */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/* Declare functions to perform linked list operations */
void insert(Node** head, int data);
void deleteNode(Node** head, int key);
void printList(Node* head);

/* Main function to test the linked list operations */
int main(int argc, char **argv) {

    /* Create an empty head */
    Node* head = NULL;

    /* Insert some nodes */
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);

    /* Print the list */
    printf("Initial list: ");
    printList(head);

    /* Delete a node */
    deleteNode(&head, 3);

    /* Print the updated list */
    printf("Updated list: ");
    printList(head);

    /* Clean up memory */
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

/* Function to insert a node at the beginning of the linked list */
void insert(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = (*head);
    (*head) = newNode;
}

/* Function to delete a node with a specific key */
void deleteNode(Node** head, int key) {
    Node* prev = NULL;
    Node* curr = (*head);

    while (curr != NULL && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        return; /* Key not found */
    }

    if (prev == NULL) {
        (*head) = (*head)->next; /* Key is at head */
    } else {
        prev->next = curr->next; /* Key is not at head */
    }

    free(curr);
}

/* Function to print the linked list */
void printList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}