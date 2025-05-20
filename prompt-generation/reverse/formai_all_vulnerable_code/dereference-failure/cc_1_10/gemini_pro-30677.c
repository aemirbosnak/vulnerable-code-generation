//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAIL_SIZE 1024
#define MAX_EMAIL_ADDRESS_SIZE 256
#define MAX_EMAIL_SUBJECT_SIZE 128
#define MAX_EMAIL_BODY_SIZE 1024

typedef struct _email {
    char *from;
    char *to;
    char *subject;
    char *body;
} email;

email *create_email(char *from, char *to, char *subject, char *body) {
    email *e = (email *)malloc(sizeof(email));
    e->from = strdup(from);
    e->to = strdup(to);
    e->subject = strdup(subject);
    e->body = strdup(body);
    return e;
}

void destroy_email(email *e) {
    free(e->from);
    free(e->to);
    free(e->subject);
    free(e->body);
    free(e);
}

void send_email(email *e) {
    // TODO: Send the email using SMTP or another protocol
}

int main() {
    char from[MAX_EMAIL_ADDRESS_SIZE];
    char to[MAX_EMAIL_ADDRESS_SIZE];
    char subject[MAX_EMAIL_SUBJECT_SIZE];
    char body[MAX_EMAIL_BODY_SIZE];

    printf("From: ");
    scanf("%s", from);

    printf("To: ");
    scanf("%s", to);

    printf("Subject: ");
    scanf("%s", subject);

    printf("Body: ");
    scanf("%[^\n]%*c", body);

    email *e = create_email(from, to, subject, body);
    send_email(e);
    destroy_email(e);

    return 0;
}