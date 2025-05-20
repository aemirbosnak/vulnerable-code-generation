//FormAI DATASET v1.0 Category: Linked list operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

void insertAtEnd(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    struct Node* last = *headRef;
    newNode->data = newData;
    newNode->next = NULL;
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = newNode;
    return;
}

void insertAfter(struct Node* prevNode, int newData) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL");
        return;
    }
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void deleteNode(struct Node **headRef, int key) { 
    struct Node* temp = *headRef, *prev;
    if (temp != NULL && temp->data == key) {
        *headRef = temp->next;   
        free(temp);               
        return;
    }
     while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);  
}

void deleteList(struct Node** headRef) {
   struct Node* current = *headRef;
   struct Node* next;

   while (current != NULL) {
       next = current->next;
       free(current);
       current = next;
   }
  
   *headRef = NULL;
}

void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 6);
    insertAfter(head->next, 7);
    printf("Initial List is: ");
    printList(head);

    deleteNode(&head,6);
    printf("\nModified List after deletion of 6: ");
    printList(head);

    deleteList(&head);
    printf("\nList deleted!");

    return 0;
}