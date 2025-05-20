//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

// Function Declarations
void sanitizeInput(char *input);
int validateEmail(const char *email);
int validateName(const char *name);
int validatePassword(const char *password);
void getInput(char *prompt, char *buffer, int maxLength);

int main() {
    char name[MAX_LEN];
    char email[MAX_LEN];
    char password[MAX_LEN];

    printf("Welcome to the User Input Sanitizer! Let's get started.\n");

    // Get and sanitize name
    getInput("Enter your name: ", name, MAX_LEN);
    sanitizeInput(name);
    if (validateName(name)) {
        printf("Hello, %s! Your name looks good!\n", name);
    } else {
        printf("Oops! Invalid name. Please use only alphabets.\n");
        return 1;
    }

    // Get and sanitize email
    getInput("Enter your email address: ", email, MAX_LEN);
    sanitizeInput(email);
    if (validateEmail(email)) {
        printf("Great! Your email %s is valid.\n", email);
    } else {
        printf("Oops! Invalid email format. Please try again.\n");
        return 1;
    }

    // Get and sanitize password
    getInput("Enter your password (at least 8 characters): ", password, MAX_LEN);
    sanitizeInput(password);
    if (validatePassword(password)) {
        printf("Your password is set successfully!\n");
    } else {
        printf("Oops! Password must be at least 8 characters and contain a number, an uppercase letter, and a special character.\n");
        return 1;
    }

    printf("\nAll inputs sanitized and validated successfully! 🎉\n");
    return 0;
}

// Function to sanitize user input
void sanitizeInput(char *input) {
    int length = strlen(input);
    char *ptr = input;

    // Remove trailing newline
    while (*ptr) {
        if (*ptr == '\n') {
            *ptr = '\0';
        }
        ptr++;
    }

    // Remove any extraneous spaces
    char *sanitized = (char *)malloc(length + 1); // Allocate memory for sanitized input
    char *p = sanitized;
    for (int i = 0; i < length; i++) {
        if (!isspace((unsigned char)input[i])) { // Ignore spaces
            *p++ = input[i];
        }
    }
    *p = '\0'; // Null-terminate the sanitized string
    strcpy(input, sanitized); // Copy sanitized content back to original
    free(sanitized); // Free allocated memory
}

// Function to validate email format using a simple regex-like check
int validateEmail(const char *email) {
    const char *at = strchr(email, '@');
    const char *dot = strrchr(email, '.');
    return at && dot && at < dot; // Basic check for '@' and '.' positions
}

// Function to validate name (only alphabets)
int validateName(const char *name) {
    for (int i = 0; name[i]; i++) {
        if (!isalpha(name[i])) {
            return 0; // Invalid name
        }
    }
    return 1; // Valid name
}

// Function to validate password criteria
int validatePassword(const char *password) {
    int length = strlen(password);
    int hasUpper = 0, hasNumber = 0, hasSpecial = 0;

    if (length < 8) {
        return 0; // Password too short
    }

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) hasUpper = 1;
        if (isdigit(password[i])) hasNumber = 1;
        if (ispunct(password[i])) hasSpecial = 1; // Check for special chars
    }

    return hasUpper && hasNumber && hasSpecial; // All conditions must be met
}

// Utility function to get user input with prompt
void getInput(char *prompt, char *buffer, int maxLength) {
    printf("%s", prompt);
    fflush(stdout); // Ensure prompt is printed before input
    fgets(buffer, maxLength, stdin); // Read input from user
}