//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 64
#define MAX_EMAIL_LEN 128
#define MAX_SUBJECT_LEN 256
#define MAX_MESSAGE_LEN 2048

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

typedef struct {
    contact* contacts;
    int num_contacts;
    char* subject;
    char* message;
} mailing_list;

void add_contact(mailing_list* list, char* name, char* email) {
    contact* new_contact = malloc(sizeof(contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->email, email);
    list->contacts = realloc(list->contacts, sizeof(contact) * (list->num_contacts + 1));
    list->contacts[list->num_contacts] = *new_contact;
    list->num_contacts++;
}

void send_mail(mailing_list* list) {
    char* to = malloc(list->num_contacts * MAX_EMAIL_LEN);
    char* cc = malloc(list->num_contacts * MAX_EMAIL_LEN);
    int i;
    for (i = 0; i < list->num_contacts; i++) {
        strcat(to, list->contacts[i].email);
        strcat(to, ",");
        strcat(cc, list->contacts[i].email);
        strcat(cc, ",");
    }
    to[strlen(to) - 1] = '\0';
    cc[strlen(cc) - 1] = '\0';
    printf("Sending mail to %s\n", to);
    printf("cc: %s\n", cc);
    free(to);
    free(cc);
}

int main() {
    mailing_list list;
    list.contacts = NULL;
    list.num_contacts = 0;
    list.subject = malloc(MAX_SUBJECT_LEN);
    list.message = malloc(MAX_MESSAGE_LEN);
    strcpy(list.subject, "Test Mail");
    strcpy(list.message, "Hello World!");
    add_contact(&list, "John Doe", "johndoe@example.com");
    add_contact(&list, "Jane Doe", "janedoe@example.com");
    send_mail(&list);
    free(list.subject);
    free(list.message);
    return 0;
}