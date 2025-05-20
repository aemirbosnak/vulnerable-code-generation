//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LEN 256

void sanitizeInput(char* input);

int main()
{
    char input[MAX_INPUT_LEN];
    
    printf("Enter your input: ");
    fgets(input, MAX_INPUT_LEN, stdin);
    
    // Remove trailing newline character from input
    input[strcspn(input, "\n")] = '\0';
    
    sanitizeInput(input);
    
    printf("Sanitized input: %s\n", input);
    
    return 0;
}

void sanitizeInput(char* input)
{
    // Replace all non-alphanumeric characters with space
    for (int i = 0; i < strlen(input); i++)
    {
        if (!isalnum(input[i]))
        {
            input[i] = ' ';
        }
    }
    
    // Convert all alphabetic characters to lowercase
    for (int i = 0; i < strlen(input); i++)
    {
        if (isalpha(input[i]))
        {
            input[i] = tolower(input[i]);
        }
    }
    
    // Remove leading and trailing spaces
    int i, j;
    for (i = 0; input[i] == ' '; i++);
    for (j = strlen(input) - 1; j >= 0 && input[j] == ' '; j--);
    input[j + 1] = '\0';
    memmove(input, input + i, j - i + 2);
}