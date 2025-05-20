//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **text_summarizer(char **text, int text_size, int summary_size)
{
    int i, j, k, count = 0, min_size = text_size / summary_size;
    char **summary = malloc(summary_size * sizeof(char *));
    summary[0] = malloc(min_size * sizeof(char));

    for (i = 0; i < text_size; i++)
    {
        for (j = 0; j < summary_size; j++)
        {
            if (strcmp(text[i], summary[j]) == 0)
            {
                count++;
            }
        }

        if (count == 0)
        {
            strcpy(summary[k], text[i]);
            k++;
        }

        count = 0;
    }

    return summary;
}

int main()
{
    char **text = malloc(10 * sizeof(char *));
    text[0] = "This is a sample text.";
    text[1] = "It is a long text.";
    text[2] = "It has many sentences.";
    text[3] = "This text is for summarizing.";

    int text_size = 4;
    int summary_size = 2;

    char **summary = text_summarizer(text, text_size, summary_size);

    printf("%s\n", summary[0]);
    printf("%s\n", summary[1]);

    free(text);
    free(summary);

    return 0;
}