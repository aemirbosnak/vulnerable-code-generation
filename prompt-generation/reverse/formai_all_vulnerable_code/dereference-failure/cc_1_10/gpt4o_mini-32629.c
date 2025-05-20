//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT 256
#define ALIEN_WORD_PREFIX "Zykk"
#define ALIEN_WORD_SUFFIX "Xorp"

// Function to convert a single character to its "alien" equivalent
char toAlienChar(char ch) {
    if (isalpha(ch)) {
        // Transform alphabetic characters to a specific mapping
        return (ch - 'a' + 1) % 26 + 'a'; // simplistic cyclic transformation
    }
    return ch; // Non-alpha characters remain unchanged
}

// Function to convert a word to its alien language format
char* translateToAlienLanguage(char* word) {
    int len = strlen(word);
    char* alienWord = (char*)malloc(len + strlen(ALIEN_WORD_PREFIX) + strlen(ALIEN_WORD_SUFFIX) + 1);
    
    // Construct the alien word with prefix, translated word, and suffix
    sprintf(alienWord, "%s", ALIEN_WORD_PREFIX);
    for (int i = 0; i < len; i++) {
        alienWord[strlen(ALIEN_WORD_PREFIX) + i] = toAlienChar(word[i]);
    }
    strcat(alienWord, ALIEN_WORD_SUFFIX);
    return alienWord;
}

// Function to translate a sentence to alien language
void translateSentence(char* sentence) {
    char* token = strtok(sentence, " ");
    printf("Translated to Alien Language:\n");

    while (token != NULL) {
        char* alienWord = translateToAlienLanguage(token);
        printf("%s ", alienWord);
        free(alienWord); // Free the allocated memory for each word
        token = strtok(NULL, " ");
    }
    printf("\n");
}

int main() {
    char input[MAX_INPUT];
    
    printf("Welcome to the Alien Language Translator!\n");
    printf("Enter your sentence (max %d characters):\n", MAX_INPUT - 1);
    fgets(input, sizeof(input), stdin);

    // Remove newline character added by fgets
    input[strcspn(input, "\n")] = 0;

    translateSentence(input);
    return 0;
}