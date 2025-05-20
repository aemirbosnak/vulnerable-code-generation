//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to check if the character is a special character
int isSpecialCharacter(char c)
{
    if(c=='-' || c=='_' || c=='.' || c=='~')
        return 1; // Return true if special character found
    else
        return 0; // Return false if not a special character
}

// Function to convert a character to hexadecimal
int charToHex(char c)
{
    return c>='0' && c<='9' ? (int)(c-'0') : (int)(c-'a'+10);
}

// Function to convert hexadecimal to decimal
int hexToDec(char c1, char c2)
{
    return charToHex(c1)*16 + charToHex(c2);
}

// Function to sanitize URL
char* sanitizeURL(char* url)
{
    int len = strlen(url);
    char* sanitized = (char*)malloc(sizeof(char)*(len+1));
    int count = 0;

    for(int i=0; i<len; i++)
    {
        if(isSpecialCharacter(url[i]))
        {
            sanitized[count++] = url[i]; // Set the special character as it is
        }
        else if(url[i] == '%')
        {
            // If the current character is %, then it must be followed by two hexadecimal numbers
            int dec = hexToDec(url[i+1], url[i+2]);
            sanitized[count++] = dec; // Convert hexadecimal to decimal and add to result
            i += 2; // Increment the index to skip the next two characters
        }
        else
        {
            sanitized[count++] = url[i]; // Add the character to result
        }
    }

    sanitized[count] = '\0'; // Add null character at the end

    return sanitized; // Return the sanitized URL
}

int main()
{
    char url[100];

    printf("Enter the URL to sanitize: ");
    fgets(url, 100, stdin);

    int len = strlen(url);
    if(url[len-1] == '\n')
        url[len-1] = '\0'; // Remove newline character

    char* sanitizedURL = sanitizeURL(url);

    printf("Sanitized URL: %s\n", sanitizedURL);

    free(sanitizedURL);

    return 0;
}