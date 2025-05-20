//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to sanitize user input
void sanitize(char *input)
{
    int i, j = 0;
    char temp[strlen(input)];

    // Loop through the input
    for (i = 0; i < strlen(input); i++)
    {
        // If the character is a space or a tab
        if (input[i] == ' ' || input[i] == '\t')
        {
            // Do nothing
        }
        // If the character is a newline character
        else if (input[i] == '\n')
        {
            // Replace it with the null terminator
            temp[j] = '\0';
            break;
        }
        // If the character is a letter or a number
        else if (isalnum(input[i]))
        {
            // Convert it to lowercase and add it to the temporary string
            temp[j] = tolower(input[i]);
            j++;
        }
    }

    // Copy the sanitized input back to the original string
    strcpy(input, temp);
}

int main()
{
    char input[100];

    printf("Enter your input: ");
    fgets(input, 100, stdin);

    // Sanitize the input
    sanitize(input);

    // Print the sanitized input
    printf("Sanitized input: %s\n", input);

    return 0;
}