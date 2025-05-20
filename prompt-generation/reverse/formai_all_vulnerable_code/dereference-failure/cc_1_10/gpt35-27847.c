//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: automated
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000

char* sanitizeInput(char* inputString);

int main()
{
    char userInput[MAX_INPUT_LENGTH];
    printf("Enter some text: ");
    fgets(userInput, MAX_INPUT_LENGTH, stdin);

    printf("Original input: %s", userInput);

    char* sanitizedInput = sanitizeInput(userInput);

    printf("Sanitized input: %s", sanitizedInput);

    return 0;
}

char* sanitizeInput(char* inputString)
{
    int i;
    int j = 0;
    int length = strlen(inputString);

    // Allocate new string
    char* sanitized = (char*) malloc(sizeof(char) * length+1);

    for(i = 0; i < length; i++)
    {
        // Check if character is alphanumeric
        if(isalnum(inputString[i]))
        {
            // Convert to lowercase
            sanitized[j++] = tolower(inputString[i]);
        }
        // Check if character is whitespace
        else if(isspace(inputString[i]))
        {
            // Replace with underscore
            sanitized[j++] = '_';
        }
        // Skip all other characters
        else
        {
            continue;
        }
    }
    // Null terminate the string
    sanitized[j] = '\0';

    return sanitized;
}