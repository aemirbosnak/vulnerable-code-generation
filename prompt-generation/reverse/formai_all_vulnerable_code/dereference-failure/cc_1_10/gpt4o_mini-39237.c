//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a contact
typedef struct Contact {
    char name[50];
    char phone[15];
    struct Contact *next;
} Contact;

// Function prototypes
Contact* create_contact(const char* name, const char* phone);
void add_contact(Contact** head);
void delete_contact(Contact** head);
void search_contact(Contact* head);
void display_contacts(Contact* head);
void free_contacts(Contact* head);

int main() {
    Contact* head = NULL;
    int choice;

    do {
        printf("\n=== Phone Book ===\n");
        printf("1. Add contact\n");
        printf("2. Delete contact\n");
        printf("3. Search contact\n");
        printf("4. Display all contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline character

        switch (choice) {
            case 1:
                add_contact(&head);
                break;
            case 2:
                delete_contact(&head);
                break;
            case 3:
                search_contact(head);
                break;
            case 4:
                display_contacts(head);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    free_contacts(head);
    return 0;
}

// Create a new contact
Contact* create_contact(const char* name, const char* phone) {
    Contact* new_contact = (Contact*)malloc(sizeof(Contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->phone, phone);
    new_contact->next = NULL;
    return new_contact;
}

// Add a contact to the phonebook
void add_contact(Contact** head) {
    char name[50], phone[15];
    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove newline character
    printf("Enter phone: ");
    fgets(phone, sizeof(phone), stdin);
    phone[strcspn(phone, "\n")] = '\0';  // Remove newline character

    Contact* new_contact = create_contact(name, phone);
    new_contact->next = *head; // Insert at the beginning
    *head = new_contact;
    printf("Contact added successfully!\n");
}

// Delete a contact from the phonebook
void delete_contact(Contact** head) {
    char name[50];
    printf("Enter name of the contact to delete: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove newline character

    Contact* current = *head;
    Contact* previous = NULL;

    while (current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Contact not found!\n");
        return;
    }

    if (previous == NULL) {
        *head = current->next; // Delete the head
    } else {
        previous->next = current->next; // Bypass the current node
    }
    free(current);
    printf("Contact deleted successfully!\n");
}

// Search for a contact in the phonebook
void search_contact(Contact* head) {
    char name[50];
    printf("Enter name of the contact to search: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove newline character

    Contact* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Found contact: %s - %s\n", current->name, current->phone);
            return;
        }
        current = current->next;
    }
    printf("Contact not found!\n");
}

// Display all contacts in the phonebook
void display_contacts(Contact* head) {
    if (head == NULL) {
        printf("Phonebook is empty!\n");
        return;
    }

    printf("Contact List:\n");
    Contact* current = head;
    while (current != NULL) {
        printf("%s - %s\n", current->name, current->phone);
        current = current->next;
    }
}

// Free all contacts from memory
void free_contacts(Contact* head) {
    Contact* current = head;
    Contact* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}