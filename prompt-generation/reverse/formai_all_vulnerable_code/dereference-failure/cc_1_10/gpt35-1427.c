//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

void sanitize_input(char *input);

int main(void)
{
    char input[MAX_INPUT_LENGTH];
    printf("Enter your input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    sanitize_input(input);
    printf("Your sanitized input is: %s", input);
    return 0;
}

void sanitize_input(char *input)
{
    int input_length = strlen(input);
    // Remove trailing newline character
    if (input[input_length - 1] == '\n')
    {
        input[input_length - 1] = '\0';
    }
    // Convert all characters to lowercase
    for (int i = 0; i < input_length; i++)
    {
        input[i] = tolower(input[i]);
    }
    // Remove any non-alphanumeric characters
    for (int i = 0; i < input_length; i++)
    {
        if (!isalnum(input[i]))
        {
            for (int j = i; j < input_length; j++)
            {
                input[j] = input[j + 1];
            }
            input_length--;
            i--;
        }
    }
    // Pad any spaces within the input with an underscore character
    for (int i = 0; i < input_length; i++)
    {
        if (input[i] == ' ')
        {
            input[i] = '_';
        }
    }
}