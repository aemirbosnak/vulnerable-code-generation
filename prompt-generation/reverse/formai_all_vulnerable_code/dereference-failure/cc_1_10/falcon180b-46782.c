//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 50000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void readWords(FILE *file, WordFrequency *words) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            words[i].word[0] = toupper(ch);
            words[i].word[1] = '\0';
            words[i].count = 1;
            i++;
        } else if (i > 0) {
            int j = 0;
            while (j < strlen(words[i - 1].word)) {
                if (words[i - 1].word[j] == ch) {
                    words[i - 1].count++;
                    break;
                }
                j++;
            }
        }
    }
}

void writeWords(FILE *file, WordFrequency *words, int numWords) {
    for (int i = 0; i < numWords; i++) {
        fprintf(file, "%s: %d\n", words[i].word, words[i].count);
    }
}

int compareWords(const void *a, const void *b) {
    WordFrequency *word1 = (WordFrequency *) a;
    WordFrequency *word2 = (WordFrequency *) b;
    return strcmp(word1->word, word2->word);
}

int main() {
    FILE *inputFile, *outputFile;
    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    readWords(inputFile, words);
    numWords = strlen(words[0].word);

    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    writeWords(outputFile, words, numWords);
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}