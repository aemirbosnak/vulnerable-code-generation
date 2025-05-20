//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 50
#define MAX_EMAIL_SIZE 100
#define MAX_SUBJECT_SIZE 100
#define MAX_MESSAGE_SIZE 1000

typedef struct {
    char name[MAX_NAME_SIZE];
    char email[MAX_EMAIL_SIZE];
} Contact;

typedef struct {
    int size;
    int capacity;
    Contact* contacts;
} MailingList;

void init_mailing_list(MailingList* list) {
    list->size = 0;
    list->capacity = 10;
    list->contacts = (Contact*) malloc(list->capacity * sizeof(Contact));
}

void add_contact(MailingList* list, char* name, char* email) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->contacts = (Contact*) realloc(list->contacts, list->capacity * sizeof(Contact));
    }
    strcpy(list->contacts[list->size].name, name);
    strcpy(list->contacts[list->size].email, email);
    list->size++;
}

void send_email(MailingList* list, char* subject, char* message) {
    for (int i = 0; i < list->size; i++) {
        printf("Sending email to %s (%s)\n", list->contacts[i].name, list->contacts[i].email);
    }
}

int main() {
    MailingList list;
    init_mailing_list(&list);

    add_contact(&list, "John Doe", "johndoe@example.com");
    add_contact(&list, "Jane Smith", "janesmith@example.com");

    send_email(&list, "Hello World", "This is a test email!");

    return 0;
}