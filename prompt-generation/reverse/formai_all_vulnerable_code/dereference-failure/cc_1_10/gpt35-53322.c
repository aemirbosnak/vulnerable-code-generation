//FormAI DATASET v1.0 Category: Phone Book ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contact {
    char name[50];
    char phoneNumber[20];
    struct contact *next;
} contact;

void addContact(contact **head_ref) {
    char name[50];
    char phoneNumber[20];
    printf("\nEnter name: ");
    scanf("%s", name);
    printf("Enter phone number: ");
    scanf("%s", phoneNumber);
    
    // Create new contact
    contact *new_contact = (contact*) malloc(sizeof(contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->phoneNumber, phoneNumber);
    new_contact->next = NULL;
    
    // Add contact to list
    if (*head_ref == NULL) {
        *head_ref = new_contact;
        printf("\nContact added!\n");
    } else {
        contact *last_contact = *head_ref;
        while (last_contact->next != NULL) {
            last_contact = last_contact->next;
        }
        last_contact->next = new_contact;
        printf("\nContact added!\n");
    }
}

void searchContact(contact *head) {
    char name[50];
    printf("\nEnter name to search: ");
    scanf("%s", name);
    
    contact *current_contact = head;
    while (current_contact != NULL) {
        if (strcmp(current_contact->name, name) == 0) {
            printf("\nName: %s\nPhone Number: %s\n", current_contact->name, current_contact->phoneNumber);
            return;
        }
        current_contact = current_contact->next;
    }
    printf("\nContact not found\n");
}

void displayContacts(contact *head) {
    if (head == NULL) {
        printf("\nNo contacts found\n");
        return;
    }
    contact *current_contact = head;
    while (current_contact != NULL) {
        printf("\nName: %s\nPhone Number: %s\n", current_contact->name, current_contact->phoneNumber);
        current_contact = current_contact->next;
    }
}

int main() {
    int choice;
    contact *head = NULL;

    do {
        printf("\n\nPhone Book\n");
        printf("-----------\n");
        printf("1. Add Contact\n2. Search Contact\n3. Display Contacts\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(&head);
                break;
            case 2:
                searchContact(head);
                break;
            case 3:
                displayContacts(head);
                break;
            case 4:
                printf("\nExiting Phone Book. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice\n");
                break;
        }
    } while (choice != 4);

    return 0;
}