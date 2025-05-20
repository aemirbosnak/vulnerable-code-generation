//FormAI DATASET v1.0 Category: Mailing list manager ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold information about the contacts
typedef struct contact {
    char name[50];
    char email[50];
    struct contact* next;
} Contact;

// Function to add a new contact to the list
void add_contact(Contact** head) {
    Contact* new_contact = malloc(sizeof(Contact));
    printf("\nEnter the name of the contact: ");
    scanf("%s", new_contact->name);
    printf("Enter the email of the contact: ");
    scanf("%s", new_contact->email);
    new_contact->next = NULL;

    if (*head == NULL) {
        *head = new_contact;
    } else {
        Contact* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_contact;
    }
    printf("\nContact added successfully!\n");
}

// Function to remove a contact from the list
void remove_contact(Contact** head, char* email) {
    if (*head == NULL) {
        printf("\nThere are no contacts to remove!\n");
    } else {
        Contact* current = *head;
        Contact* previous = NULL;

        while (current != NULL && strcmp(current->email, email) != 0) {
            previous = current;
            current = current->next;
        }

        if (current == NULL) {
            printf("\nContact not found!\n");
        } else if (previous == NULL) {
            *head = current->next;
            free(current);
            printf("\nContact removed successfully!\n");
        } else {
            previous->next = current->next;
            free(current);
            printf("\nContact removed successfully!\n");
        }
    }
}

int main() {
    Contact* head = NULL;
    int choice;
    char email[50];

    printf("Welcome to the Mailing List Manager!\n\n");

    while (1) {
        printf("\n1. Add a contact\n2. Remove a contact\n3. Quit\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact(&head);
                break;
            case 2:
                printf("\nEnter the email of the contact to remove: ");
                scanf("%s", email);
                remove_contact(&head, email);
                break;
            case 3:
                printf("\nThank you for using the Mailing List Manager!\n");
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }
    return 0;
}