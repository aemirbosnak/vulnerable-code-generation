//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 200

int main()
{
    char text[MAX_SENTENCE_LENGTH];
    char words[MAX_WORDS][MAX_SENTENCE_LENGTH];

    printf("Enter text: ");
    fgets(text, MAX_SENTENCE_LENGTH, stdin);

    // Split text into words
    int num_words = split_text(text, words);

    // Check for spam words
    int is_spam = check_spam_words(words, num_words);

    // Display result
    if (is_spam)
    {
        printf("Text is spam.\n");
    }
    else
    {
        printf("Text is not spam.\n");
    }

    return 0;
}

int split_text(char *text, char **words)
{
    char *p = text;
    int i = 0;
    int num_words = 0;

    while (p)
    {
        char *word = malloc(MAX_SENTENCE_LENGTH);
        word = strtok(p, " ");

        if (word)
        {
            strcpy(words[num_words], word);
            num_words++;
        }

        p = strtok(NULL, " ");
    }

    return num_words;
}

int check_spam_words(char **words, int num_words)
{
    char *spam_words[] = {"buy", "free", "lottery", "miracle", "prize"};
    int i = 0;

    for (i = 0; i < num_words; i++)
    {
        int j = 0;
        for (j = 0; j < 5; j++)
        {
            if (strcmp(words[i], spam_words[j]) == 0)
            {
                return 1;
            }
        }
    }

    return 0;
}