//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to translate a word from English to Cat Language
char *translateWord(char *word) {
    char *catWord;

    // Allocate memory for the cat word
    catWord = malloc(strlen(word) + 1);

    // Copy the word to the cat word
    strcpy(catWord, word);

    // Replace all vowels with "ow"
    for (int i = 0; i < strlen(word); i++) {
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
            catWord[i] = 'o';
            catWord[i+1] = 'w';
        }
    }

    // Return the cat word
    return catWord;
}

// Function to translate a sentence from English to Cat Language
char *translateSentence(char *sentence) {
    char *catSentence;
    char *word;

    // Allocate memory for the cat sentence
    catSentence = malloc(strlen(sentence) + 1);

    // Copy the sentence to the cat sentence
    strcpy(catSentence, sentence);

    // Tokenize the sentence into words
    word = strtok(sentence, " ");

    // Translate each word and add it to the cat sentence
    while (word != NULL) {
        char *catWord = translateWord(word);
        strcat(catSentence, catWord);
        strcat(catSentence, " ");
        word = strtok(NULL, " ");
    }

    // Return the cat sentence
    return catSentence;
}

// Main function
int main() {
    // Get the English sentence from the user
    char sentence[100];
    printf("Enter an English sentence: ");
    gets(sentence);

    // Translate the sentence to Cat Language
    char *catSentence = translateSentence(sentence);

    // Print the Cat Language sentence
    printf("Cat Language sentence: %s\n", catSentence);

    // Free the memory allocated for the cat sentence
    free(catSentence);

    return 0;
}