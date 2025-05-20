//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: careful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_sentence(char sentence[]) {
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);
    sentence[strcspn(sentence, "\n")] = '\0';
}

void tokenize_sentence(char sentence[], char words[]) {
    char *token = strtok(sentence, " ");
    int i = 0;

    while (token!= NULL) {
        strcpy(words[i], token);
        i++;
        token = strtok(NULL, " ");
    }

    words[i] = '\0';
}

void count_words(char words[], WordCount counts[], int num_words) {
    int i;

    for (i = 0; i < num_words; i++) {
        counts[i].word[0] = '\0';
        counts[i].count = 0;
    }

    for (i = 0; words[i]!= '\0'; i++) {
        int j;

        for (j = 0; j < num_words; j++) {
            if (strcmp(words[i], counts[j].word) == 0) {
                counts[j].count++;
                break;
            }
        }

        if (j == num_words) {
            strcpy(counts[i].word, words[i]);
            counts[i].count = 1;
        }
    }
}

void print_word_counts(WordCount counts[], int num_words) {
    int i;

    for (i = 0; i < num_words; i++) {
        if (counts[i].count > 0) {
            printf("%s: %d\n", counts[i].word, counts[i].count);
        }
    }
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    char words[MAX_WORD_LENGTH][MAX_WORD_LENGTH];
    WordCount counts[MAX_WORD_LENGTH];
    int num_words;

    read_sentence(sentence);
    tokenize_sentence(sentence, words);
    count_words(words, counts, num_words);
    print_word_counts(counts, num_words);

    return 0;
}