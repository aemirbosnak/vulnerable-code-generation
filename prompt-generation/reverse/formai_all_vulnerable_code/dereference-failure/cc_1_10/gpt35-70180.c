//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to check if the character is not alphanumeric
int isCharacterInvalid(char c)
{
    //ASCII value of a lowercase letter is between 97 to 122
    //ASCII value of an uppercase letter is between 65 to 90
    //ASCII value of a digit is between 48 to 57
    if (!((c >= 97 && c <= 122) || (c >= 65 && c <= 90) || (c >= 48 && c <= 57)))
    {
        return 1; //Returns true if the character is not alphanumeric
    }
    return 0; //Returns false if the character is alphanumeric
}

//Function to sanitize the given URL by removing any invalid characters
char *sanitizeURL(char *url)
{
    int i, j;
    char *sanitizedUrl = (char *)malloc(strlen(url) + 1); //Dynamically allocate memory for sanitized URL

    j = 0; //Initial index of sanitized URL

    for (i = 0; i < strlen(url); i++)
    {
        if (!isCharacterInvalid(url[i])) //Checks if the character is alphanumeric
        {
            sanitizedUrl[j++] = url[i]; //Adds the character to the sanitized URL
        }
    }

    sanitizedUrl[j] = '\0'; //Adds null character at the end of the sanitized URL

    return sanitizedUrl;
}

int main()
{
    char url[1000];
    printf("Enter the URL: ");
    scanf("%s", url);

    char *sanitizedUrl = sanitizeURL(url);
    printf("The sanitized URL is: %s", sanitizedUrl);

    free(sanitizedUrl); //Frees the memory allocated for sanitized URL

    return 0;
}