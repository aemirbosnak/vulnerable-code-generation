//Falcon-180B DATASET v1.0 Category: Email Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_RECIPIENTS 10
#define MAX_ATTACHMENTS 5

typedef struct {
    char* recipient;
    char* subject;
    char* body;
} Email;

typedef struct {
    Email email;
    char** attachments;
    int num_attachments;
} EmailWithAttachments;

Email* create_email(char* recipient, char* subject, char* body) {
    Email* email = malloc(sizeof(Email));
    email->recipient = recipient;
    email->subject = subject;
    email->body = body;
    return email;
}

EmailWithAttachments* create_email_with_attachments(Email* email, char** attachments, int num_attachments) {
    EmailWithAttachments* email_with_attachments = malloc(sizeof(EmailWithAttachments));
    email_with_attachments->email = *email;
    email_with_attachments->attachments = malloc(sizeof(char*) * num_attachments);
    for (int i = 0; i < num_attachments; i++) {
        email_with_attachments->attachments[i] = malloc(sizeof(char) * strlen(attachments[i]) + 1);
        strcpy(email_with_attachments->attachments[i], attachments[i]);
    }
    email_with_attachments->num_attachments = num_attachments;
    return email_with_attachments;
}

void send_email(Email* email) {
    printf("Sending email to %s with subject '%s' and body '%s'\n", email->recipient, email->subject, email->body);
}

void send_email_with_attachments(EmailWithAttachments* email_with_attachments) {
    printf("Sending email to %s with subject '%s' and body '%s'\n", email_with_attachments->email.recipient, email_with_attachments->email.subject, email_with_attachments->email.body);
    for (int i = 0; i < email_with_attachments->num_attachments; i++) {
        printf("  Attachment: %s\n", email_with_attachments->attachments[i]);
    }
}

int main() {
    char* recipients[] = {"john.doe@example.com", "jane.doe@example.com"};
    char* subject = "Test Email";
    char* body = "This is a test email sent from our C email client.";
    Email* email = create_email(recipients[0], subject, body);
    send_email(email);

    char** attachments = malloc(sizeof(char*) * 2);
    attachments[0] = "attachment1.txt";
    attachments[1] = "attachment2.jpg";
    EmailWithAttachments* email_with_attachments = create_email_with_attachments(email, attachments, 2);
    send_email_with_attachments(email_with_attachments);

    free(email->recipient);
    free(email->subject);
    free(email->body);
    free(email);

    for (int i = 0; i < email_with_attachments->num_attachments; i++) {
        free(email_with_attachments->attachments[i]);
    }
    free(email_with_attachments->attachments);
    free(email_with_attachments);

    return 0;
}