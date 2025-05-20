//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_UNIQUE_WORDS 1000

typedef struct {
    char* word;
    int count;
} WordFrequency;

WordFrequency wordFrequencies[MAX_UNIQUE_WORDS];
int uniqueWordCount = 0;

bool wordExists(const char* word) {
    for (int i = 0; i < uniqueWordCount; i++) {
        if (strcmp(wordFrequencies[i].word, word) == 0) {
            return true;
        }
    }
    return false;
}

int getWordIndex(const char* word) {
    for (int i = 0; i < uniqueWordCount; i++) {
        if (strcmp(wordFrequencies[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

void addOrUpdateWord(const char* word) {
    int index = getWordIndex(word);
    if (index != -1) {
        wordFrequencies[index].count++;
    } else {
        if (uniqueWordCount < MAX_UNIQUE_WORDS) {
            wordFrequencies[uniqueWordCount].word = malloc(strlen(word) + 1);
            strcpy(wordFrequencies[uniqueWordCount].word, word);
            wordFrequencies[uniqueWordCount].count = 1;
            uniqueWordCount++;
        } else {
            printf("Error: Maximum unique word limit reached.\n");
        }
    }
}

void printWordFrequencies() {
    printf("Word Frequencies:\n");
    for (int i = 0; i < uniqueWordCount; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }
}

void freeMemory() {
    for (int i = 0; i < uniqueWordCount; i++) {
        free(wordFrequencies[i].word);
    }
}

void processText(const char* text) {
    char word[MAX_WORD_LENGTH];
    int wordIndex = 0;
    for (const char* p = text; *p != '\0'; p++) {
        if (isalnum(*p)) {
            word[wordIndex++] = *p;
        } else {
            if (wordIndex > 0) {
                word[wordIndex] = '\0';
                addOrUpdateWord(word);
                wordIndex = 0;
            }
        }
    }
    // Check for any remaining word
    if (wordIndex > 0) {
        word[wordIndex] = '\0';
        addOrUpdateWord(word);
    }
}

int main() {
    FILE* file;
    char filename[100];
    char* buffer;
    long fileLength;

    printf("Enter the filename (with .txt extension): ");
    scanf("%s", filename);
    
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return EXIT_FAILURE;
    }

    fseek(file, 0, SEEK_END);
    fileLength = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    buffer = (char*)malloc(fileLength + 1);
    fread(buffer, 1, fileLength, file);
    buffer[fileLength] = '\0';
    
    fclose(file);

    processText(buffer);
    printWordFrequencies();

    freeMemory();
    free(buffer);
    
    return EXIT_SUCCESS;
}