//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char *name;
    char *email;
    char *phone;
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

void destroy_database(Database *db) {
    for (int i = 0; i < db->num_contacts; i++) {
        free(db->contacts[i].name);
        free(db->contacts[i].email);
        free(db->contacts[i].phone);
    }
    free(db->contacts);
    free(db);
}

Contact *create_contact(int id, char *name, char *email, char *phone) {
    Contact *contact = malloc(sizeof(Contact));
    contact->id = id;
    contact->name = strdup(name);
    contact->email = strdup(email);
    contact->phone = strdup(phone);
    return contact;
}

void destroy_contact(Contact *contact) {
    free(contact->name);
    free(contact->email);
    free(contact->phone);
    free(contact);
}

void add_contact(Database *db, Contact *contact) {
    db->contacts = realloc(db->contacts, (db->num_contacts + 1) * sizeof(Contact));
    db->contacts[db->num_contacts++] = *contact;
}

Contact *get_contact_by_id(Database *db, int id) {
    for (int i = 0; i < db->num_contacts; i++) {
        if (db->contacts[i].id == id) {
            return &db->contacts[i];
        }
    }
    return NULL;
}

void print_database(Database *db) {
    printf("Database:\n");
    for (int i = 0; i < db->num_contacts; i++) {
        printf("Contact %d:\n", db->contacts[i].id);
        printf("Name: %s\n", db->contacts[i].name);
        printf("Email: %s\n", db->contacts[i].email);
        printf("Phone: %s\n", db->contacts[i].phone);
        printf("\n");
    }
}

int main() {
    Database *db = create_database();

    Contact *contact1 = create_contact(1, "John Doe", "john.doe@example.com", "123-456-7890");
    add_contact(db, contact1);

    Contact *contact2 = create_contact(2, "Jane Doe", "jane.doe@example.com", "123-456-7891");
    add_contact(db, contact2);

    print_database(db);

    Contact *contact3 = get_contact_by_id(db, 3);
    if (contact3 != NULL) {
        printf("Contact 3:\n");
        printf("Name: %s\n", contact3->name);
        printf("Email: %s\n", contact3->email);
        printf("Phone: %s\n", contact3->phone);
        printf("\n");
    } else {
        printf("Contact 3 not found.\n");
    }

    destroy_contact(contact1);
    destroy_contact(contact2);
    destroy_database(db);

    return 0;
}