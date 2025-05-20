//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

typedef struct word {
    char *word;
    int count;
} word;

int main() {
    char *text = "This is a sample text with multiple words. Some words are repeated, while others are not.";
    char *words[MAX_WORDS];
    int counts[MAX_WORDS];
    int num_words = 0;

    // Tokenize the text into words
    char *token = strtok(text, " ");
    while (token != NULL) {
        // Check if the word is already in the list of words
        int found = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(token, words[i]) == 0) {
                counts[i]++;
                found = 1;
                break;
            }
        }

        // If the word is not in the list, add it
        if (!found) {
            words[num_words] = token;
            counts[num_words] = 1;
            num_words++;
        }

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Sort the words by count
    for (int i = 0; i < num_words; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (counts[i] < counts[j]) {
                char *temp_word = words[i];
                words[i] = words[j];
                words[j] = temp_word;

                int temp_count = counts[i];
                counts[i] = counts[j];
                counts[j] = temp_count;
            }
        }
    }

    // Print the word count
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i], counts[i]);
    }

    return 0;
}