//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 1024

typedef struct Word {
    char *word;
    struct Word *next;
} Word;

Word *word_list = NULL;

void add_word(char *word)
{
    Word *new_word = malloc(sizeof(Word));
    new_word->word = strdup(word);
    new_word->next = NULL;

    if (word_list == NULL)
    {
        word_list = new_word;
    }
    else
    {
        word_list->next = new_word;
        word_list = new_word;
    }
}

int count_words()
{
    int word_count = 0;
    Word *current_word = word_list;

    while (current_word)
    {
        word_count++;
        current_word = current_word->next;
    }

    return word_count;
}

int main()
{
    add_word("The");
    add_word("Quick");
    add_word("Brown");
    add_word("Fox");
    add_word("Jumping");
    add_word("Frog");

    int word_count = count_words();

    printf("Number of words in the list: %d\n", word_count);

    return 0;
}