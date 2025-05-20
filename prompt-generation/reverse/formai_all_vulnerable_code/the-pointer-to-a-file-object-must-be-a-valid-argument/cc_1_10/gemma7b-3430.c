//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char text[MAX_BUFFER_SIZE];
    char summary[MAX_BUFFER_SIZE];
    int text_length, summary_length, i, j;
    FILE *fp;

    // Open the text file
    fp = fopen("text.txt", "r");

    // Read the text file
    text_length = read_text(text, fp);

    // Summarize the text
    summary_length = summarize(text, summary, text_length);

    // Print the summary
    printf("Summary:\n");
    for (i = 0; i < summary_length; i++)
    {
        printf("%c", summary[i]);
    }

    // Close the text file
    fclose(fp);

    return 0;
}

int read_text(char *text, FILE *fp)
{
    int text_length = 0;

    // Read the text file line by line
    char line[MAX_BUFFER_SIZE];
    while (fgets(line, MAX_BUFFER_SIZE, fp) != NULL)
    {
        // Append the line to the text
        strcat(text, line);

        // Increment the text length
        text_length++;
    }

    return text_length;
}

int summarize(char *text, char *summary, int text_length)
{
    int summary_length = 0;

    // Create a summary of the text
    for (int i = 0; i < text_length; i++)
    {
        // Check if the character is a punctuation mark
        if (ispunct(text[i]))
        {
            // If the summary length is less than the maximum length, add the character to the summary
            if (summary_length < MAX_BUFFER_SIZE - 1)
            {
                summary[summary_length++] = text[i];
            }
        }
    }

    return summary_length;
}