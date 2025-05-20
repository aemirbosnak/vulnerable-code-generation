//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to translate a single word from Alien to English
char* translateWord(char* word) {
    // Create a buffer to store the translated word
    char* translation = malloc(strlen(word) + 1);

    // Iterate over the characters in the word
    int i;
    for (i = 0; i < strlen(word); i++) {
        // Translate each character using the following rules:
        //   - 'a' -> 'z'
        //   - 'b' -> 'y'
        //   - 'c' -> 'x'
        //   - 'd' -> 'w'
        //   - 'e' -> 'v'
        //   - 'f' -> 'u'
        //   - 'g' -> 't'
        //   - 'h' -> 's'
        //   - 'i' -> 'r'
        //   - 'j' -> 'q'
        //   - 'k' -> 'p'
        //   - 'l' -> 'o'
        //   - 'm' -> 'n'
        switch (word[i]) {
            case 'a': translation[i] = 'z'; break;
            case 'b': translation[i] = 'y'; break;
            case 'c': translation[i] = 'x'; break;
            case 'd': translation[i] = 'w'; break;
            case 'e': translation[i] = 'v'; break;
            case 'f': translation[i] = 'u'; break;
            case 'g': translation[i] = 't'; break;
            case 'h': translation[i] = 's'; break;
            case 'i': translation[i] = 'r'; break;
            case 'j': translation[i] = 'q'; break;
            case 'k': translation[i] = 'p'; break;
            case 'l': translation[i] = 'o'; break;
            case 'm': translation[i] = 'n'; break;
            default: translation[i] = word[i]; break;
        }
    }

    // Add the null-terminator to the end of the translated word
    translation[i] = '\0';

    // Return the translated word
    return translation;
}

// Function to translate a sentence from Alien to English
char* translateSentence(char* sentence) {
    // Split the sentence into words
    char** words = malloc(sizeof(char*) * 100);
    int numWords = 0;
    char* word = strtok(sentence, " ");
    while (word != NULL) {
        words[numWords++] = word;
        word = strtok(NULL, " ");
    }

    // Translate each word in the sentence
    int i;
    for (i = 0; i < numWords; i++) {
        words[i] = translateWord(words[i]);
    }

    // Join the translated words back into a sentence
    char* translation = malloc(strlen(sentence) + 1);
    strcpy(translation, words[0]);
    for (i = 1; i < numWords; i++) {
        strcat(translation, " ");
        strcat(translation, words[i]);
    }

    // Free the memory allocated for the words
    for (i = 0; i < numWords; i++) {
        free(words[i]);
    }
    free(words);

    // Return the translated sentence
    return translation;
}

// Main function
int main() {
    // Get the input sentence from the user
    char sentence[100];
    printf("Enter a sentence in Alien language: ");
    gets(sentence);

    // Translate the sentence from Alien to English
    char* translation = translateSentence(sentence);

    // Print the translated sentence
    printf("Translation: %s\n", translation);

    // Free the memory allocated for the translation
    free(translation);

    return 0;
}