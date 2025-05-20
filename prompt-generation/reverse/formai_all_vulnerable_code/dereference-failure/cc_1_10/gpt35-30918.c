//FormAI DATASET v1.0 Category: Mailing list manager ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char email[50];
    struct Node* next;
} Node;

void printMenu() {
    printf("\nWelcome to the Surreal Mailing List Manager!\n");
    printf("1. Add email to list\n");
    printf("2. Remove email from list\n");
    printf("3. Print mailing list\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void addEmail(Node** head, char email[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->email, email, 50);
    newNode->next = *head;
    *head = newNode;
}

void removeEmail(Node** head, char email[]) {
    Node* current = *head;
    Node* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Email %s removed successfully.\n", email);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Email not found.\n");
}

void printList(Node* head) {
    printf("\nMailing List:\n");
    while (head != NULL) {
        printf("%s\n", head->email);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice = 0;
    char email[50];

    printf("Surreal Mailing List Manager initializing...");
    while (choice != 4) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                scanf("%s", email);
                addEmail(&head, email);
                printf("Email %s added successfully.\n", email);
                break;
            case 2:
                printf("Enter email to remove: ");
                scanf("%s", email);
                removeEmail(&head, email);
                break;
            case 3:
                printList(head);
                break;
            case 4:
                printf("Exiting Surreal Mailing List manager...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
                break;
        }
    }

    return 0;
}