//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
char *reverse(char *str)
{
    int len = strlen(str);
    char *new_str = malloc(len + 1);
    for (int i = 0; i < len; i++)
    {
        new_str[len - i - 1] = str[i];
    }
    new_str[len] = '\0';
    return new_str;
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

// Function to find the longest palindrome substring in a string
char *longest_palindrome_substring(char *str)
{
    int len = strlen(str);
    int max_len = 0;
    int start = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            int curr_len = j - i + 1;
            if (curr_len > max_len && is_palindrome(str + i))
            {
                max_len = curr_len;
                start = i;
            }
        }
    }
    char *new_str = malloc(max_len + 1);
    strncpy(new_str, str + start, max_len);
    new_str[max_len] = '\0';
    return new_str;
}

int main()
{
    // Example strings
    char *str1 = "Hello, world!";
    char *str2 = "Madam, I'm Adam";
    char *str3 = "racecar";

    // Reverse the strings
    char *reversed_str1 = reverse(str1);
    char *reversed_str2 = reverse(str2);
    char *reversed_str3 = reverse(str3);

    // Print the reversed strings
    printf("Original string: %s\n", str1);
    printf("Reversed string: %s\n\n", reversed_str1);
    printf("Original string: %s\n", str2);
    printf("Reversed string: %s\n\n", reversed_str2);
    printf("Original string: %s\n", str3);
    printf("Reversed string: %s\n\n", reversed_str3);

    // Check if the strings are palindromes
    int is_pal1 = is_palindrome(str1);
    int is_pal2 = is_palindrome(str2);
    int is_pal3 = is_palindrome(str3);

    // Print whether the strings are palindromes
    printf("Is \"%s\" a palindrome? %s\n\n", str1, is_pal1 ? "Yes" : "No");
    printf("Is \"%s\" a palindrome? %s\n\n", str2, is_pal2 ? "Yes" : "No");
    printf("Is \"%s\" a palindrome? %s\n\n", str3, is_pal3 ? "Yes" : "No");

    // Find the longest palindrome substrings in the strings
    char *longest_pal1 = longest_palindrome_substring(str1);
    char *longest_pal2 = longest_palindrome_substring(str2);
    char *longest_pal3 = longest_palindrome_substring(str3);

    // Print the longest palindrome substrings
    printf("Longest palindrome substring in \"%s\": %s\n\n", str1, longest_pal1);
    printf("Longest palindrome substring in \"%s\": %s\n\n", str2, longest_pal2);
    printf("Longest palindrome substring in \"%s\": %s\n\n", str3, longest_pal3);

    // Free the allocated memory
    free(reversed_str1);
    free(reversed_str2);
    free(reversed_str3);
    free(longest_pal1);
    free(longest_pal2);
    free(longest_pal3);

    return 0;
}