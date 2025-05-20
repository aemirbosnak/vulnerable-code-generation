//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int isPalindrome(char *str);
char *reverseString(char *str);

int main()
{
    char input[MAX_LENGTH];

    printf("Enter a string: ");
    scanf("%s", input);

    if (isPalindrome(input))
    {
        printf("Your string is a palindrome, my love.");
    }
    else
    {
        printf("Your string is not a palindrome, my dear.");
    }

    return 0;
}

int isPalindrome(char *str)
{
    char *reversedString = reverseString(str);
    int result = strcmp(str, reversedString);

    free(reversedString);

    return result == 0;
}

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