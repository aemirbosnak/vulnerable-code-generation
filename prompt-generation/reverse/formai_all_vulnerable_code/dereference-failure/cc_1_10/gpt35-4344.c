//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

typedef struct Node {
    Contact contact;
    struct Node* next;
} Node;

Node* head = NULL;

void addContact(char* name, char* email) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strncpy(newNode->contact.name, name, MAX_NAME_LENGTH);
    strncpy(newNode->contact.email, email, MAX_EMAIL_LENGTH);
    newNode->next = head;
    head = newNode;
}

void displayContacts() {
    Node* cursor = head;
    while (cursor != NULL) {
        printf("%s: %s\n", cursor->contact.name, cursor->contact.email);
        cursor = cursor->next;
    }
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];

    do {
        printf("1. Add contact\n");
        printf("2. Display contacts\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                addContact(name, email);
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

    } while (choice != 3);

    return 0;
}