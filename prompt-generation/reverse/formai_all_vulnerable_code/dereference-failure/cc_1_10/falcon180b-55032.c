//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 50

// Function to generate a random conspiracy theory
void generate_theory(char *theory) {
    const char *words[] = {"government", "aliens", "chemtrails", "illuminati", "secret", "society", "global", "elite", "new", "world", "order", "cabal", "conspiracy", "cover-up", "false", "flag", "hoax", "mind", "control", "nwo", "reptilian", "shape", "shifting", "sheeple", "truth", "whistleblower", "zionist"};
    const int num_words = sizeof(words) / sizeof(words[0]);
    int i, j, k;
    char *sentence = malloc(MAX_SENTENCE_LENGTH * sizeof(char));
    char *word;

    // Set random seed
    srand(time(NULL));

    // Fill sentence with random words
    i = rand() % num_words;
    strcpy(sentence, words[i]);
    for (j = 1; j < MAX_SENTENCE_LENGTH - strlen(sentence); j++) {
        i = rand() % num_words;
        word = words[i];
        k = strlen(sentence);
        while (k + strlen(word) + 1 > MAX_SENTENCE_LENGTH) {
            i = rand() % num_words;
            word = words[i];
        }
        strcat(sentence, " ");
        strcat(sentence, word);
    }
    strcat(sentence, ".");

    // Capitalize first letter of sentence
    sentence[0] = toupper(sentence[0]);

    // Copy sentence to theory
    strcpy(theory, sentence);

    // Free memory
    free(sentence);
}

int main() {
    char theory[MAX_SENTENCE_LENGTH + 1];
    int i;

    for (i = 0; i < 10; i++) {
        generate_theory(theory);
        printf("%s\n", theory);
    }

    return 0;
}