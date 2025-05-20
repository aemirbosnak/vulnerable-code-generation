//Gemma-7B DATASET v1.0 Category: User Input Sanitizer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

void sanitize_user_input(char **buffer)
{
    char *ptr = *buffer;
    char *end = *buffer + MAX_BUFFER_SIZE;
    char ch;

    while ((ch = getchar()) != '\n' && ptr < end)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            *ptr++ = ch - 'a' + 'A';
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            *ptr++ = ch - 'A' + 'a';
        }
        else if (ch >= '0' && ch <= '9')
        {
            *ptr++ = ch - '0' + '0';
        }
        else if (ch == ' ')
        {
            *ptr++ = ' ';
        }
        else
        {
            printf("Invalid character. Please try again.\n");
            *buffer = NULL;
            return;
        }
    }

    *ptr = NULL;
    return;
}

int main()
{
    char *buffer = NULL;

    printf("Enter a message: ");
    buffer = malloc(MAX_BUFFER_SIZE);

    sanitize_user_input(&buffer);

    if (buffer)
    {
        printf("Your message is: %s\n", buffer);
        free(buffer);
    }

    return 0;
}