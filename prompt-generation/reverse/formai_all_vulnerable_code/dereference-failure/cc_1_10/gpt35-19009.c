//FormAI DATASET v1.0 Category: Mailing list manager ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct {
    char name[MAX_LEN];
    char email[MAX_LEN];
} Contact;

typedef struct linkedlist {
    Contact contact;
    struct linkedlist* next;
} LinkedList;

int get_menu_choice() {
    int choice;
    printf("Choose an option:\n");
    printf("1. Add contact.\n");
    printf("2. Delete contact.\n");
    printf("3. Display all contacts.\n");
    printf("4. Exit.\n");
    printf("> ");
    scanf("%d", &choice);
    return choice;
}

void add_contact(LinkedList** head, char* name, char* email) {
    LinkedList* new_contact = malloc(sizeof(LinkedList));
    strcpy(new_contact->contact.name, name);
    strcpy(new_contact->contact.email, email);
    new_contact->next = *head;
    *head = new_contact;
}

void delete_contact(LinkedList** head, char* name, char* email) {
    LinkedList* current = *head;
    LinkedList* previous = NULL;
    while (current != NULL) {
        if ((strcmp(current->contact.name, name) == 0) && (strcmp(current->contact.email, email) == 0)) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Contact deleted.\n");
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Contact not found.\n");
}

void display_all_contacts(LinkedList* head) {
    if (head == NULL) {
        printf("No contacts found.\n");
        return;
    }
    LinkedList* current = head;
    while (current != NULL) {
        printf("Name: %s\n", current->contact.name);
        printf("Email: %s\n", current->contact.email);
        current = current->next;
    }
}

int main() {
    LinkedList* head = NULL;
    while (1) {
        switch (get_menu_choice()) {
            case 1: {
                char name[MAX_LEN], email[MAX_LEN];
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                add_contact(&head, name, email);
                printf("Contact added.\n");
                break;
            }
            case 2: {
                char name[MAX_LEN], email[MAX_LEN];
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                delete_contact(&head, name, email);
                break;
            }
            case 3:
                display_all_contacts(head);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}