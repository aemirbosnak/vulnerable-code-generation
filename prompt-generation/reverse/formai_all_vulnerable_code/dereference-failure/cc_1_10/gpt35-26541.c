//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: introspective
#include <stdio.h>
#include <string.h>

// Define alien language dictionary
const char* alienWords[5][2] = {
    {"yap", "hello"},
    {"uptya", "goodbye"},
    {"chwaa", "thank you"},
    {"shtaal", "please"},
    {"tyuup", "help"}
};

/**
 * Function to translate given alien word to English
 * If the word is not found in the dictionary, return error message
 * @param word alien word to be translated
 * @return corresponding English word or error message
 */
const char* translate(const char* word) {
    int i;
    for (i = 0; i < 5; i++) {
        if (strcmp(word, alienWords[i][0]) == 0) {
            return alienWords[i][1];
        }
    }
    return "Error: Word not found in dictionary";
}

// main function to test the translator
int main() {
    // Example sentences in alien language
    const char* sentence1 = "yap, uptya";
    const char* sentence2 = "chwaa, tyuup";
    const char* sentence3 = "shtaal";

    // Pointer to store tokenized words
    char* token;

    // Tokenize and translate first sentence
    token = strtok(sentence1, ", ");
    while (token != NULL) {
        printf("%s ", translate(token));
        token = strtok(NULL, ", ");
    }
    printf("\n");

    // Tokenize and translate second sentence
    token = strtok(sentence2, ", ");
    while (token != NULL) {
        printf("%s ", translate(token));
        token = strtok(NULL, ", ");
    }
    printf("\n");

    // Tokenize and translate third sentence
    token = strtok(sentence3, ", ");
    while (token != NULL) {
        printf("%s ", translate(token));
        token = strtok(NULL, ", ");
    }
    printf("\n");

    return 0;
}