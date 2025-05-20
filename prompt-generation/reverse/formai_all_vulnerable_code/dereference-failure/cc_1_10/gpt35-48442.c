//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// function signature
char* str_to_lower(char*);
int is_palindrome(char*);

int main()
{
    char user_input[100];

    printf("Please enter a string to check if it is a palindrome: ");
    fgets(user_input, 100, stdin);

    // remove the newline character
    user_input[strcspn(user_input, "\n")] = 0;

    // convert the string to lowercase
    char* lower_string = str_to_lower(user_input);

    if (is_palindrome(lower_string))
    {
        printf("The string is a palindrome.\n");
    }
    else
    {
        printf("The string is not a palindrome.\n");
    }

    // free the memory allocated to the lower_string pointer
    free(lower_string);

    return 0;
}

// function to convert a string to lowercase
char* str_to_lower(char* str)
{
    char* lower_string = strdup(str);
    size_t len = strlen(lower_string);
    for (size_t i = 0; i < len; i++)
    {
        lower_string[i] = tolower(lower_string[i]);
    }
    return lower_string;
}

// function to check if a string is a palindrome
int is_palindrome(char* str)
{
    size_t len = strlen(str);
    for (size_t i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i - 1])
        {
            return 0;
        }
    }
    return 1;
}