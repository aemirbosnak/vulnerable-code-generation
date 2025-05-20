//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
char *reverseString(char *str)
{
    int length = strlen(str);
    char *reversedString = malloc(length + 1);
    int i, j;
    for (i = 0, j = length - 1; i < length; i++, j--)
    {
        reversedString[i] = str[j];
    }
    reversedString[length] = '\0';
    return reversedString;
}

// Function to remove duplicate characters from a string
char *removeDuplicates(char *str)
{
    int length = strlen(str);
    char *newString = malloc(length + 1);
    int i, j, k = 0;
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (str[i] == str[j])
            {
                break;
            }
        }
        if (j == i)
        {
            newString[k++] = str[i];
        }
    }
    newString[k] = '\0';
    return newString;
}

// Function to count the number of vowels in a string
int countVowels(char *str)
{
    int length = strlen(str);
    int vowelCount = 0;
    int i;
    for (i = 0; i < length; i++)
    {
        char c = str[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        {
            vowelCount++;
        }
    }
    return vowelCount;
}

// Function to find the longest palindrome in a string
char *findLongestPalindrome(char *str)
{
    int length = strlen(str);
    int maxLength = 0;
    int start = 0;
    int end = 0;
    int i, j;
    for (i = 0; i < length; i++)
    {
        for (j = i + 1; j < length; j++)
        {
            int k;
            for (k = 0; k < (j - i + 1) / 2; k++)
            {
                if (str[i + k] != str[j - k])
                {
                    break;
                }
            }
            if (k == (j - i + 1) / 2 && j - i + 1 > maxLength)
            {
                maxLength = j - i + 1;
                start = i;
                end = j;
            }
        }
    }
    char *longestPalindrome = malloc(maxLength + 1);
    strncpy(longestPalindrome, str + start, maxLength);
    longestPalindrome[maxLength] = '\0';
    return longestPalindrome;
}

// Driver code to test the string manipulation functions
int main()
{
    char str[] = "Hello, world!";
    printf("Original string: %s\n", str);

    char *reversedString = reverseString(str);
    printf("Reversed string: %s\n", reversedString);
    free(reversedString);

    char *newString = removeDuplicates(str);
    printf("String with duplicate characters removed: %s\n", newString);
    free(newString);

    int vowelCount = countVowels(str);
    printf("Number of vowels in the string: %d\n", vowelCount);

    char *longestPalindrome = findLongestPalindrome(str);
    printf("Longest palindrome in the string: %s\n", longestPalindrome);
    free(longestPalindrome);

    return 0;
}