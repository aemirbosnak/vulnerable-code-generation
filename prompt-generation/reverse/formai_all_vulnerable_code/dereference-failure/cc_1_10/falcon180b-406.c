//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100
#define MAX_SUBJECTS 100
#define MAX_BODY 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

typedef struct {
    contact *contacts;
    int num_contacts;
    char *subject;
    char *body;
} mailing_list;

void add_contact(mailing_list *list, char *name, char *email) {
    contact *new_contact = malloc(sizeof(contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->email, email);
    list->contacts = realloc(list->contacts, sizeof(contact) * (list->num_contacts + 1));
    list->contacts[list->num_contacts] = *new_contact;
    list->num_contacts++;
}

void remove_contact(mailing_list *list, char *email) {
    int i;
    for (i = 0; i < list->num_contacts; i++) {
        if (strcmp(list->contacts[i].email, email) == 0) {
            list->contacts = realloc(list->contacts, sizeof(contact) * (list->num_contacts - 1));
            list->num_contacts--;
            break;
        }
    }
}

void send_mail(mailing_list *list) {
    FILE *fp;
    int i;
    char subject[MAX_SUBJECTS];
    char body[MAX_BODY];

    strcpy(subject, list->subject);
    strcat(subject, " - Mailing List");

    fp = fopen("mail.txt", "w");
    fprintf(fp, "Subject: %s\n", subject);
    fprintf(fp, "To: ");
    for (i = 0; i < list->num_contacts; i++) {
        fprintf(fp, "%s <%s>", list->contacts[i].name, list->contacts[i].email);
        if (i!= list->num_contacts - 1) {
            fprintf(fp, ", ");
        }
    }
    fprintf(fp, "\n");
    fprintf(fp, "From: Your Name <your@email.com>\n");
    fprintf(fp, "Content-Type: text/plain; charset=UTF-8\n");
    fprintf(fp, "\n");
    fprintf(fp, "%s", list->body);

    fclose(fp);

    system("mail -s \"Subject\" mail.txt");
}

int main() {
    mailing_list list;
    list.contacts = NULL;
    list.num_contacts = 0;
    list.subject = NULL;
    list.body = NULL;

    add_contact(&list, "John Doe", "john@example.com");
    add_contact(&list, "Jane Doe", "jane@example.com");

    list.subject = malloc(sizeof(char) * MAX_SUBJECTS);
    strcpy(list.subject, "Hello");

    list.body = malloc(sizeof(char) * MAX_BODY);
    strcpy(list.body, "This is a test message.\n");

    send_mail(&list);

    return 0;
}