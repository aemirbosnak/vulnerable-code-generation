//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: mind-bending
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 1000

typedef struct Word
{
    char **words;
    int index;
} Word;

Word **createWordList()
{
    Word **list = (Word **)malloc(MAX_WORDS * sizeof(Word));
    for (int i = 0; i < MAX_WORDS; i++)
    {
        list[i] = (Word *)malloc(sizeof(Word));
        list[i]->words = (char **)malloc(20 * sizeof(char *));
        list[i]->index = 0;
    }
    return list;
}

void addWordToList(Word **list, char *word)
{
    list[list[0]->index]->words[list[0]->index] = word;
    list[0]->index++;
}

int main()
{
    Word **list = createWordList();
    addWordToList(list, "Hello");
    addWordToList(list, "World");
    addWordToList(list, "Welcome");
    addWordToList(list, "To");
    addWordToList(list, "The");
    addWordToList(list, "Internet");

    time_t start, end;
    start = clock();

    for (int i = 0; i < list[0]->index; i++)
    {
        printf("%s ", list[0]->words[i]);
    }

    end = clock();

    printf("\nTime taken: %f seconds", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}