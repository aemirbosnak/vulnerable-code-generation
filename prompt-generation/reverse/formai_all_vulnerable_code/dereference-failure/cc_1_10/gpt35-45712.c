//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a given string is a palindrome
int isPalindrome(char *str)
{
    int left = 0;
    int right = strlen(str) - 1;

    // Traverse the string from both ends until they meet at the middle
    while (right > left)
    {
        // Ignore spaces, punctuations and special characters
        while (!isalpha(str[left]))
        {
            left++;
        }
        while (!isalpha(str[right]))
        {
            right--;
        }

        // Check if the characters at these positions are equal
        if (tolower(str[left]) != tolower(str[right]))
        {
            return 0; // not a palindrome
        }

        left++;
        right--;
    }
    return 1; // palindrome
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);

    if (isPalindrome(str))
    {
        printf("%s is a palindrome.\n", str);
    }
    else
    {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}