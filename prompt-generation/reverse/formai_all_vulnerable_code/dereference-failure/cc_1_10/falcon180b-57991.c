//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

// Function to count the number of words in a sentence
int countWords(char *sentence) {
    int i, j, wordCount = 0;
    char word[MAX_WORD_LENGTH];

    // Remove any leading/trailing spaces
    while (isspace(*sentence)) {
        sentence++;
    }
    while (isspace(*(sentence + strlen(sentence) - 1))) {
        sentence[strlen(sentence) - 1] = '\0';
    }

    // Count the number of words in the sentence
    for (i = 0; i < strlen(sentence); i++) {
        if (isspace(sentence[i])) {
            word[j] = '\0';
            if (strlen(word) > 0) {
                wordCount++;
            }
            j = 0;
        } else {
            word[j] = sentence[i];
            j++;
        }
    }

    // Add the last word if it's not empty
    if (strlen(word) > 0) {
        wordCount++;
    }

    return wordCount;
}

int main() {
    char sentence[1000];

    // Prompt user to enter a sentence
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Count the number of words in the sentence
    int wordCount = countWords(sentence);

    // Print the result
    printf("The sentence '%s' contains %d words.\n", sentence, wordCount);

    return 0;
}