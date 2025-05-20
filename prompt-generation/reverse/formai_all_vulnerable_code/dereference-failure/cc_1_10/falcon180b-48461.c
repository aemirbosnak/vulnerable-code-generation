//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: Romeo and Juliet
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20
#define MIN_WORD_LEN 3
#define MIN_SENTENCE_LEN 5
#define MAX_SENTENCE_LEN 100
#define NUM_SENTENCES 10

typedef struct {
    char *word;
    int len;
} Word;

typedef struct {
    Word *words;
    int num_words;
} Sentence;

void generate_sentence(Sentence *sentence) {
    int i, num_words = rand() % (NUM_SENTENCES - MIN_SENTENCE_LEN + 1) + MIN_SENTENCE_LEN;
    char *words[MAX_WORDS];
    int word_lens[MAX_WORDS];
    int total_len = 0;

    for (i = 0; i < num_words; i++) {
        int word_len = rand() % (MAX_WORD_LEN - MIN_WORD_LEN + 1) + MIN_WORD_LEN;
        char *word = malloc(word_len + 1);
        int j;

        for (j = 0; j < word_len; j++) {
            char c = rand() % 26 + 'a';
            word[j] = c;
        }
        word[word_len] = '\0';

        words[i] = word;
        word_lens[i] = word_len;
        total_len += word_len;
    }

    sentence->words = malloc(num_words * sizeof(Word));
    sentence->num_words = num_words;

    for (i = 0; i < num_words; i++) {
        sentence->words[i].word = words[i];
        sentence->words[i].len = word_lens[i];
    }
}

int main() {
    srand(time(NULL));

    Sentence sentence;
    generate_sentence(&sentence);

    printf("Romeo and Juliet:\n");

    int i;
    for (i = 0; i < sentence.num_words; i++) {
        printf("%s ", sentence.words[i].word);
    }

    printf("\n");

    return 0;
}