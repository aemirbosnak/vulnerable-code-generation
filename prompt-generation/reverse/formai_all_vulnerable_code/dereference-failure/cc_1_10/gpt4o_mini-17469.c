//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

// Alien language vocabulary mapping
const char *english_to_alien[][2] = {
    {"hello", "greetak"},
    {"world", "glabarn"},
    {"how", "zup"},
    {"are", "flonn"},
    {"you", "kiro"},
    {"friend", "blorg"},
    {"goodbye", "shlum"},
    {"yes", "yup"},
    {"no", "ni"},
    {"please", " gripto"},
    {"thank you", "blessoon"},
    {"sorry", "grimbio"},
    {"help", "womp"},
    {"love", "kruz"},
    {"food", "zorb"},
    {"water", "plonk"},
    {"happy", "zuzzle"},
    {"sad", "grumble"},
    {"angry", "floop"},
    {"music", "vroom"},
    {"dance", "twirl"},
    {"play", "snap"},
    {"game", "clash"},
    {"work", "grind"},
    {"school", "bloop"},
    {"fun", "zizzle"},
    {"space", "flim"},
    {"star", "snoof"},
};

void print_welcome_message() {
    printf("Welcome to the Alien Language Translator!\n");
    printf("Enter an English phrase for translation. Type 'exit' to quit.\n");
}

char *translate_to_alien(const char *input) {
    char *translation = malloc(MAX_LENGTH);
    if (!translation) {
        perror("Unable to allocate memory");
        exit(EXIT_FAILURE);
    }

    strcpy(translation, ""); // Initialize translation

    char *token = strtok(strdup(input), " ");
    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < sizeof(english_to_alien) / sizeof(english_to_alien[0]); i++) {
            if (strcmp(token, english_to_alien[i][0]) == 0) {
                strcat(translation, english_to_alien[i][1]);
                strcat(translation, " "); // Add space after translated word
                found = 1;
                break;
            }
        }
        if (!found) {
            strcat(translation, token);
            strcat(translation, " "); // Keep the original word if not found
        }
        token = strtok(NULL, " ");
    }
    
    return translation;
}

int main() {
    char input[MAX_LENGTH];

    print_welcome_message();

    while (1) {
        printf("You: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character

        if (strcmp(input, "exit") == 0) {
            printf("Exiting the translator. Farewell!\n");
            break;
        }

        char *translation = translate_to_alien(input);
        printf("Alien Translation: %s\n", translation);
        free(translation); // Free allocated memory
    }

    return 0;
}