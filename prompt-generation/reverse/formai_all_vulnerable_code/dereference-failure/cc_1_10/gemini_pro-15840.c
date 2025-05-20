//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *email;
    char *phone;
} Contact;

typedef struct {
    Contact *contacts;
    int num_contacts;
    int capacity;
} Database;

Database *create_database() {
    Database *db = malloc(sizeof(Database));
    db->contacts = NULL;
    db->num_contacts = 0;
    db->capacity = 0;
    return db;
}

void destroy_database(Database *db) {
    for (int i = 0; i < db->num_contacts; i++) {
        free(db->contacts[i].name);
        free(db->contacts[i].email);
        free(db->contacts[i].phone);
    }
    free(db->contacts);
    free(db);
}

void add_contact(Database *db, char *name, char *email, char *phone) {
    if (db->num_contacts == db->capacity) {
        db->capacity *= 2;
        db->contacts = realloc(db->contacts, db->capacity * sizeof(Contact));
    }

    db->contacts[db->num_contacts].name = strdup(name);
    db->contacts[db->num_contacts].email = strdup(email);
    db->contacts[db->num_contacts].phone = strdup(phone);
    db->num_contacts++;
}

Contact *find_contact(Database *db, char *name) {
    for (int i = 0; i < db->num_contacts; i++) {
        if (strcmp(db->contacts[i].name, name) == 0) {
            return &db->contacts[i];
        }
    }

    return NULL;
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_contacts; i++) {
        printf("%s (%s, %s)\n", db->contacts[i].name, db->contacts[i].email, db->contacts[i].phone);
    }
}

int main() {
    Database *db = create_database();

    add_contact(db, "John Doe", "john.doe@example.com", "555-123-4567");
    add_contact(db, "Jane Smith", "jane.smith@example.com", "555-234-5678");
    add_contact(db, "Bill Jones", "bill.jones@example.com", "555-345-6789");

    Contact *contact = find_contact(db, "John Doe");
    if (contact != NULL) {
        printf("Found contact: %s (%s, %s)\n", contact->name, contact->email, contact->phone);
    } else {
        printf("Contact not found.\n");
    }

    print_database(db);

    destroy_database(db);

    return 0;
}