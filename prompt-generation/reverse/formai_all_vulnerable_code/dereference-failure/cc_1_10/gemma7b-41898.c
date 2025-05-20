//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char text[MAX_BUFFER_SIZE];
    char summary[MAX_BUFFER_SIZE];
    int text_length, summary_length, i;

    printf("Enter text: ");
    fgets(text, MAX_BUFFER_SIZE, stdin);

    text_length = strlen(text);

    if (text_length > MAX_BUFFER_SIZE - 1)
    {
        printf("Error: Text exceeds buffer size.\n");
        return 1;
    }

    summary_length = text_length / 3;
    summary[0] = '\0';

    for (i = 0; i < summary_length; i++)
    {
        int frequency = 0;
        char word[20];

        word[0] = '\0';

        // Iterate over the text and count word occurrences
        for (int j = 0; j < text_length; j++)
        {
            if (strcmp(word, text[j] + "") == 0)
            {
                frequency++;
            }

            if (frequency > 1)
            {
                sprintf(word, "%s (%d)", text[j], frequency);
            }
            else
            {
                sprintf(word, "%s", text[j]);
            }

            strcat(summary, word);
            strcat(summary, " ");
        }

        summary[summary_length - 1] = '\0';
    }

    printf("Summary: \n");
    printf("%s\n", summary);

    return 0;
}