//FormAI DATASET v1.0 Category: Phone Book ; Style: Claude Shannon
/*
Claude Shannon Style Phone Book Example Program

This program allows the user to add, search, delete and view contacts from a phone book.
Each contact includes a name, phone number, and email address.
The program stores the contacts in a linked list.

Author: Your Name
Date: Current Date

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Phone book contact struct
struct Contact {
    char name[30];
    char phone[15];
    char email[50];
    struct Contact *next;
};

// Function prototypes
void addContact();
void searchContact();
void deleteContact();
void viewContacts();

// Global variables
struct Contact *head = NULL;

int main() {
    int choice;
    do {
        // Print menu
        printf("\n--- Phone Book Menu ---\n");
        printf("1. Add a contact\n");
        printf("2. Search for a contact\n");
        printf("3. Delete a contact\n");
        printf("4. View contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handle menu choice
        switch(choice) {
            case 1:
                addContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                deleteContact();
                break;
            case 4:
                viewContacts();
                break;
            case 5:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice, please try again.\n");
        }

    } while (choice != 5);

    return 0;
}

void addContact() {
    // Allocate memory for new contact
    struct Contact *new_contact = (struct Contact*) malloc(sizeof(struct Contact));

    // Get contact details from user
    printf("\nEnter contact name: ");
    scanf("%s", new_contact->name);
    printf("Enter contact phone number: ");
    scanf("%s", new_contact->phone);
    printf("Enter contact email address: ");
    scanf("%s", new_contact->email);

    // Add new contact to head of linked list
    if (head == NULL) {
        new_contact->next = NULL;
        head = new_contact;
    } else {
        new_contact->next = head;
        head = new_contact;
    }

    printf("\nContact added successfully!\n");
}

void searchContact() {
    // Get search term from user
    char search_term[50];
    printf("\nEnter search term: ");
    scanf("%s", search_term);

    // Traverse linked list and print matching contacts
    struct Contact *current = head;
    int search_count = 0;
    while (current != NULL) {
        if (strstr(current->name, search_term) || strstr(current->phone, search_term) || strstr(current->email, search_term)) {
            printf("\nName: %s\nPhone: %s\nEmail: %s\n", current->name, current->phone, current->email);
            search_count++;
        }
        current = current->next;
    }

    // Print search results
    if (search_count == 0) {
        printf("\nNo contacts matching '%s' found.\n", search_term);
    } else {
        printf("\n%d contact(s) matching '%s' found.\n", search_count, search_term);
    }
}

void deleteContact() {
    // Get name of contact to delete from user
    char delete_name[30];
    printf("\nEnter name of contact to delete: ");
    scanf("%s", delete_name);

    // Traverse linked list and find contact to delete
    struct Contact *current = head;
    struct Contact *previous = NULL;
    int delete_count = 0;
    while (current != NULL) {
        if (strcmp(current->name, delete_name) == 0) {
            // Found contact to delete
            if (previous == NULL) {
                // Contact to delete is first in linked list
                head = current->next;
            } else {
                // Contact to delete is not first in linked list
                previous->next = current->next;
            }
            free(current);
            printf("\nContact '%s' deleted successfully!\n", delete_name);
            delete_count++;
            break;
        }
        previous = current;
        current = current->next;
    }

    // Print delete results
    if (delete_count == 0) {
        printf("\nContact '%s' not found.\n", delete_name);
    }
}

void viewContacts() {
    // Traverse linked list and print all contacts
    struct Contact *current = head;
    int view_count = 0;
    while (current != NULL) {
        printf("\nName: %s\nPhone: %s\nEmail: %s\n", current->name, current->phone, current->email);
        current = current->next;
        view_count++;
    }

    // Print view results
    if (view_count == 0) {
        printf("\nNo contacts found.\n");
    } else {
        printf("\n%d contacts found.\n", view_count);
    }
}