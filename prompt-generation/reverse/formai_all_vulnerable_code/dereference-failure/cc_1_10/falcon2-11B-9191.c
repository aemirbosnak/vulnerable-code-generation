//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int n) {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = n;
    head->next = NULL;
    return head;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* temp = *head;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(struct Node** head, int data, int pos) {
    if (pos == 0) {
        insertAtBeginning(head, data);
    } else {
        struct Node* temp = *head;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }
        insertAtEnd(&temp, data);
    }
}

void deleteAtBeginning(struct Node** head) {
    if (*head!= NULL) {
        free(*head);
        *head = (*head)->next;
        printf("Deleted at Beginning\n");
    } else {
        printf("List is Empty\n");
    }
}

void deleteAtEnd(struct Node** head) {
    if (*head!= NULL) {
        struct Node* temp = *head;
        while (temp->next->next!= NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
        printf("Deleted at End\n");
    } else {
        printf("List is Empty\n");
    }
}

void deleteAtPosition(struct Node** head, int pos) {
    if (pos == 0) {
        deleteAtBeginning(head);
    } else {
        struct Node* temp = *head;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }
        deleteAtEnd(&temp);
    }
}

int main() {
    struct Node* head = createList(10);
    printf("Initial List: ");
    printList(head);
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 15);
    insertAtBeginning(&head, 20);
    printf("After Insertion at Beginning: ");
    printList(head);
    insertAtEnd(&head, 25);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 35);
    printf("After Insertion at End: ");
    printList(head);
    insertAtPosition(&head, 40, 2);
    insertAtPosition(&head, 45, 5);
    insertAtPosition(&head, 50, 8);
    printf("After Insertion at Position: ");
    printList(head);
    deleteAtBeginning(&head);
    printf("After Deletion at Beginning: ");
    printList(head);
    deleteAtEnd(&head);
    printf("After Deletion at End: ");
    printList(head);
    deleteAtPosition(&head, 3);
    printf("After Deletion at Position: ");
    printList(head);
    return 0;
}