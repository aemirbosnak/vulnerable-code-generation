//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 255

int main()
{
    char text[MAX_SENTENCE_LENGTH];
    char words[MAX_WORDS][MAX_SENTENCE_LENGTH];

    // Get the text from the user
    printf("Enter text: ");
    fgets(text, MAX_SENTENCE_LENGTH, stdin);

    // Split the text into words and store them in the words array
    int numWords = splitTextIntoWords(text, words);

    // Check if the text contains spam words
    int isSpam = checkForSpamWords(words, numWords);

    // Display the results
    if (isSpam)
    {
        printf("Your text contains spam words.\n");
    }
    else
    {
        printf("Your text does not contain spam words.\n");
    }

    return 0;
}

int splitTextIntoWords(char *text, char **words)
{
    int numWords = 0;
    char *word = strtok(text, " ");

    while (word)
    {
        strcpy(words[numWords], word);
        numWords++;
        word = strtok(NULL, " ");
    }

    return numWords;
}

int checkForSpamWords(char **words, int numWords)
{
    char *spamWords[] = {"spam", "junk", "scam", "lottery", "miracle"};
    int numSpamWords = 5;

    for (int i = 0; i < numWords; i++)
    {
        for (int j = 0; j < numSpamWords; j++)
        {
            if (strcmp(words[i], spamWords[j]) == 0)
            {
                return 1;
            }
        }
    }

    return 0;
}