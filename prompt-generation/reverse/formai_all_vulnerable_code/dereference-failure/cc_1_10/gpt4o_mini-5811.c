//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100

// Function to sanitize input
void sanitize_input(const char *input, char *sanitized_output) {
    int j = 0; // To track index for sanitized_output
    for (int i = 0; input[i] != '\0'; i++) {
        // Skip if already sanitized, this checks alphanumeric and allowed special characters
        if (isalnum(input[i]) || input[i] == '_' || input[i] == '-') {
            sanitized_output[j++] = input[i];
        }
    }
    sanitized_output[j] = '\0'; // Null-terminate the sanitized string
}

// Function to trim whitespace
void trim_whitespace(char *str) {
    char *end;
    // Trim leading space
    while (isspace((unsigned char)*str)) str++;
    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    end[1] = '\0'; // Null-terminate after the last non-space character
}

// Function to display user info
void display_user_info(const char *username, const char *email) {
    printf("Registration Successful!\n");
    printf("Username: %s\n", username);
    printf("Email: %s\n", email);
}

int main() {
    char username[MAX_INPUT_SIZE];
    char email[MAX_INPUT_SIZE];
    char sanitized_username[MAX_INPUT_SIZE];
    char sanitized_email[MAX_INPUT_SIZE];

    printf("Welcome to the User Registration System!\n");

    // Input username
    printf("Enter your username: ");
    if (fgets(username, sizeof(username), stdin) != NULL) {
        trim_whitespace(username);
        sanitize_input(username, sanitized_username);
    }

    // Input email
    printf("Enter your email: ");
    if (fgets(email, sizeof(email), stdin) != NULL) {
        trim_whitespace(email);
        sanitize_input(email, sanitized_email);
    }

    // Display sanitized user info
    display_user_info(sanitized_username, sanitized_email);

    return 0;
}