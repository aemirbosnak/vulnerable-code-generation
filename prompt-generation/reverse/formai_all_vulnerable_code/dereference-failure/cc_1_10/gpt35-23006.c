//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a maximum character limit for URL input
#define MAX_INPUT_SIZE 1024

// Define a maximum character limit for sanitized URL output
#define MAX_OUTPUT_SIZE 2048

// Define a list of characters that are allowed in a URL
const char ALLOWED_CHARS[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-._~:/?#[]@!$&'()*+,;=%";

// Function to check if the provided character is allowed in a URL
int is_allowed_char(char c)
{
    int len = strlen(ALLOWED_CHARS);
    for (int i = 0; i < len; i++)
    {
        if (ALLOWED_CHARS[i] == c)
        {
            return 1;
        }
    }

    return 0;
}

// Function to sanitize a URL input and return sanitized output
char* sanitize_url(char* url)
{
    // Allocate memory for the sanitized URL output
    char* sanitized_url = (char*) malloc(MAX_OUTPUT_SIZE * sizeof(char));

    // Keep track of the index for the sanitized URL output
    int output_index = 0;

    // Loop through each character in the URL input
    int len = strlen(url);
    for (int i = 0; i < len; i++)
    {
        char c = url[i];

        // Check if character is allowed in a URL
        if (is_allowed_char(c))
        {
            // Add the allowed character to the sanitized URL output
            sanitized_url[output_index] = c;
            output_index++;
        }
        else
        {
            // Convert the character to its corresponding hexadecimal ASCII value
            char hex_code[4];
            sprintf(hex_code, "%%%02X", c);

            // Add the hexadecimal ASCII value to the sanitized URL output
            int j = 0;
            while (hex_code[j] != '\0')
            {
                sanitized_url[output_index] = hex_code[j];
                output_index++;
                j++;
            }
        }

        // Check if the maximum output size has been reached
        if (output_index >= MAX_OUTPUT_SIZE)
        {
            // Free the memory for the sanitized URL output and return NULL
            free(sanitized_url);
            return NULL;
        }
    }

    // Add a null terminator to the end of the sanitized URL output
    sanitized_url[output_index] = '\0';

    // Return the sanitized URL output
    return sanitized_url;
}

int main()
{
    // Allocate memory for the URL input
    char* url_input = (char*) malloc(MAX_INPUT_SIZE * sizeof(char));

    // Get input from the user
    printf("Enter a URL to sanitize: ");
    fgets(url_input, MAX_INPUT_SIZE, stdin);

    // Sanitize the URL input
    char* sanitized_url = sanitize_url(url_input);

    // Check if the sanitized URL output is NULL
    if (sanitized_url == NULL)
    {
        printf("The sanitized URL is too long.\n");
    }
    else
    {
        printf("The sanitized URL is: %s\n", sanitized_url);
        free(sanitized_url);
    }

    // Free the memory for the URL input
    free(url_input);

    return 0;
}