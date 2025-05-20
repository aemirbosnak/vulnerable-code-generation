//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 256

// This function removes leading and trailing whitespaces from a string
char* trim(char *str) {
    char *end;
    
    // Removing leading whitespaces
    while(isspace((unsigned char)*str)) {
        str++;
    }
    
    // String contains only whitespaces
    if(*str == 0) {
        return str;
    }
    
    // Removing trailing whitespaces
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) {
        end--;
    }
    
    // Adding null character after last non-whitespace character
    *(end+1) = 0;
    
    return str;
}

// This function checks if a string contains only alpha-numeric characters
bool is_alpha_numeric(char *str) {
    while(*str) {
        if(!isalnum(*str++)) {
            return false;
        }
    }
    return true;
}

// This function sanitizes user input to prevent injection attacks
char* sanitize_input(char *input) {
    // Removing leading and trailing whitespaces
    input = trim(input);
    
    // Removing all non alpha-numeric characters except space
    int i, j = 0;
    char *sanitized_input = malloc(sizeof(char) * (MAX_INPUT_LENGTH + 1));
    for(i=0; input[i] != '\0'; i++) {
        if(isalnum(input[i]) || input[i] == ' ') {
            sanitized_input[j++] = input[i];
        }
    }
    sanitized_input[j] = '\0';
    
    // Freeing input memory
    free(input);
    
    return sanitized_input;
}

int main() {
    char *user_input = malloc(sizeof(char) * (MAX_INPUT_LENGTH + 1));
    printf("Enter your input: ");
    fgets(user_input, MAX_INPUT_LENGTH, stdin);
    user_input[strcspn(user_input, "\n")] = '\0'; // Removing new line character
    
    // Sanitizing user input
    user_input = sanitize_input(user_input);
    
    printf("Sanitized input: %s\n", user_input);
    
    // Freeing sanitized input memory
    free(user_input);
    
    return 0;
}