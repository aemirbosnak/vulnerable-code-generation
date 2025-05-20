//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
char *reverse(char *str)
{
    int len = strlen(str);
    char *reversed = malloc(len + 1);
    int i, j;
    for (i = 0, j = len - 1; i < len; i++, j--)
        reversed[i] = str[j];
    reversed[len] = '\0';
    return reversed;
}

// Function to find the length of a string
int length(char *str)
{
    int count = 0;
    while (*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}

// Function to concatenate two strings
char *concatenate(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char *concatenated = malloc(len1 + len2 + 1);
    strcpy(concatenated, str1);
    strcpy(concatenated + len1, str2);
    concatenated[len1 + len2] = '\0';
    return concatenated;
}

// Function to compare two strings
int compare(char *str1, char *str2)
{
    int result = strcmp(str1, str2);
    if (result == 0)
        return 0;
    else if (result > 0)
        return 1;
    else
        return -1;
}

// Function to find the index of a character in a string
int find_index(char *str, char ch)
{
    int i = 0;
    while (*str != '\0')
    {
        if (*str == ch)
            return i;
        str++;
        i++;
    }
    return -1;
}

// Function to replace a character in a string
char *replace(char *str, char ch1, char ch2)
{
    int len = strlen(str);
    char *replaced = malloc(len + 1);
    int i;
    for (i = 0; i < len; i++)
    {
        if (str[i] == ch1)
            replaced[i] = ch2;
        else
            replaced[i] = str[i];
    }
    replaced[len] = '\0';
    return replaced;
}

int main()
{
    // String manipulation examples
    char *str = "Hello World!";
    printf("Original string: %s\n", str);
    printf("Reversed string: %s\n", reverse(str));
    printf("Length of the string: %d\n", length(str));
    printf("Concatenated string: %s\n", concatenate(str, " This is a concatenated string"));
    printf("Comparison result: %d\n", compare(str, "Hello World!"));
    printf("Index of 'l' in the string: %d\n", find_index(str, 'l'));
    printf("Replaced string: %s\n", replace(str, 'o', 'a'));

    return 0;
}