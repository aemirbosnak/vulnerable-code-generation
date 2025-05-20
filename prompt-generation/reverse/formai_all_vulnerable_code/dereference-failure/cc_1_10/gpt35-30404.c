//FormAI DATASET v1.0 Category: Phone Book ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char name[50];
    char phone_number[20];
    struct contact *next;
};

typedef struct contact contact_t;

void print_menu();
void search_contacts(contact_t *head);
void add_contact(contact_t **head);
void delete_contact(contact_t **head);
void display_contacts(contact_t *head);

int main() {

    contact_t *head = NULL;
    int choice = 0;

    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_contacts(head);
                break;
            case 2:
                search_contacts(head);
                break;
            case 3:
                add_contact(&head);
                break;
            case 4:
                delete_contact(&head);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void print_menu() {
    printf("\n*** Phone Book ***\n");
    printf("1. Display all contacts\n");
    printf("2. Search contacts\n");
    printf("3. Add contact\n");
    printf("4. Delete contact\n");
    printf("5. Exit\n");
}

void search_contacts(contact_t *head) {
    char search_name[50];
    int found = 0;
    contact_t *current = head;

    printf("Enter name to search: ");
    scanf("%s", search_name);

    while (current != NULL) {
        if (strcmp(current->name, search_name) == 0) {
            printf("%s: %s\n", current->name, current->phone_number);
            found = 1;
        }
        current = current->next;
    }

    if (!found) {
        printf("No contacts found with name: %s\n", search_name);
    }
}

void add_contact(contact_t **head) {
    char name[50], phone_number[20];
    contact_t *new_contact = (contact_t *)malloc(sizeof(contact_t));

    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter phone number: ");
    scanf("%s", phone_number);

    strcpy(new_contact->name, name);
    strcpy(new_contact->phone_number, phone_number);
    new_contact->next = *head;

    *head = new_contact;

    printf("Contact added successfully!\n");
}

void delete_contact(contact_t **head) {
    char delete_name[50];
    contact_t *current = *head, *prev = NULL;

    printf("Enter name to delete: ");
    scanf("%s", delete_name);

    while (current != NULL) {
        if (strcmp(current->name, delete_name) == 0) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Contact deleted successfully!\n");
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Contact not found with name: %s\n", delete_name);
}

void display_contacts(contact_t *head) {
    contact_t *current = head;

    if (current == NULL) {
        printf("No contacts found!\n");
        return;
    }

    while (current != NULL) {
        printf("%s: %s\n", current->name, current->phone_number);
        current = current->next;
    }
}