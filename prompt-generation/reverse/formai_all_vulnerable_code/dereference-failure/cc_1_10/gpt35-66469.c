//FormAI DATASET v1.0 Category: Linked list operations ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertFront(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    printf("%d inserted at the front of the list.\n", data);
}

void insertLast(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        printf("%d inserted at the end of the list.\n", data);
        return;
    }
    struct Node* curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
    printf("%d inserted at the end of the list.\n", data);
}

void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head, *prev;
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        printf("%d deleted from the list.\n", key);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("%d not found in the list.\n", key);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("%d deleted from the list.\n", key);
}

void displayList(struct Node* head) {
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
    struct Node* list = NULL;
    int choice, value;
    while (1) {
        printf("\nLinked List Operations\n");
        printf("-----------------------\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Delete a Node\n");
        printf("4. Display the List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            insertFront(&list, value);
            break;
        case 2:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            insertLast(&list, value);
            break;
        case 3:
            printf("Enter the value to be deleted: ");
            scanf("%d", &value);
            deleteNode(&list, value);
            break;
        case 4:
            displayList(list);
            break;
        case 5:
            printf("Exiting program...\n");
            exit(0);
            break;
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}