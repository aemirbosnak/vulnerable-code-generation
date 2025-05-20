//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the character is a hexadecimal digit
int is_hex_digit(char c)
{
    return ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'));
}

// Function to sanitize the URL
char* sanitize_url(char* url)
{
    int url_len = strlen(url);
    char* sanitized_url = (char*)malloc((url_len + 1) * sizeof(char));

    // Initialize variables to keep track of string positions
    int i = 0; // current position in original url
    int j = 0; // current position in sanitized url

    while (i < url_len)
    {
        if (url[i] == '%')
        {
            if (is_hex_digit(url[i + 1]) && is_hex_digit(url[i + 2]))
            {
                // Copy the hex code into the sanitized url
                sanitized_url[j] = url[i];
                sanitized_url[j + 1] = url[i + 1];
                sanitized_url[j + 2] = url[i + 2];
                i += 3; // Jump over the hex code in the original url
                j += 3; // Update the current position in the sanitized url
            }
            else
            {
                // Malformed hex code detected, replace it with "_"
                sanitized_url[j] = '_';
                i++; // Jump over the "%"
                j++; // Update the current position in the sanitized url
            }
        }
        else
        {
            // Just copy the character into the sanitized url
            sanitized_url[j] = url[i];
            i++; // Move on to the next character in the original url
            j++; // And the next position in the sanitized url
        }
    }

    // Add the null terminator to the sanitized url string
    sanitized_url[j] = '\0';

    return sanitized_url;
}

int main()
{
    char url[] = "https://example.com/path/to/file%20name.html?search=hello%26world";
    char* sanitized_url = sanitize_url(url);

    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);

    return 0;
}