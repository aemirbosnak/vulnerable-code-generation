//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: excited
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

int compare_words(const void *a, const void *b) {
    const WordFrequency *word_a = (const WordFrequency *)a;
    const WordFrequency *word_b = (const WordFrequency *)b;

    return strcmp(word_a->word, word_b->word);
}

void count_words(char *text, WordFrequency *word_frequencies) {
    char *word = strtok(text, ",.!?;:\"'-");
    while (word!= NULL) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            if (!isalpha(word[i])) {
                word[i] = '\0';
            }
        }
        word_frequencies[i].word[strlen(word_frequencies[i].word)] = '\0';
        strcpy(word_frequencies[i].word, word);
        word_frequencies[i].count++;
        word = strtok(NULL, ",.!?;:\"'-");
        i++;
    }
}

void print_frequencies(WordFrequency *word_frequencies, int num_words) {
    qsort(word_frequencies, num_words, sizeof(WordFrequency), compare_words);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_frequencies[i].word, word_frequencies[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char *text = NULL;
    size_t text_size = 0;

    while ((text_size = fread(text, sizeof(char), text_size + 1, file))!= 0) {
        text = realloc(text, text_size + 1);
    }

    fclose(file);

    WordFrequency word_frequencies[MAX_WORDS];
    int num_words = 0;

    count_words(text, word_frequencies);
    print_frequencies(word_frequencies, num_words);

    free(text);

    return 0;
}