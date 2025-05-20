//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Word {
    char *word;
    int count;
} Word;

void toLower(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) str[i] = tolower(str[i]);
    }
}

int compareWords(const void *a, const void *b) {
    return strcmp(((Word *)a)->word, ((Word *)b)->word);
}

void incrementWordCount(Word **words, int size, char *word) {
    for (int i = 0; i < size; i++) {
        if (strcmp(((Word *)words[i])->word, word) == 0) {
            ((Word *)words[i])->count++;
            return;
        }
    }

    Word *newWord = (Word *)malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->count = 1;

    words = realloc(words, sizeof(Word) * (size + 1));
    words[size] = newWord;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int capacity = 16;
    Word *words = malloc(sizeof(Word) * capacity);

    char word[128];
    int numWords = 0;

    while (fscanf(file, "%s%*c", word) != EOF) {
        toLower(word);
        incrementWordCount(&words, numWords, word);
        numWords++;

        if (numWords >= capacity) {
            capacity *= 2;
            words = realloc(words, sizeof(Word) * capacity);
        }
    }

    qsort(words, numWords, sizeof(Word), compareWords);

    printf("\nWord Frequencies:\n");

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
        free(words[i].word);
    }

    free(words);
    fclose(file);

    return 0;
}