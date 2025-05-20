//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* This program takes a string and checks if it is a palindrome */
/* A palindrome is a string that reads the same forwards and backwards */

/* This function removes all non-alphabetic characters from the input string */
char* clean_string(char* str)
{
    int len = strlen(str);
    char* new_str = malloc(len + 1);
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        if (isalpha(str[i]))
        {
            new_str[j] = tolower(str[i]);
            j++;
        }
    }
    new_str[j] = '\0'; // Add null terminating character to end of string
    return new_str;
}

/* This function reverses the input string */
char* reverse_string(char* str)
{
    int len = strlen(str);
    char* new_str = malloc(len + 1);
    int j = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        new_str[j] = str[i];
        j++;
    }
    new_str[j] = '\0'; // Add null terminating character to end of string
    return new_str;
}

int main()
{
    char input[100];
    printf("Enter a string: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character at end of input string
    char* clean_input = clean_string(input);
    char* reversed_input = reverse_string(clean_input);

    if (strcmp(clean_input, reversed_input) == 0)
    {
        printf("The input string is a palindrome.\n");
    }
    else
    {
        printf("The input string is not a palindrome.\n");
    }

    free(clean_input);
    free(reversed_input);

    return 0;
}