//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LEN 100

typedef struct Node {
    char email[MAX_EMAIL_LEN];
    struct Node* next;
} Node;

Node* head = NULL;

void addEmail(const char* email) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->email, email);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    printf("Added: %s\n", email);
}

void deleteEmail(const char* email) {
    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && strcmp(temp->email, email) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Email %s not found in the list.\n", email);
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Deleted: %s\n", email);
}

void displayEmails() {
    Node* temp = head;
    if (temp == NULL) {
        printf("The mailing list is empty.\n");
        return;
    }
    printf("Mailing List:\n");
    while (temp != NULL) {
        printf("- %s\n", temp->email);
        temp = temp->next;
    }
}

void freeList() {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int choice;
    char email[MAX_EMAIL_LEN];

    while (1) {
        printf("\n=== Mailing List Manager ===\n");
        printf("1. Add Email\n");
        printf("2. Delete Email\n");
        printf("3. Display Emails\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, MAX_EMAIL_LEN, stdin);
                email[strcspn(email, "\n")] = '\0'; // Remove newline
                addEmail(email);
                break;
            case 2:
                printf("Enter email to delete: ");
                fgets(email, MAX_EMAIL_LEN, stdin);
                email[strcspn(email, "\n")] = '\0'; // Remove newline
                deleteEmail(email);
                break;
            case 3:
                displayEmails();
                break;
            case 4:
                freeList();
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }
}