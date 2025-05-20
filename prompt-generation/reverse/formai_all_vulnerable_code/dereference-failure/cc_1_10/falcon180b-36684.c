//Falcon-180B DATASET v1.0 Category: Email Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAIL_LENGTH 1000
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 10000
#define MAX_ATTACHMENTS 10
#define MAX_ATTACHMENT_LENGTH 10000

typedef struct email_t {
    char from[MAX_EMAIL_LENGTH];
    char to[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    int num_attachments;
    char attachments[MAX_ATTACHMENTS][MAX_ATTACHMENT_LENGTH];
} Email;

Email* create_email() {
    Email* email = malloc(sizeof(Email));
    memset(email, 0, sizeof(Email));
    return email;
}

void free_email(Email* email) {
    free(email);
}

void set_from(Email* email, char* from) {
    strncpy(email->from, from, MAX_EMAIL_LENGTH);
}

void set_to(Email* email, char* to) {
    strncpy(email->to, to, MAX_EMAIL_LENGTH);
}

void set_subject(Email* email, char* subject) {
    strncpy(email->subject, subject, MAX_SUBJECT_LENGTH);
}

void set_body(Email* email, char* body) {
    strncpy(email->body, body, MAX_BODY_LENGTH);
}

void add_attachment(Email* email, char* attachment) {
    int i;
    for (i = 0; i < email->num_attachments; i++) {
        if (strcmp(email->attachments[i], attachment) == 0) {
            return;
        }
    }
    if (email->num_attachments >= MAX_ATTACHMENTS) {
        printf("Error: Too many attachments\n");
        return;
    }
    strncpy(email->attachments[email->num_attachments], attachment, MAX_ATTACHMENT_LENGTH);
    email->num_attachments++;
}

void print_email(Email* email) {
    printf("From: %s\n", email->from);
    printf("To: %s\n", email->to);
    printf("Subject: %s\n", email->subject);
    printf("Body:\n%s", email->body);
    printf("Attachments:\n");
    int i;
    for (i = 0; i < email->num_attachments; i++) {
        printf("%s\n", email->attachments[i]);
    }
}

int main() {
    Email* email = create_email();

    set_from(email, "sender@example.com");
    set_to(email, "recipient@example.com");
    set_subject(email, "Test Email");
    set_body(email, "Hello, World!");

    add_attachment(email, "attachment1.txt");
    add_attachment(email, "attachment2.txt");

    print_email(email);

    free_email(email);

    return 0;
}