//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define MAX_TRIES 5
#define USERNAME_MAX_LENGTH 20

// Function Definitions
void sanitize_username(char *username);
int validate_username(const char *username);
void get_username(char *username);
void clear_input_buffer();

int main() {
    char *username = (char *)malloc(USERNAME_MAX_LENGTH + 1); // Dynamic allocation for username
    if (username == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    int attempts = 0;
    while (attempts < MAX_TRIES) {
        get_username(username);
        sanitize_username(username);
        
        if (validate_username(username)) {
            printf("Valid username entered: %s\n", username);
            break;
        } else {
            printf("Invalid username. Please try again.\n");
            attempts++;
        }
    }

    if (attempts == MAX_TRIES) {
        printf("Maximum attempts reached. Exiting.\n");
    }

    free(username); // Clean up the allocated memory
    return EXIT_SUCCESS;
}

void sanitize_username(char *username) {
    // Trimming whitespace from beginning and end
    char *start = username;
    while (*start == ' ') start++;
    char *end = username + strlen(username) - 1;
    while (end > start && *end == ' ') end--;
    end[1] = '\0'; // Null terminate the trimmed string

    // Convert to lowercase
    for (int i = 0; start[i]; i++) {
        start[i] = tolower(start[i]);
    }
}

int validate_username(const char *username) {
    regex_t regex;
    const char *pattern = "^[a-zA-Z0-9_]+$"; // Alphanumeric and underscore only

    int reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        return 0;
    }

    reti = regexec(&regex, username, 0, NULL, 0);
    regfree(&regex);

    return (reti == 0);
}

void get_username(char *username) {
    printf("Enter your username (max %d chars): ", USERNAME_MAX_LENGTH);
    if (fgets(username, USERNAME_MAX_LENGTH + 1, stdin) == NULL) {
        fprintf(stderr, "Error reading input\n");
        exit(EXIT_FAILURE);
    }
    // Remove newline character from input
    size_t len = strlen(username);
    if (len > 0 && username[len - 1] == '\n') {
        username[len - 1] = '\0';
    }
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}