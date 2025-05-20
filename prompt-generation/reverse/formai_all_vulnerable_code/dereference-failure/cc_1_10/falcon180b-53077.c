//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int word_compare(const void *a, const void *b) {
    const WordFrequency *word1 = a;
    const WordFrequency *word2 = b;

    return strcmp(word1->word, word2->word);
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *text = NULL;
    size_t text_size = 0;
    WordFrequency *word_frequency = NULL;
    int num_words = 0;
    int i;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    text_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    text = malloc(text_size + 1);
    if (text == NULL) {
        fprintf(stderr, "Memory error\n");
        exit(1);
    }

    fread(text, 1, text_size, file);
    text[text_size] = '\0';

    word_frequency = malloc(MAX_WORDS * sizeof(WordFrequency));
    if (word_frequency == NULL) {
        fprintf(stderr, "Memory error\n");
        exit(1);
    }

    for (i = 0; i < text_size; i++) {
        if (isalpha(text[i])) {
            if (num_words == MAX_WORDS) {
                fprintf(stderr, "Maximum number of words reached\n");
                exit(1);
            }

            WordFrequency *current_word = word_frequency + num_words;
            current_word->count = 1;

            int j = 0;
            while (isalpha(text[i + j])) {
                current_word->word[j] = tolower(text[i + j]);
                j++;
            }
            current_word->word[j] = '\0';

            num_words++;
        }
    }

    qsort(word_frequency, num_words, sizeof(WordFrequency), word_compare);

    printf("Word\tFrequency\n");
    for (i = 0; i < num_words; i++) {
        printf("%s\t%d\n", word_frequency[i].word, word_frequency[i].count);
    }

    free(text);
    free(word_frequency);

    return 0;
}