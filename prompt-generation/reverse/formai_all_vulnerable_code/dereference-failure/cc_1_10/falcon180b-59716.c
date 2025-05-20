//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_sentence(char* sentence) {
    char* token = strtok(sentence, " ");
    while (token!= NULL) {
        if (strlen(token) > 0) {
            strcpy(sentence, token);
            break;
        }
        token = strtok(NULL, " ");
    }
}

void count_words(char* sentence, WordCount* word_counts, int num_word_counts) {
    char* token = strtok(sentence, " ");
    while (token!= NULL) {
        if (strlen(token) > 0) {
            int i;
            for (i = 0; i < num_word_counts; i++) {
                if (strcmp(token, word_counts[i].word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }
            if (i == num_word_counts) {
                strcpy(word_counts[num_word_counts - 1].word, token);
                word_counts[num_word_counts - 1].count = 1;
                num_word_counts++;
            }
        }
        token = strtok(NULL, " ");
    }
}

void print_word_counts(WordCount* word_counts, int num_word_counts) {
    printf("Word Counts:\n");
    for (int i = 0; i < num_word_counts; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    WordCount word_counts[MAX_WORD_LENGTH];
    int num_word_counts = 0;

    printf("Enter a sentence:\n");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    read_sentence(sentence);
    count_words(sentence, word_counts, num_word_counts);
    print_word_counts(word_counts, num_word_counts);

    return 0;
}