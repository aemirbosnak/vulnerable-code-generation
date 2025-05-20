//FormAI DATASET v1.0 Category: Linked list operations ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printLinkedList(struct Node* node) {
    printf("Linked List: ");
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    printf("%d inserted at the beginning.\n", data);
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("%d inserted at the end.\n", data);
}

void insertAtIndex(struct Node** head, int index, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (index == 0) {
        insertAtBeginning(head, data);
    }
    else {
        struct Node* temp = *head;
        for (int i = 0; i < index-1; i++) {
            if (temp == NULL) {
                printf("Invalid index.\n");
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        printf("%d inserted at index %d.\n", data, index);
    }
}

void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("Linked list is empty.\n");
    }
    else {
        struct Node* temp = *head;
        *head = temp->next;
        printf("%d deleted from the beginning.\n", temp->data);
        free(temp);
    }
}

void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("Linked list is empty.\n");
    }
    else if ((*head)->next == NULL) {
        printf("%d deleted from the end.\n", (*head)->data);
        free(*head);
        *head = NULL;
    }
    else {
        struct Node* temp = *head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        printf("%d deleted from the end.\n", temp->next->data);
        free(temp->next);
        temp->next = NULL;
    }
}

void deleteAtIndex(struct Node** head, int index) {
    if (*head == NULL) {
        printf("Linked list is empty.\n");
    }
    else if (index == 0) {
        deleteAtBeginning(head);
    }
    else {
        struct Node* temp = *head;
        for (int i = 0; i < index-1; i++) {
            if (temp == NULL) {
                printf("Invalid index.\n");
                return;
            }
            temp = temp->next;
        }
        struct Node* temp2 = temp->next;
        temp->next = temp2->next;
        printf("%d deleted from index %d.\n", temp2->data, index);
        free(temp2);
    }
}

void deleteAll(struct Node** head) {
    while (*head != NULL) {
        struct Node* temp = *head;
        *head = temp->next;
        free(temp);
    }
    printf("Deleted all nodes from the linked list.\n");
}

int main() {
    struct Node* head = NULL;
    insertAtBeginning(&head, 2);
    insertAtEnd(&head, 4);
    insertAtBeginning(&head, 1);
    insertAtIndex(&head, 2, 3);
    printLinkedList(head);
    deleteAtIndex(&head, 2);
    deleteAtBeginning(&head);
    deleteAtEnd(&head);
    printLinkedList(head);
    deleteAll(&head);
    printLinkedList(head);
    return 0;
}