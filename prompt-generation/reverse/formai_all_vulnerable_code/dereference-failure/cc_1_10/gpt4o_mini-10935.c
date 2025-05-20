//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_LENGTH 100
#define ALPHABET_SIZE 26

// Structure to hold thread data
typedef struct {
    char letter;
    char *translated;
} ThreadData;

// Function to translate a single letter to alien language
void *translate_to_alien(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    char alien_alphabet[ALPHABET_SIZE] = {
        '@', '#', '$', '%', '^', '&', '*', '(', ')', '!', 
        '-', '=', '+', '[', ']', '{', '}', ':', ';', '"', 
        '<', '>', '?', '/', '|', '~', '`'
    };

    if (data->letter >= 'a' && data->letter <= 'z') {
        // Convert 'a' to 'z' to index 0 to 25
        int index = data->letter - 'a';
        *data->translated = alien_alphabet[index];
    } else if (data->letter >= 'A' && data->letter <= 'Z') {
        // Convert 'A' to 'Z' to index 0 to 25
        int index = data->letter - 'A';
        *data->translated = alien_alphabet[index];
    } else {
        // Non-alphabet characters remain the same
        *data->translated = data->letter;
    }
    
    return NULL;
}

int main() {
    char input[MAX_LENGTH];
    char translated[MAX_LENGTH];
    pthread_t threads[MAX_LENGTH];
    ThreadData threadData[MAX_LENGTH];
    
    printf("Enter text to translate to Alien Language: ");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0;  // Remove newline character

    size_t len = strlen(input);
    for (size_t i = 0; i < len; i++) {
        threadData[i].letter = input[i];
        threadData[i].translated = (char *)malloc(sizeof(char));
        
        // Create a thread for each character
        if (pthread_create(&threads[i], NULL, translate_to_alien, (void *)&threadData[i]) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

    // Wait for all threads to complete
    for (size_t i = 0; i < len; i++) {
        pthread_join(threads[i], NULL);
        translated[i] = *threadData[i].translated;
        free(threadData[i].translated);  // Free allocated memory
    }
    translated[len] = '\0';  // Null-terminate the translated string

    printf("Translated text in Alien Language: %s\n", translated);

    return 0;
}