//Falcon2-11B DATASET v1.0 Category: Searching algorithm ; Style: decentralized
#include <stdio.h>
#include <string.h>

// Function to perform a decentralized search
int searchDecentralized(char *str, char c)
{
    // Assume not found initially
    int found = 0;

    // Convert string to an array
    char *strArray = (char *)malloc(strlen(str) + 1);
    strcpy(strArray, str);

    // Convert character to array index
    int cIndex = (int)c - (int)'a';

    // Iterate over each character in the string
    for (int i = 0; i < strlen(str); i++)
    {
        // If current character is equal to the target character
        if (strArray[i] == strArray[cIndex])
        {
            // Found the target character
            found = 1;
            break;
        }
    }

    // Free memory
    free(strArray);

    return found;
}

int main()
{
    // Test string
    char str[] = "Hello World";

    // Target character
    char c = 'l';

    // Call search function
    int found = searchDecentralized(str, c);

    // Print result
    if (found)
        printf("%c found at index %d\n", c, found);
    else
        printf("%c not found\n", c);

    return 0;
}