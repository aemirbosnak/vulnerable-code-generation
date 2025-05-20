//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: ephemeral
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 1024

//
// Parse the input string and check for malicious characters.
//
char* sanitizeInput( char* input )
{
    if ( input == NULL || strlen( input ) == 0 )
    {
        return NULL;
    }
    char* output = malloc(strlen(input) + 1);
    int i=0;
    int j=0;
    while(input[i] != '\0')
    {
        if(isalnum(input[i]) || input[i] == ' ')
        {
            output[j] = input[i];
            j++;
        }
        i++;
    }
    output[j] = '\0';
    return output;
}

int main()
{
    char input[MAX_INPUT_LENGTH];
    char* sanitizedInput;

    printf("Enter input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    sanitizedInput = sanitizeInput(input);

    if (sanitizedInput == NULL)
    {
        printf("Input is empty or contains malicious characters.\n");
    }
    else
    {
        printf("Sanitized input: %s\n", sanitizedInput);
    }

    return 0;
}