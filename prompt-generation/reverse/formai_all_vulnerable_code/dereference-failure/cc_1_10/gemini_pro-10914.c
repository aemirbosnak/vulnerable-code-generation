//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char *name;
    char *email;
    char *phone;
    char *address;
} Contact;

typedef struct {
    int num_contacts;
    Contact *contacts;
} Database;

Database *create_database() {
    Database *db = malloc(sizeof(Database));
    db->num_contacts = 0;
    db->contacts = NULL;
    return db;
}

void add_contact(Database *db, Contact *contact) {
    db->num_contacts++;
    db->contacts = realloc(db->contacts, sizeof(Contact) * db->num_contacts);
    db->contacts[db->num_contacts - 1] = *contact;
}

Contact *get_contact(Database *db, int index) {
    if (index < 0 || index >= db->num_contacts) {
        return NULL;
    }
    return &db->contacts[index];
}

void delete_contact(Database *db, int index) {
    if (index < 0 || index >= db->num_contacts) {
        return;
    }
    for (int i = index; i < db->num_contacts - 1; i++) {
        db->contacts[i] = db->contacts[i + 1];
    }
    db->num_contacts--;
    db->contacts = realloc(db->contacts, sizeof(Contact) * db->num_contacts);
}

void print_database(Database *db) {
    printf("Database contains %d contacts:\n", db->num_contacts);
    for (int i = 0; i < db->num_contacts; i++) {
        Contact *contact = get_contact(db, i);
        printf("  - %s (%s, %s, %s)\n", contact->name, contact->email, contact->phone, contact->address);
    }
}

void destroy_database(Database *db) {
    for (int i = 0; i < db->num_contacts; i++) {
        free(db->contacts[i].name);
        free(db->contacts[i].email);
        free(db->contacts[i].phone);
        free(db->contacts[i].address);
    }
    free(db->contacts);
    free(db);
}

int main() {
    Database *db = create_database();

    Contact contact1 = {"John Doe", "john.doe@example.com", "0123456789", "123 Main Street"};
    add_contact(db, &contact1);

    Contact contact2 = {"Jane Doe", "jane.doe@example.com", "9876543210", "456 Elm Street"};
    add_contact(db, &contact2);

    print_database(db);

    Contact *contact3 = get_contact(db, 1);
    printf("Contact at index 1: %s (%s, %s, %s)\n", contact3->name, contact3->email, contact3->phone, contact3->address);

    delete_contact(db, 0);

    print_database(db);

    destroy_database(db);

    return 0;
}