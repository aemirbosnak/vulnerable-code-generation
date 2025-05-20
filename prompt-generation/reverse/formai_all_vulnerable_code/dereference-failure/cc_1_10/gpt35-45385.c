//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: enthusiastic
/* Woohoo! Welcome to the awesome User Input sanitizer program! 
 * We are going to make sure no harmful code or characters enter our system.
 * Let's get this party started! */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Declaration of functions*/
void sanitizeInput(char input[]);

int main()
{
    char input[100]; // Let's store the user input in a variable
    
    printf("Welcome to our awesome User Input Sanitizer!\n");
    printf("Please enter a string (max 100 characters):\n");
    fgets(input, sizeof(input), stdin); // Get the user input

    sanitizeInput(input); // We will now sanitize the input

    printf("\nYour sanitized string is: %s\n", input);

    return 0;
}

/* Definition of the sanitizeInput function */
void sanitizeInput(char input[])
{
    int i, j;
    int is_numeric = 0;
    int len = strlen(input);

    for (i = 0; i < len; i++)
    {
        if (input[i] == '<' || input[i] == '>') // Remove < and >
        {
            input[i] = ' ';
        }
        else if (input[i] == '&' || input[i] == '\'') // Remove & and '
        {
            input[i] = ' ';
        }
        else if (isalnum(input[i])) // Check if it is alphanumeric
        {
            is_numeric = isdigit(input[i]); // Check if it's a digit
            input[j++] = is_numeric ? input[i] : tolower(input[i]); // Convert to lower case
        }
        else
        {
            input[i] = ' ';
        }
    }
    input[j] = '\0'; // Terminate the string
}