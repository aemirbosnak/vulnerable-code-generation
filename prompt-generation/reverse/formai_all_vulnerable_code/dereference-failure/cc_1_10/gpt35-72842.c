//FormAI DATASET v1.0 Category: Phone Book ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone_number[20];
};

struct Node {
    struct Contact contact;
    struct Node *next;
};

void addContact(struct Node **first, struct Node **last, struct Contact newContact);
void searchContact(struct Node *first, char name[]);
void deleteContact(struct Node **first, char name[]);
void printContacts(struct Node *first);

int main() {
    struct Node *first = NULL;
    struct Node *last = NULL;
    int choice;
    do {
        printf("\nPhone Book Menu\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Delete Contact\n");
        printf("4. Print All Contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter contact name: ");
                char name[50];
                scanf("%s", name);
                printf("Enter phone number: ");
                char phone_number[20];
                scanf("%s", phone_number);
                struct Contact newContact;
                strcpy(newContact.name, name);
                strcpy(newContact.phone_number, phone_number);
                addContact(&first, &last, newContact);
                printf("Contact added successfully!\n");
                break;
            case 2:
                printf("Enter contact name: ");
                char searchName[50];
                scanf("%s", searchName);
                searchContact(first, searchName);
                break;
            case 3:
                printf("Enter contact name: ");
                char deleteName[50];
                scanf("%s", deleteName);
                deleteContact(&first, deleteName);
                break;
            case 4:
                printContacts(first);
                break;
            case 5:
                printf("Exiting Phone Book. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);
    return 0;
}

void addContact(struct Node **first, struct Node **last, struct Contact newContact) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->contact = newContact;
    newNode->next = NULL;
    if (*first == NULL) {
        *first = newNode;
        *last = newNode;
    } else {
        (*last)->next = newNode;
        *last = newNode;
    }
}

void searchContact(struct Node *first, char name[]) {
    while (first != NULL) {
        if (strcmp(first->contact.name, name) == 0) {
            printf("Contact found!\n");
            printf("Name: %s\n", first->contact.name);
            printf("Phone Number: %s\n", first->contact.phone_number);
            return;
        }
        first = first->next;
    }
    printf("Contact not found. Try again.\n");
}

void deleteContact(struct Node **first, char name[]) {
    struct Node *prev = NULL;
    struct Node *curr = *first;
    while (curr != NULL) {
        if (strcmp(curr->contact.name, name) == 0) {
            if (prev == NULL) {
                *first = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            printf("Contact deleted successfully!\n");
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Contact not found. Try again.\n");
}

void printContacts(struct Node *first) {
    if (first == NULL) {
        printf("Phone Book is empty. Add some contacts first.\n");
        return;
    }
    while (first != NULL) {
        printf("Name: %s\n", first->contact.name);
        printf("Phone Number: %s\n\n", first->contact.phone_number);
        first = first->next;
    }
}