//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

// Function to trim whitespace from the start and the end of a string
char *trimWhitespace(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Null terminate after the last non-space character
    *(end + 1) = '\0';

    return str;
}

// Function to sanitize the username
void sanitizeUsername(char *username) {
    int i, j = 0;
    char temp[MAX_LENGTH];

    for (i = 0; username[i] != '\0'; i++) {
        if (isalnum(username[i]) || username[i] == '_' || username[i] == '-') {
            temp[j++] = username[i];
        }
    }
    temp[j] = '\0';
    strcpy(username, temp);
}

// Function to sanitize the email
void sanitizeEmail(char *email) {
    int i, j = 0;
    char temp[MAX_LENGTH];

    for (i = 0; email[i] != '\0'; i++) {
        if (isalnum(email[i]) || email[i] == '@' || email[i] == '.' || email[i] == '-') {
            temp[j++] = email[i];
        }
    }
    temp[j] = '\0';
    strcpy(email, temp);
}

// Function to check if the sanitized email is valid
int isEmailValid(char *email) {
    if (strchr(email, '@') == NULL || strchr(email, '.') == NULL) {
        return 0; // Invalid email
    }
    return 1; // Valid email
}

int main() {
    char username[MAX_LENGTH];
    char email[MAX_LENGTH];

    printf("🎉 Welcome to the Ultimate Input Sanitizer! 🎉\n");
    printf("Please enter your username: ");
    fgets(username, MAX_LENGTH, stdin);
    username[strcspn(username, "\n")] = 0; // Remove the newline character

    printf("Please enter your email: ");
    fgets(email, MAX_LENGTH, stdin);
    email[strcspn(email, "\n")] = 0; // Remove the newline character

    // Sanitize inputs
    strncpy(username, trimWhitespace(username), MAX_LENGTH);
    strncpy(email, trimWhitespace(email), MAX_LENGTH);
    
    sanitizeUsername(username);
    sanitizeEmail(email);

    // Check if the email is valid
    if (!isEmailValid(email)) {
        printf("❌ Invalid email format! Please ensure it contains '@' and '.'\n");
        return 1;
    }

    // Final Output
    printf("\n🎊 Sanitization Complete! 🎊\n");
    printf("Your sanitized username is: '%s'\n", username);
    printf("Your sanitized email is: '%s'\n", email);

    printf("\nThank you for using our sanitizer! Have a wonderful day! 😊\n");
    return 0;
}