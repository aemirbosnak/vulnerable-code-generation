//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Function to remove new line character from the input */
void removeNewLine(char *input)
{
    int i = 0;
    while(input[i] != '\0')
    {
        if(input[i] == '\n')
        {
            input[i] = '\0';
            break;
        }
        i++;
    }
}

/* Function to sanitize the input */
char* sanitizeInput(char *input)
{
    char *sanitizedInput = malloc(strlen(input) + 1);
    int i = 0, j = 0;
    while(input[i] != '\0')
    {
        if(isdigit(input[i]) || isalpha(input[i]))
        {
            sanitizedInput[j++] = input[i++];
        }
        else if(input[i] == ' ')
        {
            sanitizedInput[j++] = input[i++];
            while(input[i] == ' ')
            {
                i++;
            }
        }
        else
        {
            i++;
        }
    }
    sanitizedInput[j] = '\0';
    return sanitizedInput;
}

int main(void)
{
    char input[100];
    printf("Enter a string: ");
    fgets(input, 100, stdin);
    removeNewLine(input);

    char *sanitizedInput = sanitizeInput(input);
    
    printf("Sanitized Input: %s\n", sanitizedInput);

    free(sanitizedInput);

    return 0;
}