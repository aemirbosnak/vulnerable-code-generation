//FormAI DATASET v1.0 Category: Mailing list manager ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100 // Maximum number of emails in the mailing list
#define MAX_SUBJECT_LENGTH 100 // Maximum length of email subject
#define MAX_BODY_LENGTH 2000 // Maximum length of email body

struct Email {
    char* recipient;
    char* subject;
    char* body;
};

struct MailingList {
    int num_emails;
    struct Email* emails[MAX_EMAILS];
};

void init_mailing_list(struct MailingList* list) {
    list->num_emails = 0;
}

void add_email(struct MailingList* list, char* recipient, char* subject, char* body) {
    if (list->num_emails >= MAX_EMAILS) {
        printf("Mailing list is full\n");
        return;
    }

    struct Email* email = malloc(sizeof(struct Email));
    email->recipient = recipient;
    email->subject = subject;
    email->body = body;

    list->emails[list->num_emails++] = email;
}

void print_email(struct Email* email) {
    printf("To: %s\nSubject: %s\n%s\n", email->recipient, email->subject, email->body);
}

void print_mailing_list(struct MailingList* list) {
    printf("Mailing List:\n");
    for (int i = 0; i < list->num_emails; i++) {
        printf("%d: ", i + 1);
        print_email(list->emails[i]);
        printf("\n");
    }
}

void send_email(struct Email* email) {
    printf("Sending email to %s:\n", email->recipient);
    printf("%s\n%s\n", email->subject, email->body);
}

void send_emails(struct MailingList* list) {
    printf("Sending %d emails...\n", list->num_emails);
    for (int i = 0; i < list->num_emails; i++) {
        send_email(list->emails[i]);
        printf("\n");
    }
}

int main() {
    struct MailingList list;
    init_mailing_list(&list);

    // Add some example emails to the mailing list
    add_email(&list, "jane@example.com", "Hello", "Hi Jane! How are you?");
    add_email(&list, "john@example.com", "Meeting Reminder", "Hi John, just a quick reminder about our meeting tomorrow at 10am.");
    add_email(&list, "alice@example.com", "Important Information", "Hi Alice, I wanted to let you know about some important information regarding the project.");

    // Print the mailing list
    print_mailing_list(&list);

    // Send all the emails in the mailing list
    send_emails(&list);

    return 0;
}