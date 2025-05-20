//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
char* reverse_string(char* str)
{
    int len = strlen(str);
    char* reversed_str = malloc(len + 1);
    int i, j;

    for (i = 0, j = len - 1; i < len; i++, j--)
    {
        reversed_str[i] = str[j];
    }

    reversed_str[len] = '\0';

    return reversed_str;
}

// Function to check if a string is a palindrome
int is_palindrome(char* str)
{
    int len = strlen(str);
    int i;

    for (i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i - 1])
        {
            return 0;
        }
    }

    return 1;
}

// Function to count the number of vowels in a string
int count_vowels(char* str)
{
    int len = strlen(str);
    int i, count;

    count = 0;

    for (i = 0; i < len; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            count++;
        }
    }

    return count;
}

// Function to find the longest word in a string
char* find_longest_word(char* str)
{
    int len = strlen(str);
    int i, j, start, end, max_len;
    char* longest_word;

    start = 0;
    end = 0;
    max_len = 0;

    for (i = 0; i < len; i++)
    {
        if (str[i] != ' ')
        {
            end++;
        }
        else
        {
            if (end - start > max_len)
            {
                max_len = end - start;
                longest_word = &str[start];
            }
            start = i + 1;
            end = i + 1;
        }
    }

    if (end - start > max_len)
    {
        max_len = end - start;
        longest_word = &str[start];
    }

    return longest_word;
}

// Main function
int main()
{
    char* str = "Hello, world!";
    char* reversed_str;
    int palindrome;
    int vowel_count;
    char* longest_word;

    printf("The original string is: %s\n", str);

    reversed_str = reverse_string(str);
    printf("The reversed string is: %s\n", reversed_str);

    palindrome = is_palindrome(str);
    printf("Is the string a palindrome? %d\n", palindrome);

    vowel_count = count_vowels(str);
    printf("The number of vowels in the string is: %d\n", vowel_count);

    longest_word = find_longest_word(str);
    printf("The longest word in the string is: %s\n", longest_word);

    return 0;
}