//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: accurate
// This program demonstrates user input sanitation in C
#include<stdio.h>
#include<string.h>

// Function to remove leading and trailing whitespace characters
char *trimWhiteSpace(char *str)
{
    int i, j; 
    for (i = 0; str[i] == ' '; i++); // Remove leading spaces
    for (j = strlen(str) - 1; (j >= 0) && (str[j] == ' '); j--); // Remove trailing spaces
    str[j+1] = '\0'; // Null terminate the string 
    return str+i; // Return the trimmed string 
}

// Function to check if a string contains non-alphanumeric characters
int hasSpecialChar(char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (!((str[i] >= 'a' && str[i] <='z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9')))
        {
            return 1; // String contains special character
        }
    }
    return 0; // String contains only alphanumeric characters
}

// Function to sanitize the user input
char *sanitizeInput(char *input)
{
    // Trim leading and trailing whitespace characters
    input = trimWhiteSpace(input);

    // Remove non-alphanumeric characters
    if (hasSpecialChar(input))
    {
        int i, j; 
        for (i = 0; input[i] != '\0'; i++)
        {
            if ((input[i] >= 'a' && input[i] <='z') || (input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= '0' && input[i] <= '9'))
            {
                input[j++] = input[i]; // Copy only alphanumeric characters to a new location
            }
        }
        input[j] = '\0'; // Null terminate the sanitized string
    }

    return input;
}

int main()
{
    char input[100];

    printf("Enter a string: ");
    fgets(input, 100, stdin); // Get user input

    printf("Sanitized input: %s", sanitizeInput(input)); // Sanitize and print input

    return 0;
}