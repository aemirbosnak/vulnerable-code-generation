//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word_t {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

void generate_random_words(struct word_t *words, int num_words) {
    srand(time(NULL));
    for (int i = 0; i < num_words; i++) {
        int word_length = rand() % MAX_WORD_LENGTH + 1;
        char *word = malloc(word_length * sizeof(char));
        for (int j = 0; j < word_length; j++) {
            word[j] = rand() % 26 + 'a';
        }
        strcpy(words[i].word, word);
        words[i].frequency = 0;
    }
}

void count_word_frequencies(struct word_t *words, char *sentence, int num_words) {
    for (int i = 0; i < num_words; i++) {
        int word_length = strlen(words[i].word);
        for (int j = 0; j <= strlen(sentence) - word_length; j++) {
            if (strncmp(sentence + j, words[i].word, word_length) == 0) {
                words[i].frequency++;
            }
        }
    }
}

void print_word_frequencies(struct word_t *words, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    struct word_t words[MAX_WORDS];
    generate_random_words(words, 10);
    char sentence[] = "The quick brown fox jumps over the lazy dog";
    count_word_frequencies(words, sentence, 10);
    print_word_frequencies(words, 10);
    return 0;
}