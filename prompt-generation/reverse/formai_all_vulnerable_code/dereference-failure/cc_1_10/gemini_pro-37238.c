//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[256];
    char phone_number[256];
} Contact;

Contact *contacts; // Array of contacts
int num_contacts; // Number of contacts in the array

void add_contact(char *name, char *phone_number) {
    // Realloc the contacts array to make space for a new contact
    contacts = realloc(contacts, (num_contacts + 1) * sizeof(Contact));

    // Add the new contact to the array
    strcpy(contacts[num_contacts].name, name);
    strcpy(contacts[num_contacts].phone_number, phone_number);

    // Increment the number of contacts
    num_contacts++;
}

void print_contacts() {
    for (int i = 0; i < num_contacts; i++) {
        printf("%s: %s\n", contacts[i].name, contacts[i].phone_number);
    }
}

void search_contacts(char *name) {
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Found contact: %s: %s\n", contacts[i].name, contacts[i].phone_number);
            return;
        }
    }

    printf("Contact not found.\n");
}

int main() {
    // Initialize the contacts array
    contacts = malloc(0);
    num_contacts = 0;

    // Add some contacts to the array
    add_contact("John Doe", "123-456-7890");
    add_contact("Jane Doe", "123-456-7891");
    add_contact("John Smith", "123-456-7892");

    // Print the contacts
    print_contacts();

    // Search for a contact
    search_contacts("John Smith");

    // Free the contacts array
    free(contacts);

    return 0;
}