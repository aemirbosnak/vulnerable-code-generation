//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 1024

char **words = NULL;

void initialize_word_list()
{
    words = malloc(MAX_WORDS * sizeof(char *));
    for (int i = 0; i < MAX_WORDS; i++)
    {
        words[i] = NULL;
    }
}

void add_word(char *word)
{
    for (int i = 0; words[i] != NULL; i++)
    {
        if (strcmp(word, words[i]) == 0)
        {
            return;
        }
    }

    words[MAX_WORDS - 1] = word;
}

void count_words()
{
    int word_count = 0;
    for (int i = 0; words[i] != NULL; i++)
    {
        word_count++;
    }

    printf("Total number of words: %d\n", word_count);
}

int main()
{
    initialize_word_list();

    add_word("apocalypse");
    add_word("cataclysm");
    add_word("destruction");
    add_word("survival");

    count_words();

    return 0;
}