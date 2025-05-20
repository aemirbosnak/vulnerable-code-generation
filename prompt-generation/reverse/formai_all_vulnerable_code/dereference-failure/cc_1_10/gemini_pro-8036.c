//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to summarize a text
char* summarize(char* text)
{
    // Check if the text is empty
    if (text == NULL || *text == '\0')
    {
        return NULL;
    }

    // Allocate memory for the summary
    int summary_length = strlen(text) / 5;
    char* summary = malloc(summary_length + 1);
    if (summary == NULL)
    {
        return NULL;
    }

    // Initialize the summary to empty
    *summary = '\0';

    // Tokenize the text
    char* tokens = strtok(text, " ");

    // Add the first few tokens to the summary
    int num_tokens = 0;
    while (num_tokens < summary_length && tokens != NULL)
    {
        // Append the token to the summary
        strcat(summary, tokens);
        strcat(summary, " ");

        // Get the next token
        tokens = strtok(NULL, " ");
        num_tokens++;
    }

    // Remove the trailing space from the summary
    char* last_char = summary + strlen(summary) - 1;
    if (*last_char == ' ')
    {
        *last_char = '\0';
    }

    // Return the summary
    return summary;
}

// Main function
int main()
{
    // Get the text from the user
    char text[1000];
    printf("Enter the text to summarize: ");
    fgets(text, 1000, stdin);

    // Summarize the text
    char* summary = summarize(text);

    // Print the summary
    printf("Summary: %s\n", summary);

    // Free the memory allocated for the summary
    free(summary);

    return 0;
}