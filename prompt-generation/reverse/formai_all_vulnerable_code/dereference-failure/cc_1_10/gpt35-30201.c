//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to sanitize user input and remove any unwanted characters
char *sanitize_input(char *input)
{
    char sanitized_input[MAX_LENGTH];
    int i, j = 0;

    for(i = 0; input[i] != '\0'; i++)
    {
        // Check if character is alphanumeric or white space
        if(isalnum(input[i]) || isspace(input[i]))
        {
            sanitized_input[j] = input[i];
            j++;
        }
    }

    sanitized_input[j] = '\0';

    // Copy sanitized input to dynamic memory and return pointer
    char *sanitized = (char*)malloc(strlen(sanitized_input) + 1);
    strcpy(sanitized, sanitized_input);
    return sanitized;
}

int main()
{
    char input[MAX_LENGTH];
    char *sanitized;

    printf("Enter a string to sanitize: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    // Call sanitize_input function and store sanitized string in pointer
    sanitized = sanitize_input(input);

    printf("Sanitized string: %s\n", sanitized);

    free(sanitized); // Free dynamic memory allocated for sanitized string

    return 0;
}