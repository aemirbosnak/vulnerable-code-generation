//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char *word;
    int length;
} word_t;

int compare_words(const void *a, const void *b) {
    const word_t *wordA = a;
    const word_t *wordB = b;
    return strcmp(wordA->word, wordB->word);
}

int main() {
    word_t words[MAX_WORDS];
    int num_words = 0;
    char input_line[MAX_WORD_LENGTH];
    char *word;
    int i;

    printf("Enter a string of text:\n");
    fgets(input_line, MAX_WORD_LENGTH, stdin);

    // Split input_line into words
    word = strtok(input_line, " ");
    while (word!= NULL) {
        if (num_words >= MAX_WORDS) {
            printf("Error: Too many words.\n");
            exit(1);
        }
        words[num_words].word = strdup(word);
        words[num_words].length = strlen(word);
        num_words++;
        word = strtok(NULL, " ");
    }

    // Sort words by length
    qsort(words, num_words, sizeof(word_t), compare_words);

    // Print sorted words
    for (i = 0; i < num_words; i++) {
        printf("%s (%d)\n", words[i].word, words[i].length);
    }

    return 0;
}