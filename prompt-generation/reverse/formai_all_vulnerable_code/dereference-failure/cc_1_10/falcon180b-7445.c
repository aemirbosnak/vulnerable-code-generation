//Falcon-180B DATASET v1.0 Category: Text processing ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;

    return strcmp(wc1->word, wc2->word);
}

void processText(char *text) {
    char *word;
    char *saveptr;
    WordCount words[MAX_WORDS];
    int numWords = 0;

    word = strtok_r(text, " \t\n\r\f", &saveptr);
    while (word!= NULL && numWords < MAX_WORDS) {
        int len = strlen(word);
        if (len > MAX_WORD_LEN) {
            len = MAX_WORD_LEN;
        }
        strncpy(words[numWords].word, word, len);
        words[numWords].word[len] = '\0';
        words[numWords].count = 1;
        numWords++;

        word = strtok_r(NULL, " \t\n\r\f", &saveptr);
    }

    qsort(words, numWords, sizeof(WordCount), compareWords);

    printf("Word Count:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    char text[10000];

    printf("Enter some text:\n");
    fgets(text, sizeof(text), stdin);

    processText(text);

    return 0;
}