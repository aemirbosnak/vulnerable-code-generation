//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void readFile(FILE* file, WordFrequency* words, int* numWords) {
    char ch;
    int inWord = 0;
    int wordLength = 0;
    char* word = (char*) malloc(MAX_WORD_LENGTH * sizeof(char));

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            inWord = 1;
            word[wordLength++] = tolower(ch);
        } else {
            inWord = 0;
            if (wordLength > 0) {
                word[wordLength] = '\0';
                int i;
                for (i = 0; i < *numWords; i++) {
                    if (strcmp(word, words[i].word) == 0) {
                        words[i].frequency++;
                        break;
                    }
                }
                if (i == *numWords) {
                    WordFrequency newWord;
                    strcpy(newWord.word, word);
                    newWord.frequency = 1;
                    words[*numWords] = newWord;
                    (*numWords)++;
                }
                wordLength = 0;
            }
        }
    }

    if (inWord && wordLength > 0) {
        word[wordLength] = '\0';
        int i;
        for (i = 0; i < *numWords; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].frequency++;
                break;
            }
        }
        if (i == *numWords) {
            WordFrequency newWord;
            strcpy(newWord.word, word);
            newWord.frequency = 1;
            words[*numWords] = newWord;
            (*numWords)++;
        }
    }

    free(word);
}

void printWords(WordFrequency* words, int numWords) {
    int i;
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    FILE* file;
    file = fopen("example.txt", "r");

    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    readFile(file, words, &numWords);

    fclose(file);

    printWords(words, numWords);

    return 0;
}