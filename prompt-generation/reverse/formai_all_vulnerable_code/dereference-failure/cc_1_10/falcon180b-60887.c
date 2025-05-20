//Falcon-180B DATASET v1.0 Category: Email Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_ATTACHMENTS 10

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    char attachments[MAX_ATTACHMENTS][MAX_BODY_LENGTH];
    time_t timestamp;
} Email;

Email* create_email() {
    Email* email = malloc(sizeof(Email));
    memset(email, 0, sizeof(Email));
    return email;
}

void set_subject(Email* email, char* subject) {
    strncpy(email->subject, subject, MAX_SUBJECT_LENGTH);
}

void set_body(Email* email, char* body) {
    strncpy(email->body, body, MAX_BODY_LENGTH);
}

void add_attachment(Email* email, char* attachment) {
    int i = 0;
    while (i < MAX_ATTACHMENTS && email->attachments[i][0]!= '\0') {
        i++;
    }
    if (i < MAX_ATTACHMENTS) {
        strncpy(email->attachments[i], attachment, MAX_BODY_LENGTH);
    }
}

void send_email(Email* email) {
    printf("Sending email...\n");
    printf("Subject: %s\n", email->subject);
    printf("Body:\n%s\n", email->body);
    for (int i = 0; i < MAX_ATTACHMENTS; i++) {
        if (email->attachments[i][0]!= '\0') {
            printf("Attachment %d:\n%s\n", i + 1, email->attachments[i]);
        }
    }
}

int main() {
    Email* email = create_email();
    set_subject(email, "Test Email");
    set_body(email, "This is a test email sent using the C Email Client.");
    add_attachment(email, "This is an attachment. ");
    time_t timestamp = time(NULL);
    email->timestamp = timestamp;
    send_email(email);
    return 0;
}