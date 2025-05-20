//FormAI DATASET v1.0 Category: Linked list operations ; Style: lively
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("%d inserted at beginning\n", data);
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    if (*head == NULL) {
        *head = newNode;
        printf("%d inserted at end\n", data);
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("%d inserted at end\n", data);
}

void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        printf("%d inserted at position %d\n", data, position);
        return;
    }
    for (int i = 0; i < (position - 1); i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("Position %d is out of range\n", position);
            return;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("%d inserted at position %d\n", data, position);
}

void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    struct Node* temp = *head;
    *head = temp->next;
    printf("%d deleted from beginning\n", temp->data);
    free(temp);
}

void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) {
        *head = NULL;
    } else {
        prev->next = NULL;
    }
    printf("%d deleted from end\n", temp->data);
    free(temp);
}

void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if (position == 0) {
        *head = temp->next;
        printf("%d deleted from position %d\n", temp->data, position);
        free(temp);
        return;
    }
    for (int i = 0; i < position; i++) {
        prev = temp;
        temp = temp->next;
        if (temp == NULL) {
            printf("Position %d is out of range\n", position);
            return;
        }
    }
    prev->next = temp->next;
    printf("%d deleted from position %d\n", temp->data, position);
    free(temp);
}

void display(struct Node* head) {
    struct Node* temp = head;
    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;
    while (1) {
        printf("1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Delete at beginning\n5. Delete at end\n6. Delete at position\n7. Display\n8. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 4:
                deleteAtBeginning(&head);
                break;
            case 5:
                deleteAtEnd(&head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 7:
                display(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}