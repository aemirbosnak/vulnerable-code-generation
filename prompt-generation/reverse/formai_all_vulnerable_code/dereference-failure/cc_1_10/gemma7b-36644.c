//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: expert-level
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 1000

typedef struct Word
{
    char **words;
    int size;
} Word;

Word *word_allocate(int size)
{
    Word *w = malloc(sizeof(Word));
    w->words = malloc(sizeof(char *) * size);
    w->size = size;
    return w;
}

void word_add(Word *w, char *word)
{
    w->words[w->size++] = strdup(word);
}

void test_typing_speed(Word *words)
{
    int i, time_start, time_end, total_time = 0, words_typed = 0;
    char word_guess[MAX_WORDS];

    for (i = 0; i < words->size; i++)
    {
        printf("Type the following word: %s", words->words[i]);
        scanf("%s", word_guess);

        if (strcmp(word_guess, words->words[i]) == 0)
        {
            words_typed++;
        }
    }

    time_start = clock();
    printf("Please type any word you want:");
    scanf("%s", word_guess);
    time_end = clock();

    total_time = time_end - time_start;

    printf("You typed %d words in %d seconds, which is %.2f words per second.", words_typed, total_time, (double)words_typed / (double)total_time);
}

int main()
{
    Word *words = word_allocate(MAX_WORDS);
    word_add(words, "Hello");
    word_add(words, "World");
    word_add(words, "How");
    word_add(words, "Are");
    word_add(words, "You?");

    test_typing_speed(words);

    return 0;
}