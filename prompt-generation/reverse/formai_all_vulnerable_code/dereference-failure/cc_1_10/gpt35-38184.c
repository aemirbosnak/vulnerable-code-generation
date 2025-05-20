//FormAI DATASET v1.0 Category: Phone Book ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// phone book structure
typedef struct phonebook {
    char name[30];
    char number[15];
    struct phonebook *next;
} phonebook;

// function prototypes
void add_contact(phonebook **head);
void search_contact(phonebook *head);
void delete_contact(phonebook **head);

int main() {
    phonebook *head = NULL;
    int choice;

    while (1) {
        // print menu
        printf("\n\nPhone Book Menu\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Delete Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact(&head);
                break;
            case 2:
                search_contact(head);
                break;
            case 3:
                delete_contact(&head);
                break;
            case 4:
                // exit program
                printf("\nExiting phone book program...\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice. Please enter a valid choice.\n");
        }
    }
}

// function to add a contact to the phone book
void add_contact(phonebook **head) {
    phonebook *new_contact = (phonebook*) malloc(sizeof(phonebook));

    // get contact information from user
    printf("\nEnter contact name: ");
    scanf("%s", new_contact->name);
    printf("Enter contact phone number: ");
    scanf("%s", new_contact->number);

    // add contact to phone book
    new_contact->next = *head;
    *head = new_contact;

    printf("\nContact '%s' successfully added to phone book!\n", new_contact->name);
}

// function to search for a contact in the phone book
void search_contact(phonebook *head) {
    char name[30];
    int found = 0;

    printf("\nEnter name to search: ");
    scanf("%s", name);

    // search for contact in phone book
    while (head != NULL) {
        if (strcmp(head->name, name) == 0) {
            printf("\nName: %s\nPhone Number: %s\n", head->name, head->number);
            found = 1;
            break;
        }
        head = head->next;
    }

    if (!found) {
        printf("\nContact not found.\n");
    }
}

// function to delete a contact from the phone book
void delete_contact(phonebook **head) {
    char name[30];
    phonebook *temp = *head;
    phonebook *prev = NULL;
    int found = 0;

    printf("\nEnter name to delete: ");
    scanf("%s", name);

    // search for contact in phone book
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            found = 1;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    if (found) {
        // remove contact from phone book
        if (prev != NULL) {
            prev->next = temp->next;
        } else {
            *head = temp->next;
        }
        free(temp);
        printf("\nContact '%s' successfully deleted from phone book!\n", name);
    } else {
        printf("\nContact not found.\n");
    }
}