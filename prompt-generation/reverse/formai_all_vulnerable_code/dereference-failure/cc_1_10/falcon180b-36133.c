//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

typedef struct {
    char *words[MAX_WORDS];
    int num_words;
} Sentence;

void read_sentence(Sentence *sentence) {
    char word[MAX_WORD_LENGTH];
    int i = 0;
    sentence->num_words = 0;
    while (fscanf(stdin, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Sentence too long.\n");
            exit(1);
        }
        strcpy(sentence->words[i], word);
        i++;
        sentence->num_words++;
    }
    sentence->words[i] = NULL;
}

void count_words(Sentence *sentence, WordCount *word_counts) {
    for (int i = 0; i < sentence->num_words; i++) {
        WordCount *word_count = NULL;
        for (int j = 0; j < sentence->num_words; j++) {
            if (strcmp(sentence->words[i], sentence->words[j]) == 0) {
                word_count = &word_counts[j];
                break;
            }
        }
        if (word_count == NULL) {
            for (int j = 0; j < sentence->num_words; j++) {
                if (word_counts[j].count == 0) {
                    word_count = &word_counts[j];
                    break;
                }
            }
        }
        word_count->count++;
    }
}

void print_word_counts(WordCount *word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
        if (word_counts[i].count > 0) {
            printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
        }
    }
}

int main() {
    Sentence sentence;
    WordCount word_counts[MAX_WORDS];
    int num_words;

    printf("Enter a sentence: ");
    read_sentence(&sentence);
    count_words(&sentence, word_counts);
    num_words = sentence.num_words;

    printf("Word frequency:\n");
    print_word_counts(word_counts, num_words);

    return 0;
}