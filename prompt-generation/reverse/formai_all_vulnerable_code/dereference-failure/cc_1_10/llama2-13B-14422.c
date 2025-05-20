//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a contact
struct contact {
    char *name;
    char *phone;
    char *email;
};

// Define a function to create a new contact
struct contact new_contact(char *name, char *phone, char *email) {
    struct contact c;
    c.name = name;
    c.phone = phone;
    c.email = email;
    return c;
}

// Define a function to print all contacts
void print_contacts(struct contact *contacts) {
    int i;
    for (i = 0; i < sizeof(contacts) / sizeof(contacts[0]); i++) {
        printf("Name: %s\nPhone: %s\nEmail: %s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}

// Define a function to add a contact
void add_contact(struct contact *contacts, struct contact new_contact) {
    int i;
    for (i = 0; i < sizeof(contacts) / sizeof(contacts[0]); i++) {
        if (strcmp(contacts[i].name, new_contact.name) == 0) {
            // Contact already exists, update the phone and email
            contacts[i].phone = new_contact.phone;
            contacts[i].email = new_contact.email;
            break;
        }
    }
    if (i == sizeof(contacts) / sizeof(contacts[0])) {
        // Contact does not exist, add it to the end
        contacts[i] = new_contact;
    }
}

int main() {
    struct contact *contacts = malloc(sizeof(struct contact) * 10);
    struct contact new_contact1 = new_contact("John", "555-1234", "john@example.com");
    struct contact new_contact2 = new_contact("Jane", "555-5678", "jane@example.com");
    struct contact new_contact3 = new_contact("Bob", "555-9012", "bob@example.com");

    // Add the contacts to the list
    add_contact(contacts, new_contact1);
    add_contact(contacts, new_contact2);
    add_contact(contacts, new_contact3);

    // Print all the contacts
    print_contacts(contacts);

    // Free the memory
    free(contacts);

    return 0;
}