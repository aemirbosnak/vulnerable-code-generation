//FormAI DATASET v1.0 Category: Phone Book ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the contact struct */
typedef struct Contact {
    char name[50];
    char phone_number[20];
    struct Contact *next;
} Contact;

/* Function prototypes */
void add_contact();
void view_contacts();
void search_contact();
void delete_contact();

/* Declare our linked list */
Contact *head = NULL;

/* The main function */
int main() {
    int option;

    while (1) {
        printf("\nWelcome to the Visionary Phone Book!\n\n");
        printf("Choose an option:\n");
        printf("1. Add a contact\n");
        printf("2. View contacts\n");
        printf("3. Search for a contact\n");
        printf("4. Delete a contact\n");
        printf("5. Exit\n\n");
        printf("Option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_contact();
                break;
            case 2:
                view_contacts();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                delete_contact();
                break;
            case 5:
                printf("\nThanks for using the Visionary Phone Book!\n");
                exit(0);
            default:
                printf("\nInvalid option. Please try again.\n");
        }
    }
}

/* Adds a new contact to our linked list */
void add_contact() {
    Contact *new_contact = malloc(sizeof(Contact));

    printf("\nEnter contact name: ");
    scanf("%s", new_contact->name);
    printf("Enter phone number: ");
    scanf("%s", new_contact->phone_number);
    new_contact->next = head;
    head = new_contact;

    printf("\nContact added!\n");
}

/* Prints out all the contacts in our linked list */
void view_contacts() {
    Contact *current_contact;

    if (head == NULL) {
        printf("\nNo contacts found.\n");
        return;
    }

    printf("\nContacts:\n\n");
    current_contact = head;
    while (current_contact != NULL) {
        printf("%s\t\t%s\n", current_contact->name, current_contact->phone_number);
        current_contact = current_contact->next;
    }
}

/* Searches for a contact in our linked list */
void search_contact() {
    Contact *current_contact;
    char search_name[50];
    int found = 0;

    if (head == NULL) {
        printf("\nNo contacts found.\n");
        return;
    }

    printf("\nEnter name to search: ");
    scanf("%s", search_name);

    current_contact = head;
    while (current_contact != NULL) {
        if (strcmp(current_contact->name, search_name) == 0) {
            printf("\n%s\t\t%s\n", current_contact->name, current_contact->phone_number);
            found = 1;
            break;
        }
        current_contact = current_contact->next;
    }

    if (!found) {
        printf("\nContact not found.\n");
    }
}

/* Deletes a contact from our linked list */
void delete_contact() {
    Contact *current_contact, *previous_contact;
    char delete_name[50];
    int found = 0;

    if (head == NULL) {
        printf("\nNo contacts found.\n");
        return;
    }

    printf("\nEnter name to delete: ");
    scanf("%s", delete_name);

    current_contact = head;
    while (current_contact != NULL) {
        if (strcmp(current_contact->name, delete_name) == 0) {
            if (current_contact == head) {
                /* Contact to delete is the head of the list */
                head = current_contact->next;
            } else {
                previous_contact->next = current_contact->next;
            }
            free(current_contact);
            printf("\nContact deleted!\n");
            found = 1;
            break;
        }
        previous_contact = current_contact;
        current_contact = current_contact->next;
    }

    if (!found) {
        printf("\nContact not found.\n");
    }
}