//FormAI DATASET v1.0 Category: Email Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *sender;
    char **recipients;
    int num_recipients;
    char *subject;
    char *body;
} Email;

typedef struct {
    char *server;
    char *username;
    char *password;
} Account;

void compose_email(Email *email) {
    printf("Enter sender address:\n");
    scanf("%ms", &(email->sender));

    printf("Enter number of recipients:\n");
    scanf("%d", &(email->num_recipients));

    email->recipients = malloc(email->num_recipients * sizeof(char *));
    printf("Enter recipient addresses:\n");
    for (int i = 0; i < email->num_recipients; i++) {
        scanf("%ms", &(email->recipients[i]));
    }

    printf("Enter subject:\n");
    scanf("%ms", &(email->subject));

    printf("Enter body:\n");
    scanf(" %[^\n]m", &(email->body));
}

void print_email(Email email) {
    printf("From: %s\n", email.sender);
    printf("To: ");
    for (int i = 0; i < email.num_recipients; i++) {
        printf("%s", email.recipients[i]);
        if (i != email.num_recipients - 1) {
            printf(", ");
        }
    }
    printf("\n");
    printf("Subject: %s\n", email.subject);
    printf("Body: %s\n", email.body);
}

int send_email(Email email, Account account) {
    // code to send email
    printf("Email sent succesfully.\n");
    return 1;
}

int main() {
    Email email;
    Account account = {"smtp.example.com", "user@example.com", "password"};

    printf("Compose new email:\n");
    compose_email(&email);
    print_email(email);

    printf("Send email? (y/n)\n");
    char choice;
    scanf(" %c", &choice);

    if (choice == 'y') {
        send_email(email, account);
    }

    free(email.sender);
    for (int i = 0; i < email.num_recipients; i++) {
        free(email.recipients[i]);
    }
    free(email.recipients);
    free(email.subject);
    free(email.body);

    return 0;
}