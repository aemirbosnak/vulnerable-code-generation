//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a contact in the phone book
typedef struct contact {
    char name[50];
    char phone_number[20];
} contact;

// Define the structure of the phone book
typedef struct phone_book {
    int num_contacts;
    contact *contacts;
} phone_book;

// Create a new phone book
phone_book* create_phone_book() {
    phone_book *pb = (phone_book*)malloc(sizeof(phone_book));
    pb->num_contacts = 0;
    pb->contacts = NULL;
    return pb;
}

// Add a new contact to the phone book
void add_contact(phone_book *pb, contact *c) {
    pb->num_contacts++;
    pb->contacts = (contact*)realloc(pb->contacts, pb->num_contacts * sizeof(contact));
    pb->contacts[pb->num_contacts - 1] = *c;
}

// Find a contact in the phone book by name
contact* find_contact_by_name(phone_book *pb, char *name) {
    for (int i = 0; i < pb->num_contacts; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            return &pb->contacts[i];
        }
    }
    return NULL;
}

// Find a contact in the phone book by phone number
contact* find_contact_by_phone_number(phone_book *pb, char *phone_number) {
    for (int i = 0; i < pb->num_contacts; i++) {
        if (strcmp(pb->contacts[i].phone_number, phone_number) == 0) {
            return &pb->contacts[i];
        }
    }
    return NULL;
}

// Delete a contact from the phone book by name
void delete_contact_by_name(phone_book *pb, char *name) {
    int index = -1;
    for (int i = 0; i < pb->num_contacts; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < pb->num_contacts - 1; i++) {
            pb->contacts[i] = pb->contacts[i + 1];
        }
        pb->num_contacts--;
        pb->contacts = (contact*)realloc(pb->contacts, pb->num_contacts * sizeof(contact));
    }
}

// Delete a contact from the phone book by phone number
void delete_contact_by_phone_number(phone_book *pb, char *phone_number) {
    int index = -1;
    for (int i = 0; i < pb->num_contacts; i++) {
        if (strcmp(pb->contacts[i].phone_number, phone_number) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < pb->num_contacts - 1; i++) {
            pb->contacts[i] = pb->contacts[i + 1];
        }
        pb->num_contacts--;
        pb->contacts = (contact*)realloc(pb->contacts, pb->num_contacts * sizeof(contact));
    }
}

// Print the phone book
void print_phone_book(phone_book *pb) {
    for (int i = 0; i < pb->num_contacts; i++) {
        printf("%s %s\n", pb->contacts[i].name, pb->contacts[i].phone_number);
    }
}

// Free the memory allocated for the phone book
void free_phone_book(phone_book *pb) {
    free(pb->contacts);
    free(pb);
}

int main() {
    // Create a new phone book
    phone_book *pb = create_phone_book();

    // Add some contacts to the phone book
    contact c1 = {"John Doe", "555-1212"};
    add_contact(pb, &c1);
    contact c2 = {"Jane Doe", "555-1213"};
    add_contact(pb, &c2);
    contact c3 = {"Bob Smith", "555-1214"};
    add_contact(pb, &c3);

    // Print the phone book
    print_phone_book(pb);

    // Find a contact in the phone book by name
    contact *c = find_contact_by_name(pb, "John Doe");
    if (c != NULL) {
        printf("Found contact: %s %s\n", c->name, c->phone_number);
    } else {
        printf("Contact not found.\n");
    }

    // Find a contact in the phone book by phone number
    c = find_contact_by_phone_number(pb, "555-1213");
    if (c != NULL) {
        printf("Found contact: %s %s\n", c->name, c->phone_number);
    } else {
        printf("Contact not found.\n");
    }

    // Delete a contact from the phone book by name
    delete_contact_by_name(pb, "Bob Smith");

    // Print the phone book
    print_phone_book(pb);

    // Free the memory allocated for the phone book
    free_phone_book(pb);

    return 0;
}