//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 256

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    char filename[MAX_FILE_NAME_LENGTH];
    strcpy(filename, argv[1]);
    char* extension = strrchr(filename, '.');
    if (extension == NULL) {
        printf("Error: Invalid file extension\n");
        fclose(inputFile);
        return 1;
    }

    if (strcmp(extension, ".txt")!= 0) {
        printf("Error: Unsupported file extension\n");
        fclose(inputFile);
        return 1;
    }

    char sentence[MAX_SENTENCE_LENGTH];
    WordCount wordCounts[MAX_WORD_LENGTH];
    int numWords = 0;

    while (fgets(sentence, MAX_SENTENCE_LENGTH, inputFile)!= NULL) {
        char* token = strtok(sentence, ",.?!;:");
        while (token!= NULL) {
            int wordLength = strlen(token);
            if (wordLength > 0 && wordLength <= MAX_WORD_LENGTH) {
                char* newWord = malloc(wordLength + 1);
                strcpy(newWord, token);
                for (int i = 0; i < wordLength; i++) {
                    if (!isalpha(newWord[i])) {
                        newWord[i] = '\0';
                        wordLength = i;
                        break;
                    }
                }
                int index = 0;
                while (index < numWords && strcmp(wordCounts[index].word, newWord)!= 0) {
                    index++;
                }
                if (index == numWords) {
                    numWords++;
                    strcpy(wordCounts[index].word, newWord);
                    wordCounts[index].count = 1;
                } else {
                    wordCounts[index].count++;
                }
            }
            token = strtok(NULL, ",.?!;:");
        }
    }

    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    fclose(inputFile);
    return 0;
}