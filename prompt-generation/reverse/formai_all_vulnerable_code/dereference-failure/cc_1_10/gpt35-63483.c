//FormAI DATASET v1.0 Category: Email Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024
#define MAX_EMAIL_LENGTH 1024
#define MAX_SUBJECT_LENGTH 256
#define MAX_BODY_LENGTH 4096

typedef struct {
    char to[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} email_t;

/**
 * Get a line of input from the user and trim leading and trailing whitespace.
 * Returns a pointer to the trimmed string.
 */
char *get_input() {
    char *line = malloc(sizeof(char) * MAX_LINE_LENGTH);
    fgets(line, MAX_LINE_LENGTH, stdin);

    size_t len = strlen(line);
    while (len > 0 && isspace(line[len - 1])) {
        len--;
    }
    line[len] = '\0';

    while (isspace(*line)) {
        line++;
    }

    return line;
}

/**
 * Send an email using the provided email_t struct.
 * Returns 0 if the email is successfully sent, -1 otherwise.
 */
int send_email(email_t *email) {
    printf("Sending email...\n");
    printf("To: %s\n", email->to);
    printf("Subject: %s\n", email->subject);
    printf("Body: %s\n", email->body);
    return 0;
}

int main() {
    printf("Welcome to the futuristic email client!\n");

    while (1) {
        printf("\n");
        printf("What would you like to do?\n");
        printf("1. Compose email\n");
        printf("2. Exit\n");
        printf("\n");

        char *option = get_input();
        if (strcmp(option, "1") == 0) {
            printf("Enter recipient email address:\n");
            char *to = get_input();

            printf("Enter email subject:\n");
            char *subject = get_input();

            printf("Enter email body text:\n");
            char *body = get_input();

            email_t email;
            strcpy(email.to, to);
            strcpy(email.subject, subject);
            strcpy(email.body, body);

            int result = send_email(&email);
            if (result == 0) {
                printf("Email sent!\n");
            } else {
                printf("Failed to send email.\n");
            }
        } else if (strcmp(option, "2") == 0) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid option %s selected. Please try again.\n", option);
        }
    }

    return 0;
}