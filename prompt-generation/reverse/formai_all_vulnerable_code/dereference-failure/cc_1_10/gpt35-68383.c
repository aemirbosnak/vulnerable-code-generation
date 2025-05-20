//FormAI DATASET v1.0 Category: Linked list operations ; Style: happy
#include <stdio.h>
#include <stdlib.h>

/* Define the node structure */
struct node {
    int data;
    struct node* next;
};

/* Display the linked list */
void displayList(struct node* head) {
    struct node* current = head;
    printf("Here is the linked list: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n\n");
}

/* Insert a node at the beginning of the list */
void insertAtBeginning(struct node** headRef, int newData) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = newData;
    newNode->next = (*headRef);
    (*headRef) = newNode;
    printf("%d added to the beginning of the list.\n\n", newData);
}

/* Insert a node at the end of the list */
void insertAtEnd(struct node** headRef, int newData) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = newData;
    newNode->next = NULL;
    if (*headRef == NULL) {
        *headRef = newNode;
        printf("%d added to the end of the list.\n\n", newData);
        return;
    }
    struct node* last = *headRef;
    while (last->next != NULL)
        last = last->next;
    last->next = newNode;
    printf("%d added to the end of the list.\n\n", newData);
}

/* Delete the first occurrence of a node */
void deleteNode(struct node** headRef, int key) {
    struct node* temp = *headRef, *prev;
    if (temp != NULL && temp->data == key) {
        *headRef = temp->next;
        free(temp);
        printf("%d deleted from the list.\n\n", key);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("%d is not in the list.\n\n", key);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("%d deleted from the list.\n\n", key);
}

/* Reverse the linked list */
void reverseList(struct node** headRef) {
    struct node* prev = NULL;
    struct node* current = *headRef;
    struct node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *headRef = prev;
    printf("The linked list has been reversed.\n\n");
}

/* Main program */
int main() {
    struct node* head = NULL;
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 4);
    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 6);
    insertAtBeginning(&head, 0);
    displayList(head);
    deleteNode(&head, 3);
    displayList(head);
    deleteNode(&head, 0);
    displayList(head);
    reverseList(&head);
    displayList(head);
    return 0;
}