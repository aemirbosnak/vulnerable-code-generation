//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 256
#define ALIEN_WORD_COUNT 10

typedef struct {
    char* english;
    char* alien;
} Translation;

Translation dictionary[ALIEN_WORD_COUNT];

void initializeDictionary() {
    dictionary[0].english = "hello";
    dictionary[0].alien = "zarg";
    dictionary[1].english = "yes";
    dictionary[1].alien = "klor";
    dictionary[2].english = "no";
    dictionary[2].alien = "blarg";
    dictionary[3].english = "friend";
    dictionary[3].alien = "vlink";
    dictionary[4].english = "enemy";
    dictionary[4].alien = "gritak";
    dictionary[5].english = "water";
    dictionary[5].alien = "plux";
    dictionary[6].english = "fire";
    dictionary[6].alien = "flarn";
    dictionary[7].english = "earth";
    dictionary[7].alien = "grok";
    dictionary[8].english = "sky";
    dictionary[8].alien = "ylaru";
    dictionary[9].english = "star";
    dictionary[9].alien = "venyx";
}

void translateToAlien(const char* input, char* output) {
    char* token = strtok(input, " ");
    output[0] = '\0';  // Initialize output as an empty string

    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < ALIEN_WORD_COUNT; i++) {
            if (strcmp(token, dictionary[i].english) == 0) {
                strcat(output, dictionary[i].alien);
                strcat(output, " "); // add space after each translated word
                found = 1;
                break;
            }
        }
        if (!found) {
            strcat(output, token); // if no translation found, keep it as is
            strcat(output, " ");
        }
        token = strtok(NULL, " ");
    }
    output[strlen(output) - 1] = '\0';  // Remove trailing space
}

int main() {
    char input[MAX_INPUT_SIZE];
    char translatedOutput[MAX_INPUT_SIZE];

    initializeDictionary();
    
    printf("Welcome to the Alien Language Translator!\n");
    printf("Enter your English sentence (or type 'exit' to quit):\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_INPUT_SIZE, stdin);
        
        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            printf("Exiting the translator. Farewell, earthling!\n");
            break;
        }

        translateToAlien(input, translatedOutput);
        
        printf("In Alien Language: %s\n", translatedOutput);
    }

    return 0;
}