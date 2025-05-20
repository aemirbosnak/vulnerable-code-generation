//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

// Shocking Name for our Linked List
typedef struct {
    int data;
    char *name;
    struct Node *next;
} ShockNode;

// Function Prototypes
ShockNode *createNode(int data, char *name);
void insertAtHead(ShockNode **head, int data, char *name);
void printList(ShockNode *node);
void freeList(ShockNode **head);

int main(int argc, char *argv[]) {

    // Initialize the Head Node to NULL
    ShockNode *head = NULL;

    // Lets insert some nodes with data and names in a shocking way
    printf("*** INSERTING SHOCKING NODES INTO THE LIST ***\n");
    insertAtHead(&head, 666, "THE DEVIL");
    insertAtHead(&head, 420, "MR.420");
    insertAtHead(&head, 1337, "M4ster");
    insertAtHead(&head, 69, "S3X");

    // Printing the List in a Shocking Way
    printf("*** PRINTING THE SHOCKING LIST ***\n");
    printList(head);

    // Freeing the List in a Shocking Way
    printf("*** FREEING THE SHOCKING MEMORY ***\n");
    freeList(&head);

    return 0;
}

// Function to create a new Node
ShockNode *createNode(int data, char *name) {
    ShockNode *newNode = (ShockNode *)malloc(sizeof(ShockNode));
    newNode->data = data;
    newNode->name = strdup(name);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new Node at the head of the list
void insertAtHead(ShockNode **head, int data, char *name) {
    ShockNode *newNode = createNode(data, name);
    newNode->next = *head;
    *head = newNode;
}

// Function to print the list
void printList(ShockNode *node) {
    while (node != NULL) {
        printf("| %d | %s |\n", node->data, node->name);
        node = node->next;
    }
}

// Function to free the list
void freeList(ShockNode **head) {
    ShockNode *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp->name);
        free(temp);
    }
}