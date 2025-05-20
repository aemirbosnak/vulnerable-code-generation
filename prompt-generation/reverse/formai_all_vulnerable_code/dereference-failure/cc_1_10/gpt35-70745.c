//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: authentic
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

// function to sanitize input string
char* sanitizeInput(char* input)
{
    int i, j = 0;
    char temp[MAX_INPUT_LENGTH];
    char* sanitized = (char*)malloc(sizeof(char) * MAX_INPUT_LENGTH);
    
    // loop through each character in the input string
    for(i = 0; i < strlen(input); i++)
    {
        // check if the character is alphanumeric or a space
        if(isalnum(input[i]) || isspace(input[i]))
        {
            // if so, add it to the temp string
            temp[j] = input[i];
            j++;
        }
    }
    temp[j] = '\0';

    // copy the sanitized string to the sanitized pointer variable
    strcpy(sanitized, temp);

    // return the sanitized string
    return sanitized;
}

int main()
{
    char input[MAX_INPUT_LENGTH];
    char* sanitizedInput;

    printf("Enter your input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    
    // remove trailing newline character
    input[strcspn(input, "\n")] = 0;

    sanitizedInput = sanitizeInput(input);

    printf("Sanitized input: %s\n", sanitizedInput);

    // free memory allocated for sanitizedInput
    free(sanitizedInput);

    return 0;
}