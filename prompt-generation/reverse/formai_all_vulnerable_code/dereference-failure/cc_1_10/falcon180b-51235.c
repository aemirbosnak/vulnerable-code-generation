//Falcon-180B DATASET v1.0 Category: Email Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAIL_LENGTH 1024
#define MAX_SUBJECT_LENGTH 256
#define MAX_RECIPIENTS 10

typedef struct {
    char *name;
    char *email;
} Recipient;

typedef struct {
    char *subject;
    char *body;
    Recipient recipients[MAX_RECIPIENTS];
    int num_recipients;
} Email;

Email create_email(char *subject, char *body) {
    Email email = {0};
    strncpy(email.subject, subject, MAX_SUBJECT_LENGTH);
    strncpy(email.body, body, MAX_EMAIL_LENGTH);
    email.num_recipients = 0;
    return email;
}

void add_recipient(Email *email, char *name, char *email_address) {
    if (email->num_recipients >= MAX_RECIPIENTS) {
        printf("Cannot add more than %d recipients.\n", MAX_RECIPIENTS);
        return;
    }
    email->recipients[email->num_recipients].name = strdup(name);
    email->recipients[email->num_recipients].email = strdup(email_address);
    email->num_recipients++;
}

void send_email(Email *email) {
    time_t now = time(NULL);
    char timestamp[32];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&now));

    printf("Sending email with subject: %s\n", email->subject);
    printf("To:");
    for (int i = 0; i < email->num_recipients; i++) {
        printf(" %s <%s>", email->recipients[i].name, email->recipients[i].email);
    }
    printf("\n\n");
    printf("Message:\n%s\n", email->body);
}

int main() {
    Email email = create_email("Test Email", "Hello World!");
    add_recipient(&email, "John Doe", "john.doe@example.com");
    add_recipient(&email, "Jane Doe", "jane.doe@example.com");
    send_email(&email);

    return 0;
}