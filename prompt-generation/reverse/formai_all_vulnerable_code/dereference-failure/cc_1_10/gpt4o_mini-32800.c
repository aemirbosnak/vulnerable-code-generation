//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

void trim_whitespace(char *str) {
    char *end;

    // Trim leading space
    while(isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;

    // Null terminate string after the last non-space character
    *(end + 1) = '\0';
}

void escape_special_characters(char *str) {
    char buffer[MAX_INPUT_LENGTH];
    int j = 0;

    for(int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\'' || str[i] == '\"' || str[i] == '\\') {
            buffer[j++] = '\\'; // Escape character
        }
        buffer[j++] = str[i];
    }
    buffer[j] = '\0';
    
    strcpy(str, buffer); // Copy the modified string back
}

int is_valid_input(const char *str) {
    // Here you can define what constitutes valid input
    for(int i = 0; str[i] != '\0'; i++) {
        if (!isalnum(str[i]) && !isspace(str[i]) && str[i] != '.' && str[i] != '-') {
            return 0; // Invalid character detected
        }
    }
    return 1; // All characters are valid
}

void get_user_input(char *input, int length) {
    printf("Enter your input (max %d characters): ", length - 1);
    fgets(input, length, stdin);

    // Remove the trailing newline character, if it exists
    size_t len = strlen(input);
    if(len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }
}

int main() {
    char user_input[MAX_INPUT_LENGTH];

    get_user_input(user_input, sizeof(user_input));

    // Step 1: Trim whitespace
    trim_whitespace(user_input);
    
    // Step 2: Check for valid input
    if (!is_valid_input(user_input)) {
        fprintf(stderr, "Error: Invalid input. Only alphanumeric characters, spaces, dots, and dashes are allowed.\n");
        exit(EXIT_FAILURE);
    }

    // Step 3: Escape special characters
    escape_special_characters(user_input);

    // Output sanitized input
    printf("Sanitized input: \"%s\"\n", user_input);

    return 0;
}