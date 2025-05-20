//FormAI DATASET v1.0 Category: Mailing list manager ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char email[50];
    struct Node* next;
};

typedef struct Node* NODE;

NODE createNode(char email[]) {
    NODE newNode = (NODE) malloc(sizeof(struct Node));
    strcpy(newNode->email, email);
    newNode->next = NULL;
    return newNode;
}

void insertNode(NODE* head, char email[]) {
    NODE current = *head;
    NODE newNode = createNode(email);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void deleteNode(NODE* head, char email[]) {
    NODE current = *head;
    NODE prev = NULL;
    while (current != NULL && strcmp(current->email, email) != 0) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Email not found\n");
        return;
    }
    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
}

void displayList(NODE head) {
    NODE current = head;
    while (current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

int main() {
    NODE head = NULL;
    int choice;
    char email[50];
    while (1) {
        printf("\n1. Add email\n");
        printf("2. Delete email\n");
        printf("3. Display all emails\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter email: ");
                scanf("%s", email);
                insertNode(&head, email);
                printf("Email added\n");
                break;
            case 2:
                printf("Enter email: ");
                scanf("%s", email);
                deleteNode(&head, email);
                break;
            case 3:
                printf("Emails:\n");
                displayList(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}