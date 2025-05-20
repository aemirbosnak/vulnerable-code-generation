//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    char *pBuffer = buffer;
    int i = 0;
    int textLength = 0;

    printf("You will now witness the shocking text summarizer!\n\n");

    // Gather text from the user
    printf("Please paste the text you want me to summarize: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Calculate the length of the text
    while (buffer[i] != '\0')
    {
        i++;
        textLength++;
    }

    // Allocate memory for the summary
    char *summary = malloc(textLength);

    // Summarize the text
    i = 0;
    while (buffer[i] != '\0')
    {
        // Check if the character is a vowel or a punctuation mark
        if (buffer[i] >= 'a' && buffer[i] <= 'z')
        {
            // Copy the character to the summary
            summary[i] = buffer[i];
        }
        else
        {
            // Skip the character
            i++;
        }
    }

    // Print the summary
    printf("Here is your summarized text: \n\n");
    printf("%s", summary);

    // Free the memory allocated for the summary
    free(summary);

    return 0;
}