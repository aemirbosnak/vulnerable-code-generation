//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: dynamic
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100

typedef struct Word
{
    char *word;
    int frequency;
} Word;

Word words[MAX_WORDS];

void analyze_text(char *text)
{
    char *word_ptr = text;
    int i = 0;

    while (word_ptr)
    {
        char word[20];
        int word_length = 0;

        word_ptr = word_ptr - 1;

        while (word_ptr >= text && word_ptr[0] != ' ')
        {
            word[word_length++] = word_ptr[0];
            word_ptr--;
        }

        word[word_length] = '\0';

        for (i = 0; i < MAX_WORDS; i++)
        {
            if (strcmp(words[i].word, word) == 0)
            {
                words[i].frequency++;
                break;
            }
        }

        if (i == MAX_WORDS)
        {
            words[MAX_WORDS - 1].word = strdup(word);
            words[MAX_WORDS - 1].frequency = 1;
        }

        word_ptr++;
    }
}

int main()
{
    char text[] = "This is a sample text with many words. Some words are repeated several times. The frequency of each word is counted and stored in a data structure. This text contains a lot of spam words, such as 'free', 'offer', and 'lottery'.";

    analyze_text(text);

    for (int i = 0; i < MAX_WORDS; i++)
    {
        if (words[i].frequency > 1)
        {
            printf("%s: %d\n", words[i].word, words[i].frequency);
        }
    }

    return 0;
}