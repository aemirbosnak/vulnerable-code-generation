//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100
#define MAX_SUBJECT_LEN 200
#define MAX_MESSAGE_LEN 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

typedef struct {
    contact *contacts;
    int num_contacts;
    int max_contacts;
} mailing_list;

void init_mailing_list(mailing_list *list) {
    list->contacts = NULL;
    list->num_contacts = 0;
    list->max_contacts = 0;
}

void add_contact(mailing_list *list, char *name, char *email) {
    contact *contact = malloc(sizeof(contact));
    strncpy(contact->name, name, MAX_NAME_LEN);
    strncpy(contact->email, email, MAX_EMAIL_LEN);
    list->contacts = realloc(list->contacts, sizeof(contact) * ++list->num_contacts);
    list->contacts[list->num_contacts - 1] = *contact;
}

int main() {
    mailing_list list;
    init_mailing_list(&list);

    add_contact(&list, "John Doe", "john.doe@example.com");
    add_contact(&list, "Jane Smith", "jane.smith@example.com");

    char *subject = "Test Email";
    char *message = "Hello, World!";

    for (int i = 0; i < list.num_contacts; i++) {
        printf("Sending email to %s...\n", list.contacts[i].email);
        system(sprintf("echo %s | mail -s %s %s", message, subject, list.contacts[i].email));
    }

    return 0;
}