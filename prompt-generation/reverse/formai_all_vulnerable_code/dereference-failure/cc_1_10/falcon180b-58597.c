//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 20
#define MAX_SENTENCE_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void read_sentence(char sentence[]) {
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);
    sentence[strcspn(sentence, "\n")] = '\0';
}

void tokenize_sentence(char sentence[], char words[], int max_words) {
    int num_words = 0;
    char *token = strtok(sentence, " ");
    while (token!= NULL && num_words < max_words) {
        strcpy(words[num_words], token);
        num_words++;
        token = strtok(NULL, " ");
    }
}

void count_word_frequencies(char words[], int num_words, WordFrequency freq_table[], int max_words) {
    for (int i = 0; i < num_words; i++) {
        int found = 0;
        for (int j = 0; j < max_words &&!found; j++) {
            if (strcmp(words[i], freq_table[j].word) == 0) {
                freq_table[j].count++;
                found = 1;
            }
        }
        if (!found) {
            strcpy(freq_table[max_words - 1].word, words[i]);
            freq_table[max_words - 1].count = 1;
            max_words++;
        }
    }
}

void print_word_frequencies(WordFrequency freq_table[], int max_words) {
    printf("Word\tFrequency\n");
    for (int i = 0; i < max_words; i++) {
        printf("%s\t%d\n", freq_table[i].word, freq_table[i].count);
    }
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    char words[MAX_WORD_LENGTH][MAX_WORD_LENGTH];
    WordFrequency freq_table[MAX_WORD_LENGTH];
    int num_words;

    read_sentence(sentence);
    tokenize_sentence(sentence, words, MAX_WORD_LENGTH);
    count_word_frequencies(words, num_words, freq_table, MAX_WORD_LENGTH);
    print_word_frequencies(freq_table, MAX_WORD_LENGTH);

    return 0;
}