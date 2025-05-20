//FormAI DATASET v1.0 Category: Linked list operations ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void printList(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void insertAtBeginning(struct node** headRef, int newData) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
    printf("%d inserted at the beginning\n", newData);
}

void insertAtEnd(struct node** headRef, int newData) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = newData;
    newNode->next = NULL;

    if (*headRef == NULL) {
        *headRef = newNode;
        printf("%d inserted at the end\n", newData);
        return;
    }

    struct node* lastNode = *headRef;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
    printf("%d inserted at the end\n", newData);
}

void deleteFirstNode(struct node** headRef) {
    if (*headRef == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node* temp = *headRef;
    *headRef = (*headRef)->next;
    free(temp);
    printf("First node deleted!\n");
}

void deleteLastNode(struct node** headRef) {
    if (*headRef == NULL) {
        printf("List is empty!\n");
        return;
    }

    if ((*headRef)->next == NULL) {
        free(*headRef);
        *headRef = NULL;
        printf("Last node deleted!\n");
        return;
    }

    struct node* lastNode = *headRef;
    struct node* prevNode = NULL;

    while (lastNode->next != NULL) {
        prevNode = lastNode;
        lastNode = lastNode->next;
    }

    free(lastNode);
    prevNode->next = NULL;
    printf("Last node deleted!\n");
}

void deleteNodeAtIndex(struct node** headRef, int index) {
    if (*headRef == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node* currentNode = *headRef;
    struct node* previousNode = NULL;

    int currentIndex = 0;

    while (currentNode != NULL && currentIndex != index) {
        previousNode = currentNode;
        currentNode = currentNode->next;
        currentIndex++;
    }

    if (currentNode == NULL) {
        printf("Invalid index!\n");
        return;
    }

    if (previousNode == NULL) {
        *headRef = currentNode->next;
    } else {
        previousNode->next = currentNode->next;
    }

    free(currentNode);
    printf("Node at index %d deleted!\n", index);
}

void searchForValue(struct node* head, int value) {
    int index = 0;
    while (head != NULL) {
        if (head->data == value) {
            printf("%d found at index %d\n", value, index);
            return;
        }
        head = head->next;
        index++;
    }
    printf("%d not found in the list\n", value);
}

int main() {
    struct node* head = NULL;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtBeginning(&head, 0);

    printList(head);

    deleteFirstNode(&head);
    deleteLastNode(&head);
    deleteNodeAtIndex(&head, 1);

    printList(head);

    searchForValue(head, 2);
    searchForValue(head, 5);

    return 0;
}