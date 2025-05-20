//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_INPUT 256
#define MAX_OUTPUT 512

typedef struct {
    char input[MAX_INPUT];
    char output[MAX_OUTPUT];
} TranslationData;

void* translate_to_cat_language(void* arg) {
    TranslationData* data = (TranslationData*)arg;
    char* token;
    char temp_output[MAX_OUTPUT] = "";

    // Tokenize the input based on spaces
    token = strtok(data->input, " ");
    
    // Create the Cat Language translation
    while (token != NULL) {
        strcat(temp_output, token);
        strcat(temp_output, "-meow ");
        token = strtok(NULL, " ");
    }

    // Remove the trailing space
    temp_output[strlen(temp_output) - 1] = '\0';
    strcpy(data->output, temp_output);
    
    pthread_exit(NULL);
}

void request_translation(const char* input) {
    TranslationData* data = malloc(sizeof(TranslationData));
    strncpy(data->input, input, MAX_INPUT);
    data->input[MAX_INPUT - 1] = '\0'; // Ensure null-termination

    pthread_t thread;
    if (pthread_create(&thread, NULL, translate_to_cat_language, (void*)data) != 0) {
        perror("Failed to create thread");
        free(data);
        return;
    }

    pthread_join(thread, NULL); // Wait for the thread to finish
    printf("Cat Language Translation: %s\n", data->output);
    free(data); // Free the allocated memory
}

int main() {
    char input[MAX_INPUT];

    printf("Welcome to the Cat Language Translator!\n");
    printf("Enter a sentence in English (type 'exit' to quit):\n");
    
    while (1) {
        printf("> ");
        fgets(input, MAX_INPUT, stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character

        if (strcmp(input, "exit") == 0) {
            break;
        }

        request_translation(input);
    }

    printf("Goodbye!\n");
    return 0;
}