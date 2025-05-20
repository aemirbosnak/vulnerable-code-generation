//Falcon-180B DATASET v1.0 Category: Email Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_RECIPIENTS 100
#define MAX_SUBJECT_LENGTH 100

typedef struct {
    char *name;
    char *email;
} Recipient;

typedef struct {
    char *subject;
    char *body;
    Recipient *recipients;
    int num_recipients;
} Email;

void add_recipient(Email *email, char *name, char *email_address) {
    Recipient *recipient = malloc(sizeof(Recipient));
    recipient->name = strdup(name);
    recipient->email = strdup(email_address);
    email->recipients = realloc(email->recipients, sizeof(Recipient) * (email->num_recipients + 1));
    email->recipients[email->num_recipients++] = *recipient;
    free(recipient);
}

int main() {
    Email email;
    char line[MAX_LINE_LENGTH];
    char *subject = NULL;
    char *body = NULL;
    int body_length = 0;
    int in_body = 0;
    email.recipients = NULL;
    email.num_recipients = 0;

    printf("Enter subject: ");
    fgets(line, MAX_LINE_LENGTH, stdin);
    subject = strdup(line);
    subject = strtok(subject, "\r\n");

    printf("Enter recipients (one per line):\n");
    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        char *name = strtok(line, " ");
        char *email_address = strtok(NULL, "\r\n");
        add_recipient(&email, name, email_address);
    }

    printf("Enter message:\n");
    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        if (in_body) {
            body = realloc(body, body_length + strlen(line) + 1);
            strcat(body, line);
            body_length += strlen(line);
        } else if (strcmp(line, ".") == 0) {
            in_body = 1;
        }
    }

    email.body = body;

    printf("Subject: %s\n", subject);
    printf("Recipients:\n");
    for (int i = 0; i < email.num_recipients; i++) {
        printf("%s <%s>\n", email.recipients[i].name, email.recipients[i].email);
    }

    return 0;
}