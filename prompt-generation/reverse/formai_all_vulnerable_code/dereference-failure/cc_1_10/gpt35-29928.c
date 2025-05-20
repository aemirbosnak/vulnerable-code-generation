//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: genious
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

bool isPalindrome(char *);

int main()
{
    char input[100];

    printf("Enter a string: ");
    fgets(input, 100, stdin);

    if (isPalindrome(input))
    {
        printf("%s is a palindrome!\n", input);
    }
    else
    {
        printf("%s is not a palindrome.\n", input);
    }

    return 0;
}

bool isPalindrome(char *str)
{
    char *start = str;
    char *end = str;

    while (*end != '\0')
    {
        end++;
    }
    end--;

    while (start < end)
    {
        if (!isalpha(*start))
        {
            start++;
        }
        else if (!isalpha(*end))
        {
            end--;
        }
        else if (tolower(*start) != tolower(*end))
        {
            return false;
        }
        else
        {
            start++;
            end--;
        }
    }

    return true;
}