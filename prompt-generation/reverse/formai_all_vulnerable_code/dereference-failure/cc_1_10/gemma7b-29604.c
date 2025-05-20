//Gemma-7B DATASET v1.0 Category: Palindrome Checker ; Style: complex
#include <stdio.h>
#include <string.h>

#define MAX 256

void palindrome_checker(char *str)
{
    int i, j, flag = 0;
    char *rev_str = (char *)malloc(MAX);

    for (i = 0; str[i] != '\0'; i++)
    {
        rev_str[i] = str[i];
    }

    rev_str[i] = '\0';

    for (i = 0; str[i] != '\0'; i++)
    {
        for (j = i; str[j] != '\0'; j++)
        {
            if (str[i] == str[j])
            {
                flag = 1;
            }
        }
    }

    if (flag)
    {
        printf("The string '%s' is a palindrome.\n", str);
    }
    else
    {
        printf("The string '%s' is not a palindrome.\n", str);
    }

    free(rev_str);
}

int main()
{
    char str[MAX];

    printf("Enter a string: ");
    scanf("%s", str);

    palindrome_checker(str);

    return 0;
}