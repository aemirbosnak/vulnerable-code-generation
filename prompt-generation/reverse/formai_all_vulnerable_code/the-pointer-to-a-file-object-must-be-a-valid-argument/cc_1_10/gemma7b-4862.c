//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 255

typedef struct Word {
    char *word;
    int frequency;
} Word;

Word *words;

void read_text(FILE *fp)
{
    char text[MAX_WORD_LENGTH];
    words = malloc(MAX_WORDS * sizeof(Word));
    int i = 0;

    while (fgets(text, MAX_WORD_LENGTH, fp) != NULL)
    {
        char *word = strtok(text, " ");
        while (word)
        {
            Word *w = &words[i++];
            w->word = strdup(word);
            w->frequency = 1;
            word = strtok(NULL, " ");
        }
    }
}

void count_words(void)
{
    for (int i = 0; i < MAX_WORDS; i++)
    {
        words[i].frequency++;
    }
}

void print_word_frequency(void)
{
    for (int i = 0; i < MAX_WORDS; i++)
    {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main(int argc, char *argv[])
{
    FILE *fp = fopen("text.txt", "r");
    read_text(fp);
    count_words();
    print_word_frequency();
    fclose(fp);

    return 0;
}