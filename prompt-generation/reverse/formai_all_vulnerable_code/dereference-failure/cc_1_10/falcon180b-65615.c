//Falcon-180B DATASET v1.0 Category: Email Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 1000
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 5000
#define MAX_RECIPIENTS 100

typedef struct {
    char *name;
    char *email;
} recipient_t;

typedef struct {
    char *subject;
    char *body;
    int num_recipients;
    recipient_t *recipients;
} email_t;

void send_email(email_t *email) {
    printf("Sending email...\n");
    printf("Subject: %s\n", email->subject);
    printf("Body:\n%s\n", email->body);
    printf("Recipients:\n");
    for (int i = 0; i < email->num_recipients; i++) {
        printf("%s <%s>\n", email->recipients[i].name, email->recipients[i].email);
    }
}

int main() {
    char input[MAX_EMAIL_LENGTH];
    email_t email;

    printf("Enter email subject: ");
    fgets(input, MAX_EMAIL_LENGTH, stdin);
    strcpy(email.subject, input);

    printf("Enter email body: ");
    fgets(input, MAX_BODY_LENGTH, stdin);
    strcpy(email.body, input);

    printf("Enter number of recipients: ");
    scanf("%d", &email.num_recipients);

    email.recipients = (recipient_t *) malloc(email.num_recipients * sizeof(recipient_t));

    for (int i = 0; i < email.num_recipients; i++) {
        printf("Enter recipient %d name: ", i+1);
        fgets(input, MAX_EMAIL_LENGTH, stdin);
        strcpy(email.recipients[i].name, input);

        printf("Enter recipient %d email: ", i+1);
        fgets(input, MAX_EMAIL_LENGTH, stdin);
        strcpy(email.recipients[i].email, input);
    }

    send_email(&email);

    return 0;
}