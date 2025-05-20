//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    char email[50];
    char phone[20];
} Contact;

typedef struct {
    int num_contacts;
    Contact contacts[100];
} Database;

// Create a new database
Database *create_database() {
    Database *db = malloc(sizeof(Database));
    db->num_contacts = 0;
    return db;
}

// Add a new contact to the database
void add_contact(Database *db, Contact contact) {
    db->contacts[db->num_contacts] = contact;
    db->num_contacts++;
}

// Search for a contact by name
Contact *search_contact_by_name(Database *db, char *name) {
    for (int i = 0; i < db->num_contacts; i++) {
        if (strcmp(db->contacts[i].name, name) == 0) {
            return &db->contacts[i];
        }
    }
    return NULL;
}

// Search for a contact by email
Contact *search_contact_by_email(Database *db, char *email) {
    for (int i = 0; i < db->num_contacts; i++) {
        if (strcmp(db->contacts[i].email, email) == 0) {
            return &db->contacts[i];
        }
    }
    return NULL;
}

// Search for a contact by phone
Contact *search_contact_by_phone(Database *db, char *phone) {
    for (int i = 0; i < db->num_contacts; i++) {
        if (strcmp(db->contacts[i].phone, phone) == 0) {
            return &db->contacts[i];
        }
    }
    return NULL;
}

// Print all contacts in the database
void print_contacts(Database *db) {
    for (int i = 0; i < db->num_contacts; i++) {
        printf("ID: %d\n", db->contacts[i].id);
        printf("Name: %s\n", db->contacts[i].name);
        printf("Email: %s\n", db->contacts[i].email);
        printf("Phone: %s\n\n", db->contacts[i].phone);
    }
}

// Free the memory allocated for the database
void free_database(Database *db) {
    free(db);
}

int main() {
    // Create a new database
    Database *db = create_database();

    // Add some contacts to the database
    Contact contact1 = {1, "John Doe", "john.doe@example.com", "555-1212"};
    Contact contact2 = {2, "Jane Doe", "jane.doe@example.com", "555-1213"};
    Contact contact3 = {3, "John Smith", "john.smith@example.com", "555-1214"};
    add_contact(db, contact1);
    add_contact(db, contact2);
    add_contact(db, contact3);

    // Search for a contact by name
    Contact *contact = search_contact_by_name(db, "John Doe");
    if (contact != NULL) {
        printf("Found contact:\n");
        printf("ID: %d\n", contact->id);
        printf("Name: %s\n", contact->name);
        printf("Email: %s\n", contact->email);
        printf("Phone: %s\n", contact->phone);
    } else {
        printf("Contact not found.\n");
    }

    // Search for a contact by email
    contact = search_contact_by_email(db, "john.doe@example.com");
    if (contact != NULL) {
        printf("Found contact:\n");
        printf("ID: %d\n", contact->id);
        printf("Name: %s\n", contact->name);
        printf("Email: %s\n", contact->email);
        printf("Phone: %s\n", contact->phone);
    } else {
        printf("Contact not found.\n");
    }

    // Search for a contact by phone
    contact = search_contact_by_phone(db, "555-1212");
    if (contact != NULL) {
        printf("Found contact:\n");
        printf("ID: %d\n", contact->id);
        printf("Name: %s\n", contact->name);
        printf("Email: %s\n", contact->email);
        printf("Phone: %s\n", contact->phone);
    } else {
        printf("Contact not found.\n");
    }

    // Print all contacts in the database
    printf("All contacts:\n");
    print_contacts(db);

    // Free the memory allocated for the database
    free_database(db);

    return 0;
}