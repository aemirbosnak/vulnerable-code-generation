//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void add_contact(Database *db, Contact *contact) {
  db->num_contacts++;
  db->contacts = realloc(db->contacts, sizeof(Contact) * db->num_contacts);
  db->contacts[db->num_contacts - 1] = *contact;
}

void print_database(Database *db) {
  for (int i = 0; i < db->num_contacts; i++) {
    Contact contact = db->contacts[i];
    printf("ID: %d\n", contact.id);
    printf("Name: %s\n", contact.name);
    printf("Email: %s\n", contact.email);
    printf("Phone: %s\n\n", contact.phone);
  }
}

int main() {
  Database *db = create_database();

  Contact contact1 = {1, "John Doe", "john.doe@example.com", "123-456-7890"};
  Contact contact2 = {2, "Jane Doe", "jane.doe@example.com", "123-456-7891"};
  Contact contact3 = {3, "John Smith", "john.smith@example.com", "123-456-7892"};

  add_contact(db, &contact1);
  add_contact(db, &contact2);
  add_contact(db, &contact3);

  print_database(db);

  return 0;
}