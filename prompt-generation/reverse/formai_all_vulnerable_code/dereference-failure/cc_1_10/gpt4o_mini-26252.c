//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000

// Function prototypes
void translateSentence(char *sentence, int index, char *translatedSentence);
char* translateWord(char *word);

// Recursive function to translate a sentence
void translateSentence(char *sentence, int index, char *translatedSentence) {
    if (index < strlen(sentence)) {
        char word[MAX_WORD_LENGTH];
        int wordIndex = 0;

        // Extract a word from the sentence
        while (index < strlen(sentence) && !isspace(sentence[index])) {
            word[wordIndex++] = sentence[index++];
        }
        word[wordIndex] = '\0';

        // Translate the current word
        char *translatedWord = translateWord(word);
        strcat(translatedSentence, translatedWord);
        free(translatedWord);

        // Add a space if there are more words to process
        if (index < strlen(sentence)) {
            strcat(translatedSentence, " ");
            translateSentence(sentence, index + 1, translatedSentence);
        }
    }
}

// Function to translate a single word into "Cat Language"
char* translateWord(char *word) {
    if (strcmp(word, "hello") == 0) {
        return strdup("meow");
    } else if (strcmp(word, "cat") == 0) {
        return strdup("kitten");
    } else if (strcmp(word, "dog") == 0) {
        return strdup("woof");
    } else if (strcmp(word, "friend") == 0) {
        return strdup("pawtner");
    } else if (strcmp(word, "play") == 0) {
        return strdup("pounce");
    } else if (strcmp(word, "food") == 0) {
        return strdup("noms");
    } else {
        // Return the word unchanged if no translation exists
        return strdup(word);
    }
}

int main(void) {
    char sentence[MAX_SENTENCE_LENGTH];
    char translatedSentence[MAX_SENTENCE_LENGTH] = ""; // Initialize an empty string

    printf("Enter a sentence to translate into Cat Language: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Remove newline character from the end of the string
    size_t len = strlen(sentence);
    if (len > 0 && sentence[len - 1] == '\n') {
        sentence[len - 1] = '\0';
    }

    translateSentence(sentence, 0, translatedSentence);
    
    printf("Translated Sentence: %s\n", translatedSentence);
    
    return 0;
}