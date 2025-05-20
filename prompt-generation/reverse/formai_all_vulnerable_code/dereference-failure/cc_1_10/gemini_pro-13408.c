//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct WordCount {
    char *word;
    int count;
};

int compareWords(const void *a, const void *b) {
    const struct WordCount *wa = a;
    const struct WordCount *wb = b;
    return strcmp(wa->word, wb->word);
}

int main() {
    FILE *fp;
    char *filename = "text.txt";
    char *word;
    int wordCount = 0;
    struct WordCount *words = NULL;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    while ((word = malloc(100)) != NULL) {
        fscanf(fp, "%s", word);
        wordCount++;
        words = realloc(words, sizeof(struct WordCount) * wordCount);
        words[wordCount - 1].word = word;
        words[wordCount - 1].count = 1;
    }

    fclose(fp);

    qsort(words, wordCount, sizeof(struct WordCount), compareWords);

    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    for (int i = 0; i < wordCount; i++) {
        free(words[i].word);
    }
    free(words);

    return EXIT_SUCCESS;
}