//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000

typedef struct {
    char *email;
    int subscribed;
} email_t;

email_t emails[MAX_EMAILS];
int num_emails = 0;

void add_email(char *email) {
    if (num_emails >= MAX_EMAILS) {
        printf("Error: Maximum number of emails reached.\n");
        return;
    }

    email_t *new_email = &emails[num_emails];
    new_email->email = strdup(email);
    new_email->subscribed = 1;
    num_emails++;
}

void remove_email(char *email) {
    int i;
    for (i = 0; i < num_emails; i++) {
        if (strcmp(emails[i].email, email) == 0) {
            free(emails[i].email);
            emails[i] = emails[--num_emails];
            break;
        }
    }
}

void send_email(char *subject, char *body) {
    int i;
    for (i = 0; i < num_emails; i++) {
        if (emails[i].subscribed) {
            printf("Sending email to %s...\n", emails[i].email);
        }
    }
}

int main() {
    add_email("example@example.com");
    add_email("another@example.com");
    send_email("Test Email", "This is a test email.");
    remove_email("example@example.com");
    send_email("Another Test Email", "This is another test email.");
    return 0;
}