//Gemma-7B DATASET v1.0 Category: User Input Sanitizer ; Style: Donald Knuth
#include <stdio.h>
#include <ctype.h>

void sanitize_user_input(char **input)
{
    char *p = *input;
    char *q = *input;
    int flag = 0;

    while (*p)
    {
        switch (*p)
        {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
                *q = toupper(*p);
                flag = 1;
                break;
            default:
                if (!flag)
                    *p = '\0';
                break;
        }
        p++;
        q++;
    }

    *input = q - *input;
}

int main()
{
    char *input = malloc(100);
    printf("Enter a string: ");
    fgets(input, 100, stdin);

    sanitize_user_input(&input);

    printf("Sanitized string: %s\n", input);

    free(input);

    return 0;
}