//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50
#define MAX_SENTENCE_LENGTH 200

struct word {
    char *value;
    int count;
};

int compare_words(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int get_word_count(char *sentence) {
    int count = 0;
    char *word = strtok(sentence, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}

void print_word_counts(struct word *word_counts, int num_words) {
    qsort(word_counts, num_words, sizeof(struct word), compare_words);
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].value, word_counts[i].count);
    }
}

int main() {
    char input_sentence[MAX_SENTENCE_LENGTH];
    char *sentence = NULL;
    int num_words = 0;
    struct word word_counts[MAX_WORDS];

    printf("Enter a sentence: ");
    fgets(input_sentence, MAX_SENTENCE_LENGTH, stdin);
    sentence = strtok(input_sentence, ".");
    while (sentence!= NULL) {
        if (num_words >= MAX_WORDS) {
            printf("Too many words.\n");
            exit(1);
        }
        word_counts[num_words].value = strdup(sentence);
        word_counts[num_words].count = get_word_count(sentence);
        num_words++;
        sentence = strtok(NULL, ".");
    }
    printf("Word counts:\n");
    print_word_counts(word_counts, num_words);

    return 0;
}