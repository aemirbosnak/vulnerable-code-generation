//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 200
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact;

typedef struct {
    contact *contacts;
    int num_contacts;
} mailing_list;

void add_contact(mailing_list *list, char *name, char *email) {
    contact *new_contact = (contact *)malloc(sizeof(contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->email, email);
    list->contacts = (contact *)realloc(list->contacts, sizeof(contact) * (list->num_contacts + 1));
    list->contacts[list->num_contacts] = *new_contact;
    list->num_contacts++;
}

void remove_contact(mailing_list *list, int index) {
    contact *temp_contacts = (contact *)malloc(sizeof(contact) * (list->num_contacts - 1));
    int j = 0;
    for (int i = 0; i < list->num_contacts; i++) {
        if (i!= index) {
            strcpy(temp_contacts[j].name, list->contacts[i].name);
            strcpy(temp_contacts[j].email, list->contacts[i].email);
            j++;
        }
    }
    free(list->contacts);
    list->contacts = temp_contacts;
    list->num_contacts--;
}

void send_email(mailing_list *list, char *subject, char *message) {
    for (int i = 0; i < list->num_contacts; i++) {
        printf("Sending email to %s (%s)\n", list->contacts[i].name, list->contacts[i].email);
    }
}

int main() {
    mailing_list list;
    list.contacts = NULL;
    list.num_contacts = 0;

    add_contact(&list, "John Doe", "johndoe@example.com");
    add_contact(&list, "Jane Smith", "janesmith@example.com");

    remove_contact(&list, 0);

    send_email(&list, "Test Email", "This is a test email sent from the mailing list manager.");

    return 0;
}