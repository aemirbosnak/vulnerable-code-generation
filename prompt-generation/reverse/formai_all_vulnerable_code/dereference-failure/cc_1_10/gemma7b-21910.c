//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_CHAR 256

typedef struct Word
{
    char **words;
    int size;
    int capacity;
} Word;

Word *word_alloc(int size)
{
    Word *w = malloc(sizeof(Word));
    w->words = malloc(size * sizeof(char *));
    w->size = 0;
    w->capacity = size;
    return w;
}

void word_add(Word *w, char *word)
{
    w->words[w->size++] = word;
    if (w->size == w->capacity)
    {
        w->capacity *= 2;
        w->words = realloc(w->words, w->capacity * sizeof(char *));
    }
}

int main()
{
    Word *words = word_alloc(MAX_WORDS);

    time_t start, end;
    char text[MAX_CHAR];

    start = time(NULL);

    printf("Type as fast as you can:");
    fgets(text, MAX_CHAR, stdin);

    end = time(NULL);

    word_add(words, text);

    printf("Your text:\n");
    for (int i = 0; i < words->size; i++)
    {
        printf("%s\n", words->words[i]);
    }

    printf("Time taken: %.2f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}