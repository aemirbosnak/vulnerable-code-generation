//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100

typedef struct {
    char *word;
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    char sentence[1000];
    char *words[MAX_WORDS];
    int numWords = 0;
    WordCount *wordCounts = malloc(sizeof(WordCount) * MAX_WORDS);

    printf("Enter a movie review: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Tokenize the sentence into words
    char *token = strtok(sentence, ",.?!;");
    while (token!= NULL) {
        if (numWords >= MAX_WORDS) {
            printf("Error: Too many words in review.\n");
            exit(1);
        }
        words[numWords++] = token;
        token = strtok(NULL, ",.?!;");
    }

    // Count the frequency of each word
    for (int i = 0; i < numWords; i++) {
        WordCount *wc = wordCounts + i;
        wc->word = words[i];
        wc->count = 1;
    }

    // Sort the words alphabetically
    qsort(words, numWords, sizeof(char *), compareWords);
    for (int i = 0; i < numWords; i++) {
        WordCount *wc = wordCounts + i;
        wc->word = words[i];
    }

    // Print the word count
    for (int i = 0; i < numWords; i++) {
        WordCount *wc = wordCounts + i;
        printf("%s: %d\n", wc->word, wc->count);
    }

    free(wordCounts);
    return 0;
}