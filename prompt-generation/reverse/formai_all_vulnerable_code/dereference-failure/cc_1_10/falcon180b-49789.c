//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 20

typedef struct {
    char *word;
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;
    return strcmp(wc1->word, wc2->word);
}

void tokenize(char *text, char **tokens) {
    char *token = strtok(text, ",.!?;:");
    int i = 0;
    while (token!= NULL) {
        tokens[i++] = token;
        token = strtok(NULL, ",.!?;:");
    }
    tokens[i] = NULL;
}

int isSpam(char *text) {
    int numSpamWords = 0;
    WordCount *spamWords = malloc(sizeof(WordCount) * MAX_WORDS);
    memset(spamWords, 0, sizeof(WordCount) * MAX_WORDS);
    char **tokens = malloc(sizeof(char *) * MAX_WORDS);
    int numTokens = 0;
    tokenize(text, tokens);
    for (int i = 0; i < numTokens; i++) {
        char *token = tokens[i];
        int len = strlen(token);
        if (len >= MIN_WORD_LENGTH && len <= MAX_WORD_LENGTH) {
            spamWords[numSpamWords].word = token;
            spamWords[numSpamWords++].count++;
        }
    }
    qsort(spamWords, numSpamWords, sizeof(WordCount), compareWords);
    for (int i = 0; i < numSpamWords; i++) {
        if (spamWords[i].count >= 3) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }
    char *text = argv[1];
    int isSpamResult = isSpam(text);
    if (isSpamResult) {
        printf("Spam detected!\n");
    } else {
        printf("No spam detected.\n");
    }
    return 0;
}