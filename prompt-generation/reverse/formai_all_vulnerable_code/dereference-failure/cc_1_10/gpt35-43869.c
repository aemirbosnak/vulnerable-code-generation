//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

// Function to remove the spaces and punctuation from a given string
void removeSpacesAndPunctuations(char str[])
{
    int i = 0, j = 0;
    while (str[i])
    {
        if (!isspace(str[i]) && !ispunct(str[i]))
            str[j++] = tolower(str[i]);
        i++;
    }
    str[j] = '\0';
}

// Recursive function to check if a given string is palindrome
int isPalindrome(char str[], int start, int end)
{
    if (start == end)
        return 1;
    if (str[start] != str[end])
        return 0;
    if (start < end + 1)
        return isPalindrome(str, start + 1, end -1);
    return 1;
}

// Function to check if a given string is palindrome
int checkPalindrome(char str[])
{
    int start = 0, end = strlen(str) -1;
    return isPalindrome(str, start, end);
}

int main()
{
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);

    removeSpacesAndPunctuations(str);

    if (checkPalindrome(str))
        printf("The string entered is a palindrome");
    else
        printf("The string entered is not a palindrome");

    return 0;
}