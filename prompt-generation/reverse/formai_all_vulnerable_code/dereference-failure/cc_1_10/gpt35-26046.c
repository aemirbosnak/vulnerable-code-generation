//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: automated
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 50

void sanitizeInput(char* input);

int main()
{
    char input[MAX_INPUT_LENGTH];
    printf("Enter your input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    printf("Your input was: %s", input);
    sanitizeInput(input);
    printf("Your sanitized input is: %s", input);
    return 0;
}

void sanitizeInput(char* input)
{
    // Remove newline character if present
    int len = strlen(input);
    if (input[len-1] == '\n')
    {
        input[len-1] = '\0';
        len--;
    }

    // Remove leading and trailing white space
    char* begin = input;
    char* end = input + len - 1;
    while (isspace(*begin))
    {
        begin++;
    }
    while (isspace(*end))
    {
        end--;
    }
    *(end+1) = '\0';
    len = end - begin + 1;

    // Replace invalid characters with spaces
    for (int i = 0; i < len; i++)
    {
        if (!isalnum(input[i]))
        {
            input[i] = ' ';
        }
    }

    // Remove multiple consecutive spaces
    char* dest = input;
    for (int i = 0; i < len; i++)
    {
        if (isspace(input[i]))
        {
            *dest = ' ';
            dest++;
            while (isspace(input[i]))
            {
                i++;
            }
            i--;
        }
        else
        {
            *dest = input[i];
            dest++;
        }
    }
    *dest = '\0';
}