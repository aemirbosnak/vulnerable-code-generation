//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Get the input string from the user.
    char *inputString = NULL;
    size_t inputStringLength = 0;
    printf("Enter a string: ");
    getline(&inputString, &inputStringLength, stdin);

    // Remove any leading or trailing whitespace from the input string.
    while (isspace(*inputString)) {
        inputString++;
    }
    while (isspace(inputString[strlen(inputString) - 1])) {
        inputString[strlen(inputString) - 1] = '\0';
    }

    // Tokenize the input string into an array of words.
    char **words = NULL;
    size_t numWords = 0;
    char *token = strtok(inputString, " ");
    while (token != NULL) {
        words = realloc(words, (numWords + 1) * sizeof(char *));
        words[numWords++] = token;
        token = strtok(NULL, " ");
    }

    // Count the number of occurrences of each word in the input string.
    int *wordCounts = NULL;
    wordCounts = calloc(numWords, sizeof(int));
    for (size_t i = 0; i < numWords; i++) {
        for (size_t j = 0; j < numWords; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                wordCounts[i]++;
            }
        }
    }

    // Print the word counts to the console.
    for (size_t i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i], wordCounts[i]);
    }

    // Free the memory allocated for the input string, the array of words, and the array of word counts.
    free(inputString);
    for (size_t i = 0; i < numWords; i++) {
        free(words[i]);
    }
    free(words);
    free(wordCounts);

    return 0;
}