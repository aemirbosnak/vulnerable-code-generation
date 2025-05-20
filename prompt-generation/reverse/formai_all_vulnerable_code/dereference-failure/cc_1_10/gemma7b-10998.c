//Gemma-7B DATASET v1.0 Category: User Input Sanitizer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

void sanitize_user_input(char *input)
{
    // 1. Remove leading and trailing whitespaces
    char *start = input;
    char *end = input + strlen(input) - 1;
    while (start <= end && isspace(*start))
    {
        start++;
    }
    while (start <= end && isspace(*end))
    {
        end--;
    }

    // 2. Convert uppercase letters to lowercase
    for (char *p = start; p <= end; p++)
    {
        if (isupper(*p))
        {
            *p = tolower(*p);
        }
    }

    // 3. Remove special characters and control characters
    char allowed_chars[] = {"abcdefghijklmnopqrstuvwxyz0123_+-!@#$%^&*()"};
    for (char *p = start; p <= end; p++)
    {
        if (!strchr(allowed_chars, *p))
        {
            *p = '\0';
        }
    }

    // 4. Normalize line endings
    char *newline = strchr(input, '\n');
    if (newline)
    {
        *newline = '\0';
    }

    // 5. Truncate to maximum length
    if (strlen(input) > MAX_LEN)
    {
        input[MAX_LEN - 1] = '\0';
    }

    // 6. Return sanitized input
    return;
}

int main()
{
    char input[MAX_LEN];
    printf("Enter a string: ");
    fgets(input, MAX_LEN, stdin);

    sanitize_user_input(input);

    printf("Sanitized input: %s\n", input);

    return 0;
}