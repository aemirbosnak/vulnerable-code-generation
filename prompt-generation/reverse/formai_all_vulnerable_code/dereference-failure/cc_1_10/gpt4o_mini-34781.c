//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void initializeWordCount(WordCount* wc, const char* word) {
    strncpy(wc->word, word, MAX_WORD_LENGTH);
    wc->count = 1;
}

int findWord(WordCount* wcArray, int size, const char* word) {
    for(int i = 0; i < size; i++) {
        if(strcmp(wcArray[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

void toLowerCase(char* str) {
    for(int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

void processTextFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Critical Alert! Failed to open file: %s\n", filename);
        return;
    }

    WordCount words[MAX_WORDS];
    int wordIndex = 0;

    char wordBuffer[MAX_WORD_LENGTH];
    while (fscanf(file, "%99s", wordBuffer) == 1) {
        // Strip punctuations and convert to lowercase
        toLowerCase(wordBuffer);
        char* end = wordBuffer + strlen(wordBuffer) - 1;
        while(end > wordBuffer && ispunct((unsigned char)*end)) {
            *end-- = '\0';
        }
        
        // Check if the word is new or already seen
        int index = findWord(words, wordIndex, wordBuffer);
        if (index >= 0) {
            words[index].count++;
        } else {
            if (wordIndex < MAX_WORDS) {
                initializeWordCount(&words[wordIndex], wordBuffer);
                wordIndex++;
            }
        }
    }

    fclose(file);
    
    // Output the result with paranoia
    printf("Word Count Analysis - Please verify the integrity of the results!\n");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < wordIndex; i++) {
        printf("Word: \"%s\" has been counted: %d time(s)\n", words[i].word, words[i].count);
    }
    printf("----------------------------------------------------\n");
    printf("Have you double-checked that no words have been omitted? Proceed with caution!\n");
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <text_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Ensure the file existence
    FILE* testFile = fopen(argv[1], "r");
    if (!testFile) {
        fprintf(stderr, "Error: File %s does not exist! Stay alert!\n", argv[1]);
        return EXIT_FAILURE;
    }
    fclose(testFile);

    // Start processing the file with suspicion
    processTextFile(argv[1]);

    // Final reminder for potential dangers
    printf("Ensure you've checked all counts thoroughly. Trust incoming data only after validation!\n");

    return EXIT_SUCCESS;
}