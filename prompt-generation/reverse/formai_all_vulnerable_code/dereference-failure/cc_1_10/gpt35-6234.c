//FormAI DATASET v1.0 Category: Email Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_EMAIL_SIZE 2000
#define MAX_SUBJECT_SIZE 100
#define MAX_BODY_SIZE 1500
#define EMAILS_FILE "emails.txt"

typedef struct {
    char from[50];
    char to[50];
    char subject[MAX_SUBJECT_SIZE];
    char body[MAX_BODY_SIZE];
} Email;

void view_emails();
void send_email();
bool validate_email(char email[]);
bool save_email_to_file(Email email);
bool read_email_from_file(char from[], char to[], char subject[], char body[]);

int main() {
    int choice;
    do {
        printf("\nWelcome to Secure email client!\n");
        printf("1. Send an email\n");
        printf("2. View emails\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice) {
            case 1: send_email();
                    break;
            case 2: view_emails();
                    break;
            case 3: printf("\nExiting...\n");
                    exit(0);
            default: printf("\nInvalid choice! Try again.\n");
                     break;
        }
    } while (true);
    return 0;
}

void send_email() {
    Email email;
    printf("Enter your email address: ");
    fgets(email.from, 50, stdin);
    email.from[strlen(email.from)-1] = '\0';

    printf("Enter recipient's email address: ");
    fgets(email.to, 50, stdin);
    email.to[strlen(email.to)-1] = '\0';

    if (!validate_email(email.to)) {
        printf("\nInvalid email address! Please enter a valid email address.\n");
        return;
    }

    printf("Enter email subject: ");
    fgets(email.subject, MAX_SUBJECT_SIZE, stdin);
    email.subject[strlen(email.subject)-1] = '\0';

    printf("Enter email body: ");
    fgets(email.body, MAX_BODY_SIZE, stdin);
    email.body[strlen(email.body)-1] = '\0';

    bool success = save_email_to_file(email);
    if (success) {
        printf("\nEmail sent successfully!\n");
    } else {
        printf("\nError sending email! Please try again.\n");
    }
}

void view_emails() {
    char from[50];
    char to[50];
    char subject[MAX_SUBJECT_SIZE];
    char body[MAX_BODY_SIZE];

    FILE *fptr = fopen(EMAILS_FILE, "r");
    if (fptr == NULL) {
        printf("\nNo emails found!\n");
        return;
    }
    printf("\n|----------------------------------------------------------------------------|\n");
    printf("| %-20s | %-20s | %-50s|\n", "From", "To", "Subject");
    printf("|----------------------------------------------------------------------------|\n");
    while (read_email_from_file(from, to, subject, body)) {
        printf("| %-20s | %-20s | %-50s|\n", from, to, subject);
    }
    printf("|----------------------------------------------------------------------------|\n");
    fclose(fptr);
}

bool validate_email(char email[]) {
    int i, at_idx = -1, dot_idx = -1;
    for (i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            at_idx = i;
        } else if (email[i] == '.') {
            dot_idx = i;
        }
    }
    if (at_idx == -1 || dot_idx == -1 || at_idx > dot_idx) {
        return false;
    }
    return true;
}

bool save_email_to_file(Email email) {
    FILE *fptr = fopen(EMAILS_FILE, "a");
    if (fptr == NULL) {
        return false;
    }
    fprintf(fptr, "%s,%s,%s,%s\n", email.from, email.to, email.subject, email.body);
    fclose(fptr);
    return true;
}

bool read_email_from_file(char from[], char to[], char subject[], char body[]) {
    static FILE *fptr = NULL;
    char buf[MAX_EMAIL_SIZE], *token;

    if (fptr == NULL) {
        fptr = fopen(EMAILS_FILE, "r");
        if (fptr == NULL) {
            return false;
        }
    }

    if (fgets(buf, MAX_EMAIL_SIZE, fptr) != NULL) {
        buf[strlen(buf)-1] = '\0';
        token = strtok(buf, ",");
        strcpy(from, token);
        token = strtok(NULL, ",");
        strcpy(to, token);
        token = strtok(NULL, ",");
        strcpy(subject, token);
        token = strtok(NULL, ",");
        strcpy(body, token);

        return true;
    } else {
        fclose(fptr);
        fptr = NULL;
        return false;
    }
}