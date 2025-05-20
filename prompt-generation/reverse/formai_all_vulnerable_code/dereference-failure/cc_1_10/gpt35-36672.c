//FormAI DATASET v1.0 Category: Mailing list manager ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct Contact {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    struct Contact* next;
} Contact;

Contact* createContact(char* name, char* email) {
    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->email, email);
    newContact->next = NULL;
    return newContact;
}

void printContacts(Contact* head) {
    printf("Contacts:\n");
    while (head != NULL) {
        printf("Name: %s \t Email: %s \n", head->name, head->email);
        head = head->next;
    }
}

void addContact(Contact** head, char* name, char* email) {
    Contact* newContact = createContact(name, email);
    newContact->next = *head;
    *head = newContact;
}

void deleteContact(Contact** head, char* name) {
    Contact* current = *head;
    Contact* prev = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

int main() {
    Contact* head = NULL;
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    int choice;

    do {
        printf("\nMenu\n");
        printf("1. Add contact\n");
        printf("2. Delete contact\n");
        printf("3. Print contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                addContact(&head, name, email);
                break;
            case 2:
                printf("\nEnter name to delete: ");
                scanf("%s", name);
                deleteContact(&head, name);
                break;
            case 3:
                printContacts(head);
                break;
            case 4:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice\n");
                break;
        }

    } while (choice != 4);

    return 0;
}