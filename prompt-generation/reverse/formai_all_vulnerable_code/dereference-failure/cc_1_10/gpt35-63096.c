//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

char *sanitize(char *input);

int main()
{
    char *input, *sanitized_input;

    // Allocate memory for input
    input = (char *)malloc(MAX_INPUT_LENGTH);

    printf("Enter your input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Sanitize input
    sanitized_input = sanitize(input);

    printf("Sanitized input: %s\n", sanitized_input);

    // Free memory
    free(input);
    free(sanitized_input);

    return 0;
}

char *sanitize(char *input)
{
    int len = strlen(input);
    char *sanitized_input = (char *)malloc(len);

    for (int i = 0; i < len; i++)
    {
        if (isalnum(input[i]))
        {
            sanitized_input[i] = input[i];
        }
        else
        {
            sanitized_input[i] = ' ';
        }
    }

    // Remove extra spaces
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        if (sanitized_input[i] == ' ')
        {
            if (j == 0 || sanitized_input[j - 1] != ' ')
            {
                sanitized_input[j] = ' ';
                j++;
            }
        }
        else
        {
            sanitized_input[j] = sanitized_input[i];
            j++;
        }
    }
    sanitized_input[j] = '\0';

    return sanitized_input;
}