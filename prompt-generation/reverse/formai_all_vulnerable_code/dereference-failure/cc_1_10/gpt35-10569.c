//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 1000

int main() {
    char text[10000];
    char* wordList[MAX_NUM_WORDS];
    int freqList[MAX_NUM_WORDS] = {0};
    int numWords = 0;

    printf("Enter the text:\n");
    fgets(text, sizeof(text), stdin);

    char* word = strtok(text, " \n");

    while (word != NULL && numWords < MAX_NUM_WORDS) {
        int wordLength = strlen(word);
        if (wordLength <= MAX_WORD_LENGTH) {
            char* newWord = (char*) malloc(wordLength * sizeof(char));
            strncpy(newWord, word, wordLength);
            newWord[wordLength] = '\0';
            for (int i = 0; i < wordLength; i++) {
                newWord[i] = tolower(newWord[i]);
            }
            int wordIndex = -1;
            for (int i = 0; i < numWords; i++) {
                if (strcmp(wordList[i], newWord) == 0) {
                    wordIndex = i;
                    break;
                }
            }
            if (wordIndex == -1) {
                wordList[numWords] = newWord;
                freqList[numWords] = 1;
                numWords++;
            } else {
                freqList[wordIndex]++;
                free(newWord);
            }
        }
        word = strtok(NULL, " \n");
    }

    printf("\nWord Frequency Count:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordList[i], freqList[i]);
        free(wordList[i]);
    }

    return 0;
}