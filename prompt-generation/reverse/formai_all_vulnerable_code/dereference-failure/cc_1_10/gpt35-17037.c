//FormAI DATASET v1.0 Category: Linked list operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("\nInserted %d at beginning.", data);
}

void insertAtIndex(Node** head, int data, int index) {
    Node* tempNode = *head;

    if(index == 0) {
        insertAtBeginning(head, data);
        return;
    }

    for(int i = 0; i < index - 1; i++) {
        if(tempNode) {
            tempNode = tempNode->next;
        } else {
            printf("\nIndex out of range!");
            return;
        }
    }

    if(!tempNode) {
        printf("\nIndex out of range!");
        return;
    }

    Node* newNode = createNode(data);
    newNode->next = tempNode->next;
    tempNode->next = newNode;
    printf("\nInserted %d at index %d.", data, index);
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);

    if(!*head) {
        *head = newNode;
        printf("\nInserted %d at end.", data);
        return;
    }

    Node* tempNode = *head;

    while(tempNode->next) {
        tempNode = tempNode->next;
    }

    tempNode->next = newNode;
    printf("\nInserted %d at end.", data);
}

void deleteAtIndex(Node** head, int index) {
    if(!*head) {
        printf("\nThe linked list is empty!");
        return;
    }

    if(index == 0) {
        Node* tempNode = *head;
        *head = (*head)->next;
        free(tempNode);
        printf("\nDeleted node at index 0.");
        return;
    }

    Node* tempNode = *head;

    for(int i = 0; i < index - 1; i++) {
        if(tempNode) {
            tempNode = tempNode->next;
        } else {
            printf("\nIndex out of range!");
            return;
        }
    }

    if(!tempNode || !tempNode->next) {
        printf("\nIndex out of range!");
        return;
    }

    Node* tempNode2 = tempNode->next;
    tempNode->next = tempNode2->next;
    free(tempNode2);
    printf("\nDeleted node at index %d.", index);
}

void displayLinkedList(Node* head) {
    printf("\nLinked List: ");

    while(head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    Node* head = NULL;

    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 3);
    insertAtEnd(&head, 10);
    insertAtIndex(&head, 7, 2);
    displayLinkedList(head);
    deleteAtIndex(&head, 3);
    deleteAtIndex(&head, 0);
    displayLinkedList(head);

    return 0;
}