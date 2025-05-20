//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int score;
} Word;

int compareWords(const void *a, const void *b) {
    Word *wordA = (Word *) a;
    Word *wordB = (Word *) b;

    if (wordA->score > wordB->score) {
        return -1;
    } else if (wordA->score < wordB->score) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <sentence>\n", argv[0]);
        return 1;
    }

    char sentence[MAX_SENTENCE_LENGTH];
    strcpy(sentence, argv[1]);

    int numWords = 0;
    Word words[MAX_WORDS];

    char *word = strtok(sentence, " ");
    while (word!= NULL) {
        if (numWords >= MAX_WORDS) {
            printf("Too many words in sentence.\n");
            return 1;
        }

        int length = strlen(word);
        if (length >= MAX_WORD_LENGTH) {
            printf("Word is too long: %s\n", word);
            return 1;
        }

        strcpy(words[numWords].word, word);
        words[numWords].score = 0;

        numWords++;

        word = strtok(NULL, " ");
    }

    for (int i = 0; i < numWords; i++) {
        char *word = words[i].word;
        int length = strlen(word);

        for (int j = 0; j < length; j++) {
            if (isalpha(word[j])) {
                if (isupper(word[j])) {
                    words[i].score++;
                } else if (islower(word[j])) {
                    words[i].score--;
                }
            }
        }
    }

    qsort(words, numWords, sizeof(Word), compareWords);

    printf("Words:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].score);
    }

    return 0;
}