//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char *name;
    char *email;
    char *phone;
} contact;

typedef struct {
    int num_contacts;
    contact *contacts;
} database;

database *create_database() {
    database *db = malloc(sizeof(database));
    db->num_contacts = 0;
    db->contacts = NULL;
    return db;
}

void destroy_database(database *db) {
    for (int i = 0; i < db->num_contacts; i++) {
        free(db->contacts[i].name);
        free(db->contacts[i].email);
        free(db->contacts[i].phone);
    }
    free(db->contacts);
    free(db);
}

contact *create_contact(int id, char *name, char *email, char *phone) {
    contact *c = malloc(sizeof(contact));
    c->id = id;
    c->name = strdup(name);
    c->email = strdup(email);
    c->phone = strdup(phone);
    return c;
}

void destroy_contact(contact *c) {
    free(c->name);
    free(c->email);
    free(c->phone);
    free(c);
}

void add_contact(database *db, contact *c) {
    db->contacts = realloc(db->contacts, (db->num_contacts + 1) * sizeof(contact));
    db->contacts[db->num_contacts++] = *c;
}

contact *get_contact_by_id(database *db, int id) {
    for (int i = 0; i < db->num_contacts; i++) {
        if (db->contacts[i].id == id) {
            return &db->contacts[i];
        }
    }
    return NULL;
}

void print_contact(contact *c) {
    printf("ID: %d\n", c->id);
    printf("Name: %s\n", c->name);
    printf("Email: %s\n", c->email);
    printf("Phone: %s\n", c->phone);
}

int main() {
    // Create a database
    database *db = create_database();

    // Add some contacts to the database
    add_contact(db, create_contact(1, "John Doe", "john.doe@example.com", "555-123-4567"));
    add_contact(db, create_contact(2, "Jane Doe", "jane.doe@example.com", "555-234-5678"));
    add_contact(db, create_contact(3, "John Smith", "john.smith@example.com", "555-345-6789"));

    // Get a contact by ID
    contact *c = get_contact_by_id(db, 2);

    // Print the contact
    print_contact(c);

    // Destroy the contact
    destroy_contact(c);

    // Destroy the database
    destroy_database(db);

    return 0;
}