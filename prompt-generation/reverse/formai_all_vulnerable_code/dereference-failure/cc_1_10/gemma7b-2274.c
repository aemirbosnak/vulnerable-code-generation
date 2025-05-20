//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000

typedef struct Word
{
    char *word;
    int frequency;
} Word;

Word *word_create(char *word, int frequency)
{
    Word *w = malloc(sizeof(Word));
    w->word = strdup(word);
    w->frequency = frequency;
    return w;
}

int main()
{
    char text[] = "This is a sample text with many words. The words are repeated several times. Some words are unique, while others are not.";

    Word **words = NULL;
    int word_count = 0;

    char *word_ptr = strtok(text, " ");

    while (word_ptr)
    {
        int found = 0;
        for (int i = 0; i < word_count; i++)
        {
            if (strcmp(word_ptr, words[i]->word) == 0)
            {
                words[i]->frequency++;
                found = 1;
            }
        }

        if (!found)
        {
            words = realloc(words, (word_count + 1) * sizeof(Word));
            words[word_count] = word_create(word_ptr, 1);
            word_count++;
        }
        word_ptr = strtok(NULL, " ");
    }

    for (int i = 0; i < word_count; i++)
    {
        printf("%s: %d\n", words[i]->word, words[i]->frequency);
    }

    free(words);

    return 0;
}