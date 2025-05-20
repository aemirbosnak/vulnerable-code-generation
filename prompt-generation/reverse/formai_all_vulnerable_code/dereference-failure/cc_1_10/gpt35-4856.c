//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

// Function to sanitize user input
void sanitize(char input[]) {
    int i, j = 0;
    char temp[MAX_EMAIL_LENGTH];
    
    // Remove leading and trailing white spaces
    while (isspace(input[0])) {
        memmove(input, input+1, strlen(input));
    }
    while (isspace(input[strlen(input)-1])) {
        input[strlen(input)-1] = '\0';
    }
    
    // Convert email to lowercase
    for (i = 0; input[i]; i++) {
        temp[j++] = tolower(input[i]);
    }
    temp[j] = '\0';
    strcpy(input, temp);
    
    // Replace multiple spaces with a single space
    for (i = 0; i < strlen(input)-1; i++) {
        if (isspace(input[i]) && isspace(input[i+1])) {
            memmove(input+i, input+i+1, strlen(input)-i);
            i--;
        }
    }
    
    // Remove non-alphanumeric and non-space characters
    for (i = 0, j = 0; i < strlen(input); i++) {
        if (isalnum(input[i]) || isspace(input[i])) {
            input[j++] = input[i];
        }
    }
    input[j] = '\0';
}

int main() {
    char name[MAX_NAME_LENGTH], email[MAX_EMAIL_LENGTH];
    
    // Get user input
    printf("Hello! What is your name?\n");
    fgets(name, MAX_NAME_LENGTH, stdin);
    printf("Nice to meet you, %s! What is your email address?\n", name);
    fgets(email, MAX_EMAIL_LENGTH, stdin);
    
    // Sanitize user input
    sanitize(name);
    sanitize(email);
    
    // Print sanitized input
    printf("Your name is: %s\n", name);
    printf("Your email address is: %s\n", email);
    
    return 0;
}