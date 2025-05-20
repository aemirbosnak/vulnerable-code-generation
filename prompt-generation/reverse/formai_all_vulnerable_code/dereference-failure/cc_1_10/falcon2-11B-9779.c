//Falcon2-11B DATASET v1.0 Category: Memory management ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* temp = NULL;

    // Create a new node with data 5
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Failed to allocate memory\n");
        return -1;
    }
    newNode->data = 5;
    newNode->next = NULL;

    // Add the new node to the beginning of the list
    temp = head;
    head = newNode;
    newNode->next = temp;

    // Print the list
    printf("List before adding 5: ");
    printList(head);

    // Add another node with data 10
    newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Failed to allocate memory\n");
        return -1;
    }
    newNode->data = 10;
    newNode->next = NULL;

    // Add the new node to the end of the list
    temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

    // Print the list again
    printf("List after adding 10: ");
    printList(head);

    // Free the memory used by the new nodes
    free(newNode);
    free(newNode);

    // Free the memory used by the list
    struct Node* temp2 = head;
    while (temp2!= NULL) {
        struct Node* temp3 = temp2->next;
        free(temp2);
        temp2 = temp3;
    }

    return 0;
}