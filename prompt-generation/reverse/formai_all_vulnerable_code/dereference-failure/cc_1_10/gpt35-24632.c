//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: careful
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LENGTH 1000

// Function prototyping
void sanitizeInput(char* input);

// Main function
int main() {
    char input[MAX_LENGTH];

    printf("Enter some text:\n");
    fgets(input, MAX_LENGTH, stdin);

    sanitizeInput(input);

    printf("Sanitized Input: %s", input);

    return 0;
}

// Function to sanitize user input
void sanitizeInput(char* input) {
    for(int i=0; input[i]!='\0'; i++) {

        // Check for non-alphanumeric characters
        if(isalnum(input[i]) == 0 && input[i] != ' ') {

            // Remove non-alphanumeric characters
            for(int j=i; input[j]!='\0'; j++) {
                input[j] = input[j+1];
            }
            i--;
        }

        // Convert uppercase letters to lowercase
        input[i] = tolower(input[i]);
    }

    // Trim trailing whitespaces
    int i = 0;
    while(input[i] != '\0') {
        i++;
    }
    i--;
    while(input[i] == ' ') {
        input[i] = '\0';
        i--;
    }
}