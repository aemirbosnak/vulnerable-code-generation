//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for mapping English words to Alien language
typedef struct {
    char *english;
    char *alien;
} WordMapping;

// Function prototypes
void initializeDictionary(WordMapping *dictionary, int *size);
void translateSentence(const char *sentence, WordMapping *dictionary, int size);
char* toAlienLanguage(const char *word, WordMapping *dictionary, int size);

int main() {
    WordMapping dictionary[100];
    int size = 0;

    // Initialize the dictionary with some basic word mappings
    initializeDictionary(dictionary, &size);

    char sentence[256];
    printf("Enter a sentence in English: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Remove newline character if it exists
    sentence[strcspn(sentence, "\n")] = 0;

    printf("Translating to Alien Language...\n");
    translateSentence(sentence, dictionary, size);

    return 0;
}

// Function to initialize the dictionary with English to Alien translations
void initializeDictionary(WordMapping *dictionary, int *size) {
    dictionary[*size].english = "hello"; dictionary[*size].alien = "zibro";
    (*size)++;
    dictionary[*size].english = "world"; dictionary[*size].alien = "glorm";
    (*size)++;
    dictionary[*size].english = "alien"; dictionary[*size].alien = "worp";
    (*size)++;
    dictionary[*size].english = "language"; dictionary[*size].alien = "kriz";
    (*size)++;
    dictionary[*size].english = "program"; dictionary[*size].alien = "blat";
    (*size)++;
    dictionary[*size].english = "translate"; dictionary[*size].alien = "zoob";
    (*size)++;
    dictionary[*size].english = "computer"; dictionary[*size].alien = "frab";
    (*size)++;
    dictionary[*size].english = "code"; dictionary[*size].alien = "gleb";
    (*size)++;
    dictionary[*size].english = "example"; dictionary[*size].alien = "xrum";
    (*size)++;
    dictionary[*size].english = "language"; dictionary[*size].alien = "lopan";
    (*size)++;
}

// Function to translate a given sentence to Alien language
void translateSentence(const char *sentence, WordMapping *dictionary, int size) {
    char *word = strtok(strdup(sentence), " ");
    int firstWord = 1;

    while (word != NULL) {
        char *alienWord = toAlienLanguage(word, dictionary, size);
        
        if (firstWord) {
            printf("%s", alienWord);
            firstWord = 0;
        } else {
            printf(" %s", alienWord);
        }
        word = strtok(NULL, " ");
        free(alienWord); // Free the allocated memory for the translated word
    }
    printf("\n");
}

// Function to convert a single English word to Alien language
char* toAlienLanguage(const char *word, WordMapping *dictionary, int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(word, dictionary[i].english) == 0) {
            return strdup(dictionary[i].alien); // Returning a new allocated string
        }
    }
    return strdup(word); // Return the original word if no translation is found
}