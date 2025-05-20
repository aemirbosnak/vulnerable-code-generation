//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Word {
    char *word;
    int count;
} Word;

void addWord(Word **words, int *numWords, char *word) {
    if (*numWords >= 100) {
        Word *newWords = (Word *)realloc(*words, sizeof(Word) * (*numWords + 100));
        if (newWords == NULL) {
            fprintf(stderr, "Out of memory!\n");
            exit(EXIT_FAILURE);
        }
        *words = newWords;
    }

    Word *newWord = &((*words)[*numWords]);
    newWord->word = strdup(word);
    newWord->count = 1;

    (*numWords)++;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    Word *words = NULL;
    int numWords = 0;
    char word[256];

    while (fscanf(file, "%s%*c", word) != EOF) {
        for (int i = 0; i < numWords; i++) {
            if (strcasecmp(words[i].word, word) == 0) {
                words[i].count++;
                break;
            }
        }

        addWord(&words, &numWords, word);
    }

    fclose(file);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
        free(words[i].word);
    }

    free(words);

    return EXIT_SUCCESS;
}