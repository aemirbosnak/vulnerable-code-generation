//FormAI DATASET v1.0 Category: String manipulation ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function Declarations //
void I_Love_You(char *);

// Main Function //
int main()
{
    // Define the C String variable to hold the input text //
    char inputText[256];
    
    // Get the input text from the user //
    printf("Enter something you love: ");
    fgets(inputText, 256, stdin);

    // Call the I_Love_You() function //
    I_Love_You(inputText);

    // Exit the program //
    return 0;
}

// Function Definitions //
void I_Love_You(char *text)
{
    // Define the variables //
    int textLength = strlen(text);
    char *pText = malloc(textLength + 1);  // Allocate memory for the new string
    char *pStart = text;                   // Pointer to the start of the string
    char *pEnd = text + textLength - 1;    // Pointer to the end of the string

    // Copy the input text to pText while swapping its case //
    int i;
    for (i = 0; i < textLength; i++)
    {
        if (*pStart >= 'a' && *pStart <= 'z')   // If the character is lowercase
            *(pText + i) = *pStart - 32;         // Convert it to uppercase for love
        else if (*pStart >= 'A' && *pStart <= 'Z')  // If the character is uppercase
            *(pText + i) = *pStart + 32;            // Convert it to lowercase for you
        else
            *(pText + i) = *pStart;      // If the character is not a letter, keep it the same
        
        pStart++;    // Move the pointer to the next character
    }

    // Reverse the pText string //
    while (pStart <= pEnd)
    {
        char temp = *pStart;
        *pStart = *pEnd;
        *pEnd = temp;

        pStart++;
        pEnd--;
    }

    // Print the final message //
    printf("I LOVE %s WITH ALL MY HEART!\n", pText);

    // Free the dynamically allocated memory //
    free(pText);
}