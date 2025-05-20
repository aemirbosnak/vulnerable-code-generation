//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>

#define BUFFER_SIZE 1024

// Function to simulate Alien language translation
void *alienLangTranslator(void *arg) {
    char *sentence = (char *) arg;
    int len = strlen(sentence);
    
    // Loop through each character
    for (int i = 0; i < len; i++) {
        char c = sentence[i];
        if (c == '-') {
            // Convert '-' to '0'
            sentence[i] = '0';
        } else {
            // Convert 'a' to 'z', 'b' to 'y'... 'z' to 'a'
            char diff = 'z' - c;
            sentence[i] = 'a' + diff;
        }
    }
    
    // Return the translated sentence
    return sentence;
}

int main() {
    char *sentence = (char *) malloc(BUFFER_SIZE * sizeof(char));
    
    // Get user input sentence
    printf("Enter a sentence in Alien language: ");
    fgets(sentence, BUFFER_SIZE, stdin);
    
    // Remove newline character from input
    if ((strlen(sentence) > 0) && (sentence[strlen(sentence)-1] == '\n')) {
        sentence[strlen(sentence)-1] = '\0';
    }
    
    // Create thread to translate sentence
    pthread_t translator_thread;
    if (pthread_create(&translator_thread, NULL, alienLangTranslator, (void *) sentence)) {
        printf("Error creating thread");
        return -1;
    }
    
    // Wait for translation to complete
    void *result;
    if (pthread_join(translator_thread, &result)) {
        printf("Error joining thread");
        return -1;
    }
    
    // Print translated sentence
    printf("Translated sentence: %s\n", (char *) result);
    
    // Free memory
    free(sentence);
    pthread_exit(NULL);
}