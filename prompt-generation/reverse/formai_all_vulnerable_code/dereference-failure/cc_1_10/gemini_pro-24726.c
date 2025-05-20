//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the number of words in a string
int countWords(char *str)
{
    int count = 0;
    int i = 0;

    while (str[i] != '\0')
    {
        // If the current character is a space, it means we have encountered a word boundary
        if (str[i] == ' ')
        {
            // Increment the word count
            count++;
        }

        // Move to the next character
        i++;
    }

    // If the string doesn't end with a space, we need to increment the word count one last time
    if (str[i - 1] != ' ')
    {
        count++;
    }

    return count;
}

// Function to reverse a string
void reverseString(char *str)
{
    int length = strlen(str);

    for (int i = 0; i < length / 2; i++)
    {
        // Swap the characters at positions i and length - i - 1
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

// Function to print a string in a shocked style
void printShocked(char *str)
{
    int length = strlen(str);

    // Add exclamation marks to the beginning and end of the string
    str[0] = '!';
    str[length] = '!';

    // Convert the string to uppercase
    for (int i = 0; i < length; i++)
    {
        str[i] = toupper(str[i]);
    }

    // Print the shocked string
    printf("%s\n", str);
}

int main()
{
    // Get the input string from the user
    char str[100];
    printf("Enter a string: ");
    gets(str);

    // Count the number of words in the string
    int wordCount = countWords(str);

    // Reverse the string
    reverseString(str);

    // Print the string in a shocked style
    printShocked(str);

    // Print the number of words in the string
    printf("Word count: %d\n", wordCount);

    return 0;
}