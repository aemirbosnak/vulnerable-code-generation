//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char name[50];
    char number[20];
};

struct phonebook {
    struct contact *contacts;
    int num_contacts;
};

// Create a new phonebook
struct phonebook *create_phonebook() {
    struct phonebook *pb = malloc(sizeof(struct phonebook));
    pb->contacts = NULL;
    pb->num_contacts = 0;
    return pb;
}

// Add a contact to a phonebook
void add_contact(struct phonebook *pb, char *name, char *number) {
    struct contact *new_contact = malloc(sizeof(struct contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->number, number);
    pb->contacts = realloc(pb->contacts, (pb->num_contacts + 1) * sizeof(struct contact));
    pb->contacts[pb->num_contacts++] = *new_contact;
    free(new_contact);
}

// Search for a contact in a phonebook
struct contact *find_contact(struct phonebook *pb, char *name) {
    for (int i = 0; i < pb->num_contacts; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            return &pb->contacts[i];
        }
    }
    return NULL;
}

// Delete a contact from a phonebook
void delete_contact(struct phonebook *pb, char *name) {
    struct contact *contact = find_contact(pb, name);
    if (contact != NULL) {
        for (int i = 0; i < pb->num_contacts; i++) {
            if (&pb->contacts[i] == contact) {
                pb->contacts[i] = pb->contacts[pb->num_contacts - 1];
                pb->num_contacts--;
                break;
            }
        }
    }
}

// Print a phonebook
void print_phonebook(struct phonebook *pb) {
    for (int i = 0; i < pb->num_contacts; i++) {
        printf("%s: %s\n", pb->contacts[i].name, pb->contacts[i].number);
    }
}

// Free a phonebook
void free_phonebook(struct phonebook *pb) {
    for (int i = 0; i < pb->num_contacts; i++) {
        free(&pb->contacts[i]);
    }
    free(pb->contacts);
    free(pb);
}

int main() {
    // Create a new phonebook
    struct phonebook *pb = create_phonebook();

    // Add some contacts to the phonebook
    add_contact(pb, "Alice", "555-1212");
    add_contact(pb, "Bob", "555-1213");
    add_contact(pb, "Carol", "555-1214");

    // Print the phonebook
    print_phonebook(pb);

    // Search for a contact in the phonebook
    struct contact *contact = find_contact(pb, "Bob");

    // If the contact was found, print their name and number
    if (contact != NULL) {
        printf("Found contact: %s (%s)\n", contact->name, contact->number);
    } else {
        printf("Contact not found.\n");
    }

    // Delete a contact from the phonebook
    delete_contact(pb, "Carol");

    // Print the phonebook again
    print_phonebook(pb);

    // Free the phonebook
    free_phonebook(pb);

    return 0;
}