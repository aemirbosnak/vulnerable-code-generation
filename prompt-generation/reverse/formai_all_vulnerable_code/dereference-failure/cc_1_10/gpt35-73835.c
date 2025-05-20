//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 5000

typedef struct {
    char *word;
    int frequency;
} WordFreq;

char *get_word(void)
{
    char *word = malloc(MAX_WORD_LENGTH * sizeof(char));
    int pos = 0;
    char c;

    while((c = getchar()) != EOF && !isspace(c) && pos < MAX_WORD_LENGTH - 1)
        word[pos++] = c;
    word[pos] = '\0';

    return word;
}

int is_unique(char *word, WordFreq *word_freq, int num_words)
{
    int i;
    for(i = 0; i < num_words; i++)
        if(strcmp(word, word_freq[i].word) == 0)
            return 0;

    return 1;    
}

void add_word(char *word, WordFreq *word_freq, int *num_words)
{
    word_freq[*num_words].word = word;
    word_freq[*num_words].frequency = 1;
    (*num_words)++;
}

void increment_freq(char *word, WordFreq *word_freq, int num_words)
{
    int i;
    for(i = 0; i < num_words; i++)
        if(strcmp(word, word_freq[i].word) == 0)
            word_freq[i].frequency++;
}

int cmpfunc(const void *a, const void *b)
{
    const WordFreq *word_a = (const WordFreq *)a;
    const WordFreq *word_b = (const WordFreq *)b;

    return word_b->frequency - word_a->frequency; 
}

int main(void)
{
    WordFreq *word_freq = malloc(MAX_WORDS * sizeof(WordFreq));
    int num_words = 0;

    char *word;
    while((word = get_word()) != NULL) {
        if(is_unique(word, word_freq, num_words))
            add_word(word, word_freq, &num_words);
        else
            increment_freq(word, word_freq, num_words);
    }

    qsort(word_freq, num_words, sizeof(WordFreq), cmpfunc);

    printf("Word Frequency Count:\n");
    int i;
    for(i = 0; i < num_words && word_freq[i].frequency > 1; i++)
        printf("%s : %d\n", word_freq[i].word, word_freq[i].frequency);
    
    return 0;
}