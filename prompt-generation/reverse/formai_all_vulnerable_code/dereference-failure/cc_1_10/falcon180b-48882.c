//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100
#define MAX_SUBJECT_LEN 100
#define MAX_MESSAGE_LEN 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

typedef struct {
    contact *contacts;
    int num_contacts;
} mailing_list;

void initialize_mailing_list(mailing_list *ml) {
    ml->contacts = NULL;
    ml->num_contacts = 0;
}

void add_contact(mailing_list *ml, char *name, char *email) {
    contact *new_contact = malloc(sizeof(contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->email, email);
    ml->contacts = realloc(ml->contacts, sizeof(contact) * (ml->num_contacts + 1));
    ml->contacts[ml->num_contacts++] = *new_contact;
    free(new_contact);
}

void remove_contact(mailing_list *ml, int index) {
    if (index >= 0 && index < ml->num_contacts) {
        contact *contact_to_remove = ml->contacts + index;
        for (int i = index; i < ml->num_contacts - 1; i++) {
            ml->contacts[i] = ml->contacts[i + 1];
        }
        ml->num_contacts--;
    }
}

void send_message(mailing_list *ml, char *subject, char *message) {
    for (int i = 0; i < ml->num_contacts; i++) {
        printf("Sending message to %s (%s)\n", ml->contacts[i].name, ml->contacts[i].email);
    }
}

int main() {
    mailing_list ml;
    initialize_mailing_list(&ml);

    add_contact(&ml, "John Doe", "john.doe@example.com");
    add_contact(&ml, "Jane Doe", "jane.doe@example.com");

    send_message(&ml, "Test Message", "This is a test message sent to the mailing list.");

    remove_contact(&ml, 0);

    send_message(&ml, "Another Test Message", "This is another test message sent to the updated mailing list.");

    return 0;
}