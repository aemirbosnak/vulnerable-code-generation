//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a contact
struct contact {
    char name[50];
    char phone_number[20];
    char email[50];
};

// Function to compare two contacts by name
int compare_contacts(const void *a, const void *b) {
    const struct contact *contact1 = (const struct contact *)a;
    const struct contact *contact2 = (const struct contact *)b;
    return strcmp(contact1->name, contact2->name);
}

// Function to print a contact
void print_contact(const struct contact *contact) {
    printf("%s: %s (%s)\n", contact->name, contact->phone_number, contact->email);
}

// Function to add a contact
void add_contact(struct contact **contacts, int *num_contacts) {
    // Allocate memory for the new contact
    struct contact *new_contact = (struct contact *)malloc(sizeof(struct contact));

    // Get the contact information from the user
    printf("Enter name: ");
    scanf("%s", new_contact->name);

    printf("Enter phone number: ");
    scanf("%s", new_contact->phone_number);

    printf("Enter email: ");
    scanf("%s", new_contact->email);

    // Add the new contact to the array
    contacts[*num_contacts] = new_contact;
    (*num_contacts)++;
}

// Function to delete a contact
void delete_contact(struct contact **contacts, int *num_contacts) {
    // Get the name of the contact to delete
    char name[50];
    printf("Enter name: ");
    scanf("%s", name);

    // Find the contact in the array
    int i;
    for (i = 0; i < *num_contacts; i++) {
        if (strcmp(contacts[i]->name, name) == 0) {
            break;
        }
    }

    // If the contact was not found, print an error message
    if (i == *num_contacts) {
        printf("Contact not found.\n");
        return;
    }

    // Delete the contact from the array
    free(contacts[i]);
    for (int j = i; j < *num_contacts - 1; j++) {
        contacts[j] = contacts[j + 1];
    }
    (*num_contacts)--;
}

// Function to search for a contact
void search_contact(struct contact **contacts, int num_contacts) {
    // Get the name of the contact to search for
    char name[50];
    printf("Enter name: ");
    scanf("%s", name);

    // Find the contact in the array
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i]->name, name) == 0) {
            break;
        }
    }

    // If the contact was not found, print an error message
    if (i == num_contacts) {
        printf("Contact not found.\n");
        return;
    }

    // Print the contact information
    print_contact(contacts[i]);
}

// Main function
int main() {
    // Allocate memory for the array of contacts
    struct contact **contacts = (struct contact **)malloc(sizeof(struct contact *) * 100);

    // Initialize the number of contacts to 0
    int num_contacts = 0;

    // Get the user's choice
    int choice;
    do {
        printf("\n1. Add contact\n2. Delete contact\n3. Search for contact\n4. Print all contacts\n5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact(contacts, &num_contacts);
                break;
            case 2:
                delete_contact(contacts, &num_contacts);
                break;
            case 3:
                search_contact(contacts, num_contacts);
                break;
            case 4:
                qsort(contacts, num_contacts, sizeof(struct contact *), compare_contacts);
                for (int i = 0; i < num_contacts; i++) {
                    print_contact(contacts[i]);
                }
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    // Free the memory allocated for the array of contacts
    for (int i = 0; i < num_contacts; i++) {
        free(contacts[i]);
    }
    free(contacts);

    return 0;
}