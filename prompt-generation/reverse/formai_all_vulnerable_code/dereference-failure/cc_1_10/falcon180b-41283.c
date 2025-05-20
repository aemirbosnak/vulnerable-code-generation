//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 30

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *) a;
    WordFrequency *wordB = (WordFrequency *) b;

    if (wordA->frequency > wordB->frequency) {
        return -1;
    } else if (wordA->frequency < wordB->frequency) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    FILE *inputFile;
    char inputString[10000];
    int inputLength;
    char word[MAX_WORD_LENGTH];
    int wordLength;
    int wordCount = 0;
    WordFrequency wordFrequencies[MAX_WORDS];

    inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while ((inputLength = fread(inputString, sizeof(char), sizeof(inputString), inputFile)) > 0) {
        inputString[inputLength] = '\0';

        for (int i = 0; i < inputLength; i++) {
            if (isalpha(inputString[i])) {
                wordLength = 0;

                while (isalpha(inputString[i]) && wordLength < MAX_WORD_LENGTH) {
                    word[wordLength] = tolower(inputString[i]);
                    i++;
                    wordLength++;
                }

                word[wordLength] = '\0';

                for (int j = 0; j < wordCount; j++) {
                    if (strcmp(wordFrequencies[j].word, word) == 0) {
                        wordFrequencies[j].frequency++;
                        break;
                    }
                }

                if (wordCount >= MAX_WORDS) {
                    break;
                }

                strcpy(wordFrequencies[wordCount].word, word);
                wordFrequencies[wordCount].frequency = 1;
                wordCount++;
            }
        }
    }

    fclose(inputFile);

    qsort(wordFrequencies, wordCount, sizeof(WordFrequency), compareWords);

    printf("Top 10 most frequent words:\n");

    for (int i = 0; i < 10 && i < wordCount; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }

    return 0;
}