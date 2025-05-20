//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char *str);

int main()
{
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    if (isPalindrome(str))
        printf("%s is a palindrome", str);
    else
        printf("%s is not a palindrome", str);

    return 0;
}

/**
 * isPalindrome - Checks if a string is a palindrome
 * @str: Input string
 *
 * This function checks if a given string is a palindrome or not.
 *
 * Return: 1 if the string is a palindrome, 0 otherwise.
 */
int isPalindrome(char *str)
{
    int i, len = strlen(str) - 1;
    char *start = str;
    char *end = str + len;

    while (end > start)
    {
        // ignore spaces and punctuation marks
        if (!isalpha(*start))
        {
            start++;
            continue;
        }
        if (!isalpha(*end))
        {
            end--;
            continue;
        }
        if (tolower(*start) != tolower(*end))
            return 0;
        start++;
        end--;
    }
    return 1;
}