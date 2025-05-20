//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact;

typedef struct {
    contact *contacts;
    int num_contacts;
    int max_contacts;
} mailing_list;

mailing_list *create_mailing_list() {
    mailing_list *ml = (mailing_list *)malloc(sizeof(mailing_list));
    ml->contacts = (contact *)malloc(sizeof(contact) * 10);
    ml->num_contacts = 0;
    ml->max_contacts = 10;
    return ml;
}

void add_contact(mailing_list *ml, char *name, char *email) {
    if (ml->num_contacts == ml->max_contacts) {
        printf("Mailing list is full.\n");
        return;
    }
    strcpy(ml->contacts[ml->num_contacts].name, name);
    strcpy(ml->contacts[ml->num_contacts].email, email);
    ml->num_contacts++;
}

void send_email(mailing_list *ml, char *subject, char *message) {
    for (int i = 0; i < ml->num_contacts; i++) {
        printf("Sending email to %s (%s)...\n", ml->contacts[i].name, ml->contacts[i].email);
        printf("Subject: %s\n", subject);
        printf("Message:\n%s", message);
    }
}

int main() {
    mailing_list *ml = create_mailing_list();

    add_contact(ml, "John Doe", "john.doe@example.com");
    add_contact(ml, "Jane Doe", "jane.doe@example.com");

    char subject[MAX_SUBJECT_LENGTH] = "Test email";
    char message[MAX_MESSAGE_LENGTH] = "Hello, world! ";

    send_email(ml, subject, message);

    return 0;
}