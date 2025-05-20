//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100

typedef struct email {
    char from[100];
    char to[100];
    char subject[100];
    char body[1000];
} email;

typedef struct mailing_list {
    char name[100];
    int num_emails;
    email emails[MAX_EMAILS];
} mailing_list;

mailing_list* create_mailing_list(char* name) {
    mailing_list* list = malloc(sizeof(mailing_list));
    strcpy(list->name, name);
    list->num_emails = 0;
    return list;
}

void add_email(mailing_list* list, email* email) {
    if (list->num_emails >= MAX_EMAILS) {
        printf("Error: mailing list is full\n");
        return;
    }
    list->emails[list->num_emails] = *email;
    list->num_emails++;
}

void send_email(mailing_list* list, email* email) {
    for (int i = 0; i < list->num_emails; i++) {
        printf("Sending email to: %s\n", list->emails[i].to);
        printf("From: %s\n", email->from);
        printf("Subject: %s\n", email->subject);
        printf("Body: %s\n", email->body);
    }
}

int main() {
    // Create a mailing list
    mailing_list* list = create_mailing_list("My Mailing List");

    // Add some emails to the list
    email email1 = { "john@example.com", "jane@example.com", "Hello", "How are you?" };
    add_email(list, &email1);

    email email2 = { "jane@example.com", "john@example.com", "Re: Hello", "I'm fine, thanks" };
    add_email(list, &email2);

    // Send an email to the list
    email email3 = { "admin@example.com", "john@example.com", "Important Announcement", "This is an important announcement for all members of the mailing list" };
    send_email(list, &email3);

    return 0;
}