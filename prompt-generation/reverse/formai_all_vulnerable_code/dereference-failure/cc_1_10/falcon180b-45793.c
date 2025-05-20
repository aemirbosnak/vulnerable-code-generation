//Falcon-180B DATASET v1.0 Category: Text processing ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    FILE *inputFile;
    char line[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    int wordCount = 0;
    WordCount wordList[MAX_WORDS];
    int i;

    // Open input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Unable to open input file.\n");
        exit(1);
    }

    // Read input file and count words
    while (fgets(line, MAX_WORD_LENGTH, inputFile)!= NULL) {
        for (i = 0; i < strlen(line); i++) {
            if (isspace(line[i])) {
                line[i] = '\0';
                if (strlen(word) > 0) {
                    strcpy(wordList[wordCount].word, word);
                    wordList[wordCount].count = 1;
                    wordCount++;
                }
                strcpy(word, "");
            } else {
                strcat(word, line[i]);
            }
        }
        if (strlen(word) > 0) {
            strcpy(wordList[wordCount].word, word);
            wordList[wordCount].count = 1;
            wordCount++;
        }
    }

    // Print word count
    for (i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordList[i].word, wordList[i].count);
    }

    // Close input file
    fclose(inputFile);
    return 0;
}