//Falcon-180B DATASET v1.0 Category: Recursive ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

Word* createWord(char* str) {
    Word* word = (Word*)malloc(sizeof(Word));
    strcpy(word->word, str);
    word->count = 0;
    return word;
}

void freeWord(Word* word) {
    free(word);
}

void countWords(char* str, Word* words) {
    char* token;
    char* saveptr;
    int i = 0;

    token = strtok_r(str, ",.!?;:\"'", &saveptr);
    while (token!= NULL) {
        if (strlen(token) > 0) {
            Word* w = NULL;
            for (int j = 0; j < i; j++) {
                if (strcmp(words[j].word, token) == 0) {
                    w = &words[j];
                    break;
                }
            }

            if (w == NULL) {
                w = createWord(token);
                words[i] = *w;
                i++;
            }

            w->count++;
        }
        token = strtok_r(NULL, ",.!?;:\"'", &saveptr);
    }
}

void printWords(Word* words, int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    char* str = "Hello, world! How are you doing today? I am feeling great!";
    Word* words = (Word*)malloc(sizeof(Word));
    countWords(str, words);
    printWords(words, 1);
    freeWord(words);
    return 0;
}