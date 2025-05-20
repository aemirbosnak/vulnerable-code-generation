//FormAI DATASET v1.0 Category: Word Count Tool ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int word_count(char *str)
{
    int count = 0;
    int i = 0;

    while (str[i] != '\0')
    {
        // If current character is not whitespace
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
        {
            // Increment count for first character of word
            count++;

            // Loop until the next whitespace character
            while (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i] != '\0')
            {
                i++;
            }
        }
        else
        {
            i++;
        }
    }

    return count;
}

int main()
{
    char *str = malloc(sizeof(char) * 1000);

    // Prompt the user to enter a string
    printf("Enter a string: ");

    // Read the user's input
    fgets(str, 1000, stdin);

    // Remove the newline character added by fgets
    str[strcspn(str, "\n")] = '\0';

    // Count the number of words in the user's input
    int count = word_count(str);

    // Display the result to the user
    printf("The string \"%s\" has %d words.\n", str, count);

    return 0;
}