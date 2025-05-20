//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000

int main(int argc, char *argv[]) {
    // Initialize variables
    char input[MAX_WORD_LENGTH];
    char *words[MAX_NUM_WORDS];
    int freq[MAX_NUM_WORDS] = {0};
    int num_words = 0;

    // Read input
    printf("Enter text: ");
    fgets(input, sizeof(input), stdin);

    // Split input into words
    char *token = strtok(input, " ");
    while (token != NULL && num_words < MAX_NUM_WORDS) {
        // Remove newline character from end of token
        if (token[strlen(token)-1] == '\n') {
            token[strlen(token)-1] = '\0';
        }
        
        // Check if word is already in array
        int found = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(token, words[i]) == 0) {
                freq[i]++;
                found = 1;
                break;
            }
        }

        // Add word to array if not found
        if (!found) {
            words[num_words] = (char *) malloc(strlen(token) + 1);
            strcpy(words[num_words], token);
            freq[num_words] = 1;
            num_words++;
        }
        
        // Get next word
        token = strtok(NULL, " ");
    }

    // Print word frequency table
    printf("\nWord frequency:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i], freq[i]);
        free(words[i]); // Free dynamically allocated memory
    }

    return 0;
}