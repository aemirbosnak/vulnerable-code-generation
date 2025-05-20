//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20

int main()
{
    char **words = NULL;
    int numWords = 0;
    char emailText[1000] = "Dear Mr. Jones,\r\n\r\nHope this email finds you well.\r\n\r\nI am writing to you today to express my concerns about the recent spam emails I have received.";

    // Analyze email text and extract words
    char *text = emailText;
    while (text)
    {
        char word[MAX_WORD_LENGTH] = "";
        int i = 0;
        while (text && text[i] != '\0' && text[i] != '.' && text[i] != ' ' && text[i] != ',')
        {
            word[i] = text[i];
            i++;
        }
        word[i] = '\0';

        // Add word to list if it is not already there
        if (word[0] != '\0' && !wordExists(words, numWords, word))
        {
            words = realloc(words, (numWords + 1) * sizeof(char *));
            words[numWords++] = strdup(word);
        }
        text += i + 1;
    }

    // Create a spam detection score based on the number of extracted words
    int spamScore = numWords / 5;

    // Print spam score
    printf("Spam score: %d\n", spamScore);

    // Free memory
    free(words);

    return 0;
}

int wordExists(char **words, int numWords, char *word)
{
    for (int i = 0; i < numWords; i++)
    {
        if (strcmp(words[i], word) == 0)
        {
            return 1;
        }
    }

    return 0;
}