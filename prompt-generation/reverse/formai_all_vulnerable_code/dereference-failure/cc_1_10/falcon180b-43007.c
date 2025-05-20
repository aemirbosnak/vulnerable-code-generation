//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: expert-level
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int CompareWords(const void* a, const void* b) {
    WordCount* wordA = (WordCount*)a;
    WordCount* wordB = (WordCount*)b;

    return strcmp(wordA->word, wordB->word);
}

void ReadWordsFromFile(char* fileName, WordCount* words, int* numWords) {
    FILE* file = fopen(fileName, "r");
    char line[MAX_FILE_NAME];
    char* word = NULL;
    int wordLength = 0;

    if (file == NULL) {
        printf("Error: could not open file %s\n", fileName);
        exit(1);
    }

    *numWords = 0;
    while (fgets(line, MAX_FILE_NAME, file)!= NULL) {
        word = strtok(line, ",.;:!?");
        while (word!= NULL) {
            wordLength = strlen(word);
            if (wordLength > MAX_WORD_LENGTH) {
                printf("Error: word '%s' is too long\n", word);
                exit(1);
            }
            strcpy(words[*numWords].word, word);
            words[*numWords].count = 1;
            (*numWords)++;

            word = strtok(NULL, ",.;:!?");
        }
    }

    fclose(file);
}

void SortWords(WordCount* words, int numWords) {
    qsort(words, numWords, sizeof(WordCount), CompareWords);
}

void PrintTopWords(WordCount* words, int numWords, int numTopWords) {
    int i;

    for (i = 0; i < numTopWords && i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char fileName[MAX_FILE_NAME];
    strcpy(fileName, argv[1]);

    WordCount words[MAX_WORD_LENGTH];
    int numWords = 0;

    ReadWordsFromFile(fileName, words, &numWords);
    SortWords(words, numWords);
    PrintTopWords(words, numWords, 10);

    return 0;
}