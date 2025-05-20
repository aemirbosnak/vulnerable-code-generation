//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
char *reverse_string(char *str)
{
    int len = strlen(str);
    char *rev = malloc(len + 1);
    int i, j;
    for (i = 0, j = len - 1; i < len; i++, j--)
    {
        rev[i] = str[j];
    }
    rev[len] = '\0';
    return rev;
}

// Function to check if a string is a palindrome
int is_palindrome(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i - 1])
        {
            return 0;
        }
    }
    return 1;
}

// Function to find the longest palindrome in a string
char *longest_palindrome(char *str)
{
    int len = strlen(str);
    int max_len = 0;
    int start = 0;
    int end = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (is_palindrome(str + i) && j - i + 1 > max_len)
            {
                max_len = j - i + 1;
                start = i;
                end = j;
            }
        }
    }
    char *longest_palindrome = malloc(max_len + 1);
    strncpy(longest_palindrome, str + start, max_len);
    longest_palindrome[max_len] = '\0';
    return longest_palindrome;
}

int main()
{
    char str[] = "Hello, world!";

    printf("Original string: %s\n", str);
    printf("Reversed string: %s\n", reverse_string(str));

    if (is_palindrome(str))
    {
        printf("%s is a palindrome\n", str);
    }
    else
    {
        printf("%s is not a palindrome\n", str);
    }

    char *longest_palindrome_str = longest_palindrome(str);
    printf("Longest palindrome in %s: %s\n", str, longest_palindrome_str);

    return 0;
}