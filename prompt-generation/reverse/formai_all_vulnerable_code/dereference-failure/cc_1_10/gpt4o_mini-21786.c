//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

// Structure to hold word frequencies
typedef struct {
    char *word;
    int count;
} WordEntry;

WordEntry wordList[MAX_WORDS];
int wordCount = 0;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int findWord(char *word) {
    for (int i = 0; i < wordCount; i++) {
        if (strcmp(wordList[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

void addWord(char *word) {
    int index = findWord(word);

    if (index != -1) {
        wordList[index].count++;
    } else {
        if (wordCount < MAX_WORDS) {
            wordList[wordCount].word = malloc((strlen(word) + 1) * sizeof(char));
            strcpy(wordList[wordCount].word, word);
            wordList[wordCount].count = 1;
            wordCount++;
        } else {
            printf("Max word count reached! Cannot add more words.\n");
        }
    }
}

void processText(FILE *file) {
    char buffer[1024];
    char word[MAX_WORD_LENGTH];
    
    while (fgets(buffer, sizeof(buffer), file)) {
        char *ptr = buffer;
        // Process each word
        while (sscanf(ptr, " %99s", word) == 1) {
            toLowerCase(word);
            addWord(word);
            ptr += strlen(word);
        }
    }
}

void printWordList() {
    printf("\nWord Count Summary:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordList[i].word, wordList[i].count);
    }
}

void freeMemory() {
    for (int i = 0; i < wordCount; i++) {
        free(wordList[i].word);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    processText(file);
    fclose(file);

    printWordList();
    freeMemory();

    return 0;
}