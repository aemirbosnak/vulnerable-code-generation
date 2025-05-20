//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold English to Alien dictionary
typedef struct {
    char *english;
    char *alien;
} Dictionary;

// Prototype functions
void translateToAlien(const char *input, Dictionary *dict, int dictSize);
void printTranslation(const char *input, const char *translation);
void loadDictionary(Dictionary *dict);
void freeDictionary(Dictionary *dict, int dictSize);

int main() {
    int dictSize = 10;
    Dictionary *dict = malloc(dictSize * sizeof(Dictionary));

    // Load the predefined dictionary
    loadDictionary(dict);

    // Input word to translate
    char input[100];
    
    printf("Enter an English word to translate into Alien Language (type 'exit' to quit):\n");

    while (1) {
        printf("> ");
        scanf("%s", input);
        
        // Exit condition
        if (strcmp(input, "exit") == 0) {
            break;
        }

        // Translate and print the result
        translateToAlien(input, dict, dictSize);
    }

    // Free allocated memory
    freeDictionary(dict, dictSize);
    free(dict);
    
    return 0;
}

void loadDictionary(Dictionary *dict) {
    // Simulating a simple dictionary with English to Alien translations
    dict[0].english = "hello"; dict[0].alien = "garrv";
    dict[1].english = "friend"; dict[1].alien = "xylth";
    dict[2].english = "love"; dict[2].alien = "krunn";
    dict[3].english = "enemy"; dict[3].alien = "zorra";
    dict[4].english = "star"; dict[4].alien = "ingle";
    dict[5].english = "planet"; dict[5].alien = "bantu";
    dict[6].english = "space"; dict[6].alien = "vortax";
    dict[7].english = "earth"; dict[7].alien = "drog";
    dict[8].english = "water"; dict[8].alien = "flume";
    dict[9].english = "fire"; dict[9].alien = "azorn";
}

void translateToAlien(const char *input, Dictionary *dict, int dictSize) {
    for (int i = 0; i < dictSize; i++) {
        if (strcmp(input, dict[i].english) == 0) {
            // Print translation if found
            printTranslation(input, dict[i].alien);
            return;
        }
    }
    // In case no translation was found
    printf("No translation found for '%s'. Please try another word.\n", input);
}

void printTranslation(const char *input, const char *translation) {
    printf("'%s' in Alien Language is '%s'.\n", input, translation);
}

void freeDictionary(Dictionary *dict, int dictSize) {
    // Free memory allocated for the dictionary strings
    for (int i = 0; i < dictSize; i++) {
        free(dict[i].english);
        free(dict[i].alien);
    }
}