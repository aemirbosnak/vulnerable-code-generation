//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

typedef struct word_freq {
    char *word;
    int frequency;
} word_freq;

int get_word(char *buffer);
void add_word_to_list(char *word, word_freq **list, int *num_words);
int compare_word_freq(const void *a, const void *b);
void print_word_freq(word_freq *list, int num_words);

int main()
{
    char buffer[MAX_WORD_LENGTH];
    word_freq *list = NULL;
    int num_words = 0;

    while (get_word(buffer)) {
        add_word_to_list(buffer, &list, &num_words);
    }

    qsort(list, num_words, sizeof(word_freq), compare_word_freq);

    print_word_freq(list, num_words);

    return 0;
}

int get_word(char *buffer)
{
    int c, i = 0;

    while ((c = getchar()) != EOF) {
        if (!isalpha(c)) {
            if (i > 0) {
                break;
            } else {
                continue;
            }
        }
        buffer[i++] = tolower(c);
        if (i >= MAX_WORD_LENGTH - 1) {
            break;
        }
    }

    buffer[i] = '\0';

    return i > 0;
}

void add_word_to_list(char *word, word_freq **list, int *num_words)
{
    int i;
    for (i = 0; i < *num_words; i++) {
        if (strcmp(word, (*list)[i].word) == 0) {
            (*list)[i].frequency++;
            return;
        }
    }

    if (*num_words % 10 == 0) {
        *list = (word_freq *)realloc(*list, (*num_words + 10) * sizeof(word_freq));
        if (*list == NULL) {
            fprintf(stderr, "Error: Memory allocation failed\n");
            exit(1);
        }
    }

    (*list)[*num_words].word = strdup(word);
    (*list)[*num_words].frequency = 1;

    (*num_words)++;
}

int compare_word_freq(const void *a, const void *b)
{
    const word_freq *w1 = (const word_freq *)a;
    const word_freq *w2 = (const word_freq *)b;

    if (w1->frequency == w2->frequency) {
        return strcmp(w1->word, w2->word);
    }

    return w2->frequency - w1->frequency;
}

void print_word_freq(word_freq *list, int num_words)
{
    int i;

    printf("\nWord frequency list:\n");
    printf("---------------------\n");

    for (i = 0; i < num_words; i++) {
        printf("%-20s %d\n", list[i].word, list[i].frequency);
    }
}