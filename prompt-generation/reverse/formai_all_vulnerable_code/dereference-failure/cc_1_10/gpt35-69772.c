//FormAI DATASET v1.0 Category: Email Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 200

// Structs
typedef struct {
    char username[20];
    char domain[20];
} email_address;

typedef struct {
    email_address to_address;
    email_address from_address;
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} email;

// Functions
void send_email(email *e) {
    // Implement SMTP protocol to send email
    printf("Email sent to: %s@%s\n", e->to_address.username, e->to_address.domain);
}

email *compose_email() {
    email *e = malloc(sizeof(email));
    char username[20], domain[20];
    printf("To: ");
    scanf("%19[^@]@%19s", username, domain);
    strcpy(e->to_address.username, username);
    strcpy(e->to_address.domain, domain);
    printf("From: ");
    scanf("%19[^@]@%19s", username, domain);
    strcpy(e->from_address.username, username);
    strcpy(e->from_address.domain, domain);
    printf("Subject: ");
    scanf("%49s", e->subject);
    printf("\nBody: ");
    scanf(" %[^\n]s", e->body);
    return e;
}

int main() {
    email *e = compose_email();
    send_email(e);
    free(e);
    return 0;
}