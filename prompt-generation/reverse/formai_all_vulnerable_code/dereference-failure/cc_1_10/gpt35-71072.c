//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: minimalist
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_WORDS 1000

int get_word(char *word, int max_word_length);
void read_words(char *words[], int max_words, int *num_words, int word_length[]);
void sort_words(char *words[], int num_words);
void print_word_occurrences(char *words[], int num_words, int word_length[]);

int main(void)
{
    int i, num_words, word_length[MAX_WORDS];
    char *words[MAX_WORDS];

    read_words(words, MAX_WORDS, &num_words, word_length);
    sort_words(words, num_words);
    print_word_occurrences(words, num_words, word_length);

    for (i = 0; i < num_words; i++)
        free(words[i]);

    return 0;
}

int get_word(char *word, int max_word_length)
{
    int c, length = 0;

    while ((c = getchar()) != EOF)
    {
        if (isalpha(c))
        {
            if (length < max_word_length)
                *word++ = tolower(c);

            length++;
        }
        else if (length > 0)
            break;
    }

    *word = '\0';

    return length;
}

void read_words(char *words[], int max_words, int *num_words, int word_length[])
{
    int i;

    *num_words = 0;

    while (*num_words < max_words && get_word(words[*num_words] = malloc(MAX_WORD_LENGTH), MAX_WORD_LENGTH))
    {
        word_length[*num_words] = strlen(words[*num_words]);
        (*num_words)++;
    }
}

void sort_words(char *words[], int num_words)
{
    int i, j;

    for (i = 1; i < num_words; i++)
    {
        char *temp = words[i];

        for (j = i; j > 0 && strcmp(temp, words[j - 1]) < 0; j--)
            words[j] = words[j - 1];

        words[j] = temp;
    }
}

void print_word_occurrences(char *words[], int num_words, int word_length[])
{
    int i, j, count;

    for (i = 0; i < num_words; i++)
    {
        if (i > 0 && strcmp(words[i], words[i - 1]) == 0)
            continue;

        count = 1;

        for (j = i + 1; j < num_words && strcmp(words[j], words[i]) == 0; j++)
            count++;

        printf("%-*s %*d\n", word_length[i], words[i], 5, count);
    }
}