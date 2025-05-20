//FormAI DATASET v1.0 Category: Linked list operations ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

/* Define the structure for each node in the linked list */
struct Node {
    int value;
    struct Node* next;
};

/* Function to append a new Node to the end of the list */
void appendNode(struct Node** headRef, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    
    /* If headRef is empty, make the new node the head */
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    
    /* Find the last node in the list */
    struct Node* lastNode = *headRef;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    
    /* Append the new node to the end of the list */
    lastNode->next = newNode;
}

/* Function to delete a node with a given value from the list */
void deleteNode(struct Node** headRef, int value) {
    struct Node* currentNode = *headRef;
    struct Node* prevNode = NULL;
    
    /* Traverse the list until the node with the desired value is found */
    while (currentNode != NULL && currentNode->value != value) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    
    /* If the node wasn't found, return without doing anything */
    if (currentNode == NULL) {
        return;
    }
    
    /* If the node is the head, update the head pointer */
    if (prevNode == NULL) {
        *headRef = currentNode->next;
    }
    /* Otherwise, update the previous node's next pointer */
    else {
        prevNode->next = currentNode->next;
    }
    
    /* Free the memory used by the deleted node */
    free(currentNode);
}

/* Function to print the values of all nodes in the list */
void printList(struct Node* head) {
    struct Node* currentNode = head;
    
    while (currentNode != NULL) {
        printf("%d ", currentNode->value);
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    
    /* Append nodes with values 0-9 to the list */
    for (int i = 0; i < 10; i++) {
        appendNode(&head, i);
    }
    
    /* Print the initial list */
    printf("Initial list: ");
    printList(head);
    
    /* Delete nodes with values 2 and 7 */
    deleteNode(&head, 2);
    deleteNode(&head, 7);
    
    /* Print the modified list */
    printf("Modified list: ");
    printList(head);
    
    /* Free the memory used by the remaining nodes */
    while (head != NULL) {
        struct Node* nextNode = head->next;
        free(head);
        head = nextNode;
    }
    
    return 0;
}