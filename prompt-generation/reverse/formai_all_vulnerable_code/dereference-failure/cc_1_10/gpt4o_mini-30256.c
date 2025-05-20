//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 100

// Function to translate a single character to alien language
char translate_char(char ch) {
    // Simple substitution cipher
    switch (tolower(ch)) {
        case 'a': return 'z';
        case 'b': return 'y';
        case 'c': return 'x';
        case 'd': return 'w';
        case 'e': return 'v';
        case 'f': return 'u';
        case 'g': return 't';
        case 'h': return 's';
        case 'i': return 'r';
        case 'j': return 'q';
        case 'k': return 'p';
        case 'l': return 'o';
        case 'm': return 'n';
        case 'n': return 'm';
        case 'o': return 'l';
        case 'p': return 'k';
        case 'q': return 'j';
        case 'r': return 'i';
        case 's': return 'h';
        case 't': return 'g';
        case 'u': return 'f';
        case 'v': return 'e';
        case 'w': return 'd';
        case 'x': return 'c';
        case 'y': return 'b';
        case 'z': return 'a';
        default: return ch; // Non-alphabetic characters remain unchanged
    }
}

// Function to translate a given word into alien language
void translate_word(char *word, char *translation) {
    for (int i = 0; word[i] != '\0'; i++) {
        translation[i] = translate_char(word[i]);
    }
    translation[strlen(word)] = '\0'; // Null terminate the translated string
}

// Function to translate a sentence
void translate_sentence(char *sentence, char *translated_sentence) {
    char *word;
    char translation[MAX_WORD_LENGTH];
    
    // Split sentence into words and translate each
    word = strtok(sentence, " ");
    while (word != NULL) {
        translate_word(word, translation);
        strcat(translated_sentence, translation);
        strcat(translated_sentence, " "); // Add space after each translated word
        word = strtok(NULL, " ");
    }
    translated_sentence[strlen(translated_sentence) - 1] = '\0'; // Remove last space
}

// Main function
int main() {
    char sentence[MAX_WORD_LENGTH * MAX_WORDS];
    char translated_sentence[MAX_WORD_LENGTH * MAX_WORDS] = "";

    printf("Welcome to the Alien Language Translator!\n");
    printf("Enter a sentence to be translated: \n");

    // Read user input
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = 0; // Remove trailing newline

    // Perform translation
    translate_sentence(sentence, translated_sentence);

    // Output the translated sentence
    printf("Translated Sentence: %s\n", translated_sentence);

    return 0;
}