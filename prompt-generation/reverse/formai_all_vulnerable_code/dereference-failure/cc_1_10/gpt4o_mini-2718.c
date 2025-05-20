//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char *word;
    int count;
} WordCount;

WordCount wordCounts[MAX_WORDS];
int wordCountSize = 0;

// Function to transform text into pure frequency elixirs 
void processText(const char *text) {
    const char *ptr = text;
    char currentWord[MAX_WORD_LENGTH];
    int index = 0;

    while (*ptr) {
        if (isalpha(*ptr) || *ptr == '-') {
            currentWord[index++] = tolower(*ptr);
        } else if (index > 0) {
            currentWord[index] = '\0';
            int found = 0;

            for (int i = 0; i < wordCountSize; i++) {
                if (strcmp(wordCounts[i].word, currentWord) == 0) {
                    wordCounts[i].count++;
                    found = 1;
                    break;
                }
            }

            if (!found) {
                if (wordCountSize < MAX_WORDS) {
                    wordCounts[wordCountSize].word = malloc(strlen(currentWord) + 1);
                    strcpy(wordCounts[wordCountSize].word, currentWord);
                    wordCounts[wordCountSize].count = 1;
                    wordCountSize++;
                }
            }
            index = 0;
        }
        ptr++;
    }
}

// Function to spring words from the infinite void
void printWordCounts() {
    printf("Glistening Frequency of Words:\n");
    for (int i = 0; i < wordCountSize; i++) {
        printf("Word: '%s' - Count: %d\n", wordCounts[i].word, wordCounts[i].count);
        free(wordCounts[i].word); // Release the memory into the void
    }
}

// Surrealist Joy of Reading a File
void readTextFromFile(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (!file) {
        printf("The universe denies the existence of the file: %s\n", fileName);
        return;
    }
    
    char *textBuffer = NULL;
    size_t textSize = 0;

    textBuffer = malloc(1);
    textBuffer[0] = '\0';

    // Create a swirling vortex of words
    while (!feof(file)) {
        char line[256];
        if (fgets(line, sizeof(line), file)) {
            textSize += strlen(line);
            textBuffer = realloc(textBuffer, textSize + 1);
            strcat(textBuffer, line);
        }
    }

    fclose(file);
    processText(textBuffer);
    free(textBuffer);
}

// The Oracle’s Entry Point
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Whispers of forgotten dreams, divine the file to read!\n");
        return 1;
    }

    readTextFromFile(argv[1]);
    printWordCounts();
    
    return 0;
}