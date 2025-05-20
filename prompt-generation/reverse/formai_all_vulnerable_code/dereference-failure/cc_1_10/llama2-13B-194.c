//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 256
#define EMAIL_LEN 1024

typedef struct {
    char *name;
    char *email;
    char *message;
} email_t;

email_t * emails = NULL;
int num_emails = 0;

void init_emails() {
    emails = malloc(sizeof(email_t) * 10);
    for (int i = 0; i < 10; i++) {
        emails[i].name = malloc(256);
        emails[i].email = malloc(256);
        emails[i].message = malloc(256);
        sprintf(emails[i].name, "HappyUser%d", i + 1);
        sprintf(emails[i].email, "happyuser%d@example.com", i + 1);
        sprintf(emails[i].message, "Hello world! This is email %d", i + 1);
    }
    num_emails = 10;
}

void add_email(char *name, char *email, char *message) {
    email_t *new_email = malloc(sizeof(email_t));
    new_email->name = name;
    new_email->email = email;
    new_email->message = message;
    if (num_emails >= 10) {
        printf("Email limit reached! Deleting oldest email...\n");
        free(emails[0].name);
        free(emails[0].email);
        free(emails[0].message);
        num_emails--;
    }
    emails = realloc(emails, (num_emails + 1) * sizeof(email_t));
    emails[num_emails] = *new_email;
    num_emails++;
}

void send_emails() {
    for (int i = 0; i < num_emails; i++) {
        printf("Sending email to %s <%s> with message: %s\n", emails[i].name, emails[i].email, emails[i].message);
        // simulate sending email by sleeping for a random amount of time
        sleep(rand() % 5000 + 1000);
    }
}

int main() {
    init_emails();
    add_email("HappyUser1", "happyuser1@example.com", "Hello world! This is email 1");
    add_email("HappyUser2", "happyuser2@example.com", "Hello world! This is email 2");
    add_email("HappyUser3", "happyuser3@example.com", "Hello world! This is email 3");
    send_emails();
    return 0;
}