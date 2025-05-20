//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: synchronous
#include <stdio.h>
#include <string.h>

char **text_summarizer(char **text)
{
    int text_length = 0;
    char **summary = NULL;

    // Calculate the text length
    for (int i = 0; text[i] != NULL; i++)
    {
        text_length++;
    }

    // Allocate memory for the summary
    summary = malloc(text_length);

    // Summarize the text
    int summary_length = 0;
    for (int i = 0; text[i] != NULL; i++)
    {
        if (summary_length > text_length / 5)
        {
            break;
        }

        if (text[i] != ' ')
        {
            summary[summary_length++] = text[i];
        }
    }

    return summary;
}

int main()
{
    char **text = NULL;
    text = malloc(100);

    // Get the text to summarize
    printf("Enter text: ");
    gets(text);

    // Summarize the text
    char **summary = text_summarizer(text);

    // Print the summary
    printf("Summary: \n");
    printf("%s", summary);

    return 0;
}