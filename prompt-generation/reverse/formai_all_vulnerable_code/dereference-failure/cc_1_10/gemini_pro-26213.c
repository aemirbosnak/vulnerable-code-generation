//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct _contact {
    char *name;
    char *phone;
} contact;

contact *contacts[MAX_CONTACTS];
int num_contacts = 0;

void add_contact(char *name, char *phone) {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Error: Phone book is full!\n");
        return;
    }

    contacts[num_contacts] = malloc(sizeof(contact));
    contacts[num_contacts]->name = strdup(name);
    contacts[num_contacts]->phone = strdup(phone);
    num_contacts++;
}

void print_contacts() {
    for (int i = 0; i < num_contacts; i++) {
        printf("%s: %s\n", contacts[i]->name, contacts[i]->phone);
    }
}

void search_contacts(char *name) {
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i]->name, name) == 0) {
            printf("Found contact: %s (%s)\n", contacts[i]->name, contacts[i]->phone);
            return;
        }
    }

    printf("Contact not found!\n");
}

void delete_contact(char *name) {
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i]->name, name) == 0) {
            free(contacts[i]->name);
            free(contacts[i]->phone);
            free(contacts[i]);
            for (int j = i; j < num_contacts - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            num_contacts--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }

    printf("Contact not found!\n");
}

int main() {
    // Initialize the phone book with some sample contacts
    add_contact("John Doe", "555-123-4567");
    add_contact("Jane Smith", "555-234-5678");
    add_contact("Bob Jones", "555-345-6789");
    add_contact("Alice Cooper", "555-456-7890");
    add_contact("Ted Nugent", "555-567-8901");

    // Print the phone book
    printf("Phone Book:\n");
    print_contacts();

    // Search for a contact
    char *name = "Jane Smith";
    search_contacts(name);

    // Delete a contact
    name = "Bob Jones";
    delete_contact(name);

    // Print the phone book again
    printf("Updated Phone Book:\n");
    print_contacts();

    // Free the memory allocated for the contacts
    for (int i = 0; i < num_contacts; i++) {
        free(contacts[i]->name);
        free(contacts[i]->phone);
        free(contacts[i]);
    }

    return 0;
}