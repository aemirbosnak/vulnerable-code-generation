//FormAI DATASET v1.0 Category: Mailing list manager ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char email[50];
    struct Node* next;
} Node;

Node* head = NULL;

void addEmail(char* email) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->email, email);

    if (head == NULL) {
        head = newNode;
        head->next = NULL;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = NULL;
    }

    printf("Email added: %s\n", email);
}

void displayList() {
    if (head == NULL) {
        printf("Mailing list is empty.\n");
    } else {
        printf("Mailing list:\n");
        Node* current = head;
        while (current != NULL) {
            printf("- %s\n", current->email);
            current = current->next;
        }
    }
}

void removeEmail(char* email) {
    if (head == NULL) {
        printf("Mailing list is empty.\n");
    } else if (strcmp(head->email, email) == 0) {
        Node* temp = head;
        head = head->next;
        free(temp);
        printf("Email removed: %s\n", email);
    } else {
        Node* previous = head;
        Node* current = head->next;

        while (current != NULL) {
            if (strcmp(current->email, email) == 0) {
                previous->next = current->next;
                free(current);
                printf("Email removed: %s\n", email);
                return;
            }
            previous = current;
            current = current->next;
        }
        printf("Email not found.\n");
    }
}

int main() {
    int choice;
    char email[50];

    do {
        printf("\n1. Add email to mailing list\n");
        printf("2. Remove email from mailing list\n");
        printf("3. Display mailing list\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter email to add: ");
                scanf("%s", email);
                addEmail(email);
                break;
            case 2:
                printf("\nEnter email to remove: ");
                scanf("%s", email);
                removeEmail(email);
                break;
            case 3:
                displayList();
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}