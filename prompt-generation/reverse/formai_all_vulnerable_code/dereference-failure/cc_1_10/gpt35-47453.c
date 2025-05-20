//FormAI DATASET v1.0 Category: Email Client ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

bool is_valid_email(char *email) {
    // Check for @ symbol
    char *at_symbol = strchr(email, '@');
    if (at_symbol == NULL || at_symbol == email) {
        return false;
    }

    // Check for valid domain
    char *domain = at_symbol + 1;
    if (strchr(domain, '.') == NULL) {
        return false;
    }

    return true;
}

int main() {
    char buffer[BUFFER_SIZE];

    printf("Enter your email address: ");
    fgets(buffer, BUFFER_SIZE, stdin);

    // Remove newline character from input
    buffer[strcspn(buffer, "\n")] = 0;

    if (!is_valid_email(buffer)) {
        printf("Invalid email address.\n");
        return 1;
    }

    // Get user's name from email address
    char *at_symbol = strchr(buffer, '@');
    int username_length = at_symbol - buffer;
    char *username = malloc(sizeof(char) * (username_length + 1));
    strncpy(username, buffer, username_length);
    username[username_length] = '\0';

    // Connect to email server
    printf("Connecting to email server...\n");

    // Authenticate user
    printf("Enter your password: ");
    fgets(buffer, BUFFER_SIZE, stdin);

    // Remove newline character from input
    buffer[strcspn(buffer, "\n")] = 0;

    printf("Authenticating user %s...\n", username);

    // Check inbox
    printf("Checking inbox...\n");

    // Print email headers
    printf("\nFrom: %s\n", "example@sender.com");
    printf("To: %s\n", buffer);
    printf("Subject: %s\n", "Sample Email");
    printf("Date: %s\n", "2021-01-01 10:00AM");
    printf("\n");
    printf("Hello %s,\n\n", username);
    printf("This is a sample email message.\n");
    printf("\n");
    printf("Thank you,\n");
    printf("Example Sender");

    // Disconnect from email server
    printf("Disconnecting from email server...\n");

    return 0;
}