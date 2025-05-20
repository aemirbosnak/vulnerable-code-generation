//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_WORDS 1000

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    WordCount *word_counts;
    int num_words;
} SentimentAnalysis;

int compare_word_counts(const void *a, const void *b) {
    WordCount *wc1 = *(WordCount **)a;
    WordCount *wc2 = *(WordCount **)b;
    return strcmp(wc1->word, wc2->word);
}

void print_word_counts(SentimentAnalysis *sa) {
    qsort(sa->word_counts, sa->num_words, sizeof(WordCount), compare_word_counts);
    for (int i = 0; i < sa->num_words; i++) {
        WordCount *wc = sa->word_counts + i;
        printf("%s: %d\n", wc->word, wc->count);
    }
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    SentimentAnalysis sa = {0};
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        if (strlen(token) > 0) {
            WordCount *wc = malloc(sizeof(WordCount));
            wc->word = strdup(token);
            wc->count = 1;

            if (sa.num_words >= MAX_WORDS) {
                printf("Max number of words reached.\n");
                exit(1);
            }

            sa.word_counts = realloc(sa.word_counts, (sa.num_words + 1) * sizeof(WordCount));
            sa.word_counts[sa.num_words++] = *wc;
        }
        token = strtok(NULL, " ");
    }

    if (sa.num_words == 0) {
        printf("No valid words found.\n");
        exit(1);
    }

    print_word_counts(&sa);

    return 0;
}