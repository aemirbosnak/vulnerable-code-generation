//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 1024

// Function to generate a random word
char *generate_random_word(void) {
    char word[10];
    srand(time(NULL));
    int i;

    for (i = 0; i < 10; i++) {
        word[i] = 'a' + (rand() % 26);
    }

    return word;
}

int main(void) {
    char *word1, *word2, *word3;
    int i, j, k;

    // Generate three random words
    word1 = generate_random_word();
    word2 = generate_random_word();
    word3 = generate_random_word();

    // Print the three words in a random order
    for (i = 0; i < 3; i++) {
        printf("%s\n", word1 + (rand() % strlen(word1)));
        word1 = word2;
        word2 = word3;
        word3 = word1;
    }

    // Print the three words in a circular order
    for (i = 0; i < 3; i++) {
        printf("%s\n", word1 + (rand() % strlen(word1)));
        word1 = word2;
        word2 = word3;
        word3 = word1;
    }

    // Print the three words in a zigzag order
    for (i = 0; i < 3; i++) {
        printf("%s\n", word1 + (rand() % strlen(word1)));
        if (i % 2 == 0) {
            word1 = word2;
        } else {
            word1 = word3;
        }
        word2 = word3;
        word3 = word1;
    }

    return 0;
}