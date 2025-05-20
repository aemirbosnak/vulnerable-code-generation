//FormAI DATASET v1.0 Category: String manipulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

char *reverse(char *str);
char *capitalize(char *str);
char *titlecase(char *str);

int main()
{
    char str[MAX_LENGTH];

    printf("Enter a string of up to 100 characters: ");
    fgets(str, MAX_LENGTH, stdin);

    // Remove the newline character at the end of the string
    str[strcspn(str, "\n")] = '\0';

    printf("Original string: %s\n", str);

    // Reverse the string and print it
    char *reversed_str = reverse(str);
    printf("Reversed string: %s\n", reversed_str);

    // Capitalize the string and print it
    char *capitalized_str = capitalize(str);
    printf("Capitalized string: %s\n", capitalized_str);

    // Title case the string and print it
    char *titlecased_str = titlecase(str);
    printf("Title cased string: %s\n", titlecased_str);

    // Free the memory of the dynamically allocated strings
    free(reversed_str);
    free(capitalized_str);
    free(titlecased_str);

    return 0;
}

char *reverse(char *str)
{
    int length = strlen(str);

    // Dynamically allocate memory for the reversed string
    char *reversed_str = (char *) malloc(length + 1);

    for (int i = 0; i < length; i++)
    {
        // Copy characters from the original string to the reversed string in reverse order
        reversed_str[i] = str[length - 1 - i];
    }

    // Null-terminate the reversed string
    reversed_str[length] = '\0';

    return reversed_str;
}

char *capitalize(char *str)
{
    int length = strlen(str);

    // Dynamically allocate memory for the capitalized string
    char *capitalized_str = (char *) malloc(length + 1);

    for (int i = 0; i < length; i++)
    {
        if (i == 0 || str[i - 1] == ' ')
        {
            // If the current character is the first character or follows a space character,
            // capitalize it and copy it to the new string
            capitalized_str[i] = toupper(str[i]);
        }
        else
        {
            // Otherwise, copy the character to the new string as is
            capitalized_str[i] = str[i];
        }
    }

    // Null-terminate the capitalized string
    capitalized_str[length] = '\0';

    return capitalized_str;
}

char *titlecase(char *str)
{
    int length = strlen(str);

    // Dynamically allocate memory for the titlecased string
    char *titlecased_str = (char *) malloc(length + 1);

    for (int i = 0; i < length; i++)
    {
        if (i == 0 || str[i - 1] == ' ')
        {
            // If the current character is the first character or follows a space character,
            // capitalize it and copy it to the new string
            titlecased_str[i] = toupper(str[i]);
        }
        else
        {
            // Otherwise, copy the character to the new string as is
            titlecased_str[i] = str[i];
        }
    }

    // Null-terminate the titlecased string
    titlecased_str[length] = '\0';

    return titlecased_str;
}