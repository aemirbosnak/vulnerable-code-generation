//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define NUM_SENTENCES 5

// Function to create a sentence
char* createSentence(int sentenceNumber) {
    char* sentence = (char*)malloc(MAX_LENGTH * sizeof(char));
    if (sentence == NULL) {
        printf("Memory allocation failed! Let’s keep going anyway!\n");
        exit(1);
    }
    
    snprintf(sentence, MAX_LENGTH, "This is sentence number %d! Wow!", sentenceNumber);
    return sentence;
}

// Function to print the sentences
void printSentences(char** sentences, int count) {
    printf("\nHere are the magical sentences:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", sentences[i]);
    }
}

// Function to free the allocated memory
void freeSentences(char** sentences, int count) {
    for (int i = 0; i < count; i++) {
        free(sentences[i]); // Free each individual sentence!
    }
    free(sentences); // Free the array that holds the sentences!
    printf("\nAll sentences have been freed into the void! What a ride!\n");
}

int main() {
    // Allocating an array of character pointers for our sentences
    char** sentences = (char**)malloc(NUM_SENTENCES * sizeof(char*));
    if (sentences == NULL) {
        printf("Memory allocation for sentences failed! Let's not give up!\n");
        return 1;  // Exit the magic carpet ride here if we fail!
    }
    
    // Dynamically create each sentence!
    for (int i = 0; i < NUM_SENTENCES; i++) {
        sentences[i] = createSentence(i + 1);
    }
    
    // Print the magical sentences
    printSentences(sentences, NUM_SENTENCES);

    // Time to set our magical sentences free!
    freeSentences(sentences, NUM_SENTENCES);

    return 0; // Everything was a blast! 🎉
}