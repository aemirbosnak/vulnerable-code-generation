//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: modular
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 10

typedef struct Word
{
    char **words;
    int words_count;
} Word;

Word *create_word_list(int words_count)
{
    Word *word_list = malloc(sizeof(Word));
    word_list->words = malloc(words_count * sizeof(char *));
    word_list->words_count = words_count;

    return word_list;
}

void add_word_to_list(Word *word_list, char *word)
{
    word_list->words[word_list->words_count++] = word;
}

void free_word_list(Word *word_list)
{
    free(word_list->words);
    free(word_list);
}

int main()
{
    Word *word_list = create_word_list(MAX_WORDS);

    add_word_to_list(word_list, "C");
    add_word_to_list(word_list, "Typing");
    add_word_to_list(word_list, "Speed");
    add_word_to_list(word_list, "Test");

    clock_t start_time, end_time;
    double time_taken;

    start_time = clock();

    for (int i = 0; i < word_list->words_count; i++)
    {
        printf("%s ", word_list->words[i]);
    }

    end_time = clock();

    time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\nTime taken: %.2f seconds\n", time_taken);

    free_word_list(word_list);

    return 0;
}