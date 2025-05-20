//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100
#define MAX_EMAIL 100
#define MAX_MESSAGE 1000

typedef struct {
    char name[MAX_NAME];
    char email[MAX_EMAIL];
} contact;

typedef struct {
    contact *contacts;
    int num_contacts;
} mailing_list;

void init_contact(contact *c) {
    strcpy(c->name, "");
    strcpy(c->email, "");
}

void init_mailing_list(mailing_list *ml) {
    ml->contacts = NULL;
    ml->num_contacts = 0;
}

void add_contact(mailing_list *ml, char *name, char *email) {
    contact *new_contact = malloc(sizeof(contact));
    init_contact(new_contact);
    strcpy(new_contact->name, name);
    strcpy(new_contact->email, email);
    ml->contacts = realloc(ml->contacts, sizeof(contact) * (ml->num_contacts + 1));
    ml->contacts[ml->num_contacts++] = *new_contact;
    free(new_contact);
}

void remove_contact(mailing_list *ml, int index) {
    if (index >= 0 && index < ml->num_contacts) {
        ml->num_contacts--;
        ml->contacts = realloc(ml->contacts, sizeof(contact) * ml->num_contacts);
    }
}

void send_message(mailing_list *ml, char *message) {
    for (int i = 0; i < ml->num_contacts; i++) {
        printf("Sending message to %s (%s)\n", ml->contacts[i].name, ml->contacts[i].email);
    }
}

int main() {
    mailing_list ml;
    init_mailing_list(&ml);

    add_contact(&ml, "John Doe", "john.doe@example.com");
    add_contact(&ml, "Jane Smith", "jane.smith@example.com");

    send_message(&ml, "Hello, world!");

    remove_contact(&ml, 0);

    send_message(&ml, "Goodbye, world!");

    return 0;
}