//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to translate a word into Cat Language
char* translateToCatLanguage(const char* word) {
    // Allocate memory for translated word
    size_t len = strlen(word);
    // "meow-" + word + (if length > 3 then "purr")
    size_t translationLength = 5 + len + (len > 3 ? 4 : 0);
    char* catWord = (char*)malloc(translationLength + 1); // +1 for the null terminator
    if (catWord == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Start constructing the Cat Language word
    strcpy(catWord, "meow-");
    strcat(catWord, word);
    if (len > 3) {
        strcat(catWord, "purr");
    }

    return catWord;
}

// Function to translate a sentence into Cat Language
void translateSentence(const char* sentence) {
    char* sentenceCopy = strdup(sentence);
    if (sentenceCopy == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Tokenize the sentence by spaces
    char* token = strtok(sentenceCopy, " ");
    while (token != NULL) {
        char* catWord = translateToCatLanguage(token);
        printf("%s ", catWord);
        free(catWord); // Free the allocated memory for translated word
        token = strtok(NULL, " ");
    }
    printf("\n");
    free(sentenceCopy); // Free the copy of the sentence
}

// Main function
int main() {
    char* inputSentence = (char*)malloc(256 * sizeof(char)); // Reserve space for user input
    if (inputSentence == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter a sentence to translate to Cat Language: ");
    if (fgets(inputSentence, 256, stdin) != NULL) {
        // Remove newline character if present
        size_t len = strlen(inputSentence);
        if (len > 0 && inputSentence[len - 1] == '\n') {
            inputSentence[len - 1] = '\0';
        }

        translateSentence(inputSentence);
    }

    free(inputSentence); // Freeing the input sentence memory
    return 0;
}