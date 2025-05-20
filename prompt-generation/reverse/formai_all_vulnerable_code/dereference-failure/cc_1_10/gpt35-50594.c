//FormAI DATASET v1.0 Category: Email Client ; Style: ephemeral
// Ephemeral Style C Email Client Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_INPUT_LENGTH 256
#define MAX_EMAIL_LENGTH 1024

// Function to remove leading and trailing whitespace from a string
char *trim(char *str) {
    char *begin = str;
    char *end = str + strlen(str) - 1;

    while (isspace(*begin)) {
        begin++;
    }
    while (isspace(*end) && end >= begin) {
        end--;
    }
    *(end + 1) = '\0';

    return begin;
}

// Function to validate an email address
bool isValidEmail(char *email) {
    char *at = strchr(email, '@'); // Find @ symbol
    char *dot = strchr(at, '.');  // Find trailing .

    return (at != NULL && dot != NULL && at < dot);
}

int main() {
    char *to, *subject, *message;
    char input[MAX_INPUT_LENGTH];

    // Get recipient email
    printf("To: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    to = trim(input);
    if (!isValidEmail(to)) {
        printf("Invalid email address.\n");
        return 1;
    }

    // Get email subject
    printf("Subject: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    subject = trim(input);

    // Get message body
    printf("Message: ");
    message = (char *) malloc(MAX_EMAIL_LENGTH);
    fgets(message, MAX_EMAIL_LENGTH, stdin);

    // Construct email and send
    char email[MAX_EMAIL_LENGTH];
    sprintf(email, "To: %s\nSubject: %s\n%s", to, subject, message);
    printf("Sending email...\n");
    // Code to send email...

    // Free memory
    free(message);

    return 0;
}