//FormAI DATASET v1.0 Category: Phone Book ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_NUMBER_LENGTH 15

typedef struct Contact {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
    struct Contact* next;
} Contact;

Contact* head = NULL;

void addContact(char* name, char* number);
void searchContact(char* name);
void removeContact(char* name);
void printContacts();

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];

    while (1) {
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Remove Contact\n");
        printf("4. Print Contacts\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter number: ");
                scanf("%s", number);
                addContact(name, number);
                break;
            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                searchContact(name);
                break;
            case 3:
                printf("Enter name: ");
                scanf("%s", name);
                removeContact(name);
                break;
            case 4:
                printContacts();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}

void addContact(char* name, char* number) {
    Contact* newContact = (Contact*) malloc(sizeof(Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->number, number);
    newContact->next = NULL;

    if (head == NULL) {
        head = newContact;
        printf("Contact added successfully.\n");
        return;
    }

    Contact* current = head;
    while (current->next != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("A contact with the same name already exists.\n");
            free(newContact);
            return;
        }
        current = current->next;
    }

    if (strcmp(current->name, name) == 0) {
        printf("A contact with the same name already exists.\n");
        free(newContact);
        return;
    }

    current->next = newContact;
    printf("Contact added successfully.\n");
}

void searchContact(char* name) {
    if (head == NULL) {
        printf("No contacts found.\n");
        return;
    }

    Contact* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("%s: %s\n", current->name, current->number);
            return;
        }
        current = current->next;
    }

    printf("Contact not found.\n");
}

void removeContact(char* name) {
    if (head == NULL) {
        printf("No contacts found.\n");
        return;
    }

    if (strcmp(head->name, name) == 0) {
        Contact* temp = head;
        head = head->next;
        free(temp);
        printf("Contact removed successfully.\n");
        return;
    }

    Contact* current = head;
    while (current->next != NULL) {
        if (strcmp(current->next->name, name) == 0) {
            Contact* temp = current->next;
            current->next = current->next->next;
            free(temp);
            printf("Contact removed successfully.\n");
            return;
        }
        current = current->next;
    }

    printf("Contact not found.\n");
}

void printContacts() {
    if (head == NULL) {
        printf("No contacts found.\n");
        return;
    }

    Contact* current = head;
    while (current != NULL) {
        printf("%s: %s\n", current->name, current->number);
        current = current->next;
    }
}