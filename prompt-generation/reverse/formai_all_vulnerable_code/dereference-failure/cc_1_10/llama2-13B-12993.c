//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1024

int main() {
    char* phrase = "Hello, world!";
    char* word = "world";
    char buffer[MAX_LENGTH];
    int i, j, k;

    // Create a random word
    for (i = 0; i < 5; i++) {
        word[i] = 'a' + (rand() % 26);
    }

    // Print the original phrase
    printf("Original phrase: %s\n", phrase);

    // Print the phrase with the first word replaced
    for (j = 0; j < strlen(phrase); j++) {
        if (phrase[j] == 'H') {
            buffer[j] = word[0];
        } else {
            buffer[j] = phrase[j];
        }
    }
    printf("Phrase with first word replaced: %s\n", buffer);

    // Print the phrase with the last word replaced
    for (k = strlen(phrase) - 1; k >= 0; k--) {
        if (phrase[k] == '!') {
            buffer[k] = word[4];
        } else {
            buffer[k] = phrase[k];
        }
    }
    printf("Phrase with last word replaced: %s\n", buffer);

    // Print the phrase with random words replaced
    for (i = 0; i < 5; i++) {
        int index = rand() % strlen(phrase);
        buffer[index] = word[i];
    }
    printf("Phrase with random words replaced: %s\n", buffer);

    return 0;
}