//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 64
#define MAX_EMAIL_LEN 256
#define MAX_SUBJECT_LEN 1024
#define MAX_MESSAGE_LEN 4096

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

typedef struct {
    contact *contacts;
    int num_contacts;
} mailing_list;

void add_contact(mailing_list *list, const char *name, const char *email) {
    contact *new_contact = malloc(sizeof(contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->email, email);
    list->contacts = realloc(list->contacts, sizeof(contact) * (list->num_contacts + 1));
    list->contacts[list->num_contacts] = *new_contact;
    list->num_contacts++;
}

void send_email(const char *to, const char *subject, const char *message) {
    printf("Sending email to %s with subject '%s' and message:\n%s\n", to, subject, message);
}

void send_emails_with_filter(mailing_list *list, const char *filter) {
    int i;
    for (i = 0; i < list->num_contacts; i++) {
        if (strcasestr(list->contacts[i].email, filter)) {
            send_email(list->contacts[i].email, "Hello from the mailing list!", "We hope this email finds you well.");
        }
    }
}

int main() {
    mailing_list list;
    list.contacts = NULL;
    list.num_contacts = 0;

    add_contact(&list, "Alice", "alice@example.com");
    add_contact(&list, "Bob", "bob@example.com");
    add_contact(&list, "Charlie", "charlie@example.com");

    send_emails_with_filter(&list, "example.com");

    return 0;
}