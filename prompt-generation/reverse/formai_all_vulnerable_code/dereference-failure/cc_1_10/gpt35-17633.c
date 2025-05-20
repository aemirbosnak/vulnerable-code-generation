//FormAI DATASET v1.0 Category: Linked list operations ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int menu() {
    int choice;
    printf("Linked list operations:\n");
    printf("1. Insert at the beginning of the list.\n");
    printf("2. Insert at the end of the list.\n");
    printf("3. Insert at a specific position in the list.\n");
    printf("4. Delete the first node in the list.\n");
    printf("5. Delete the last node in the list.\n");
    printf("6. Delete a node at a specific position in the list.\n");
    printf("7. Display the list.\n");
    printf("8. Exit.\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void insertAtBeginning(struct Node **head, int data) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    printf("%d inserted at the beginning of the list.\n", data);
}

void insertAtEnd(struct Node **head, int data) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        printf("%d inserted at the end of the list.\n", data);
        return;
    }
    struct Node *lastNode = *head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
    printf("%d inserted at the end of the list.\n", data);
}

void insertAtPosition(struct Node **head, int data, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }
    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node *currentNode = *head;
    for (int i = 1; i < position-1 && currentNode != NULL; i++) {
        currentNode = currentNode->next;
    }
    if (currentNode == NULL) {
        printf("Invalid position.\n");
        return;
    }
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    printf("%d inserted at position %d in the list.\n", data, position);
}

void deleteFirst(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("First node deleted from the list.\n");
}

void deleteLast(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Last node deleted from the list.\n");
        return;
    }
    struct Node *lastNode = *head;
    while (lastNode->next->next != NULL) {
        lastNode = lastNode->next;
    }
    free(lastNode->next);
    lastNode->next = NULL;
    printf("Last node deleted from the list.\n");
}

void deleteAtPosition(struct Node **head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }
    if (position == 1) {
        deleteFirst(head);
        return;
    }
    struct Node *currentNode = *head;
    struct Node *previousNode = NULL;
    for (int i = 1; i < position && currentNode != NULL; i++) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    if (currentNode == NULL) {
        printf("Invalid position.\n");
        return;
    }
    previousNode->next = currentNode->next;
    free(currentNode);
    printf("Node at position %d deleted from the list.\n", position);
}

void displayList(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    int choice, data, position;
    while (1) {
        choice = menu();
        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 4:
                deleteFirst(&head);
                break;
            case 5:
                deleteLast(&head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 7:
                displayList(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}