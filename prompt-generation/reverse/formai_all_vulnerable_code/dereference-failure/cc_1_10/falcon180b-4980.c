//Falcon-180B DATASET v1.0 Category: Email Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LINE_LEN 2048
#define MAX_RECIPIENTS 100
#define MAX_SUBJECT_LEN 256
#define MAX_BODY_LEN (1024*1024) // 1MB

typedef struct {
    char *name;
    char *email;
} recipient_t;

typedef struct {
    char *subject;
    char *body;
    recipient_t recipients[MAX_RECIPIENTS];
    int num_recipients;
} email_t;

void email_init(email_t *email) {
    email->num_recipients = 0;
}

void email_add_recipient(email_t *email, const char *name, const char *email_addr) {
    if (email->num_recipients >= MAX_RECIPIENTS) {
        printf("Error: Too many recipients.\n");
        return;
    }

    recipient_t *recipient = &email->recipients[email->num_recipients];
    recipient->name = strdup(name);
    recipient->email = strdup(email_addr);

    email->num_recipients++;
}

void email_set_subject(email_t *email, const char *subject) {
    if (strlen(subject) > MAX_SUBJECT_LEN) {
        printf("Error: Subject is too long.\n");
        return;
    }

    email->subject = strdup(subject);
}

void email_set_body(email_t *email, const char *body) {
    if (strlen(body) > MAX_BODY_LEN) {
        printf("Error: Body is too long.\n");
        return;
    }

    email->body = strdup(body);
}

void email_send(email_t *email) {
    time_t now = time(NULL);
    char timestamp[32];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&now));

    printf("Sending email...\n");
    printf("To: %s\n", email->recipients[0].email);
    printf("Subject: %s\n", email->subject);
    printf("Timestamp: %s\n", timestamp);
    printf("Body:\n%s\n", email->body);
}

int main() {
    email_t email;
    email_init(&email);

    email_add_recipient(&email, "John Doe", "john.doe@example.com");
    email_add_recipient(&email, "Jane Doe", "jane.doe@example.com");

    email_set_subject(&email, "Test Email");
    email_set_body(&email, "Hello world!");

    email_send(&email);

    return 0;
}