//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define POEM_SIZE 20
#define WORD_SIZE 10

void randomize_words(char words[POEM_SIZE][WORD_SIZE]);
void print_poem(char words[POEM_SIZE][WORD_SIZE]);

int main() {
    char words[POEM_SIZE][WORD_SIZE];
    int i, j;

    // Initialize the words array with random words
    for (i = 0; i < POEM_SIZE; i++) {
        for (j = 0; j < WORD_SIZE; j++) {
            words[i][j] = (char)('a' + (rand() % 26));
        }
    }

    // Randomize the order of the words
    randomize_words(words);

    // Print the poem
    print_poem(words);

    return 0;
}

void randomize_words(char words[POEM_SIZE][WORD_SIZE]) {
    int i, j, k;

    // Shuffle the words
    for (i = 0; i < POEM_SIZE; i++) {
        for (j = 0; j < POEM_SIZE; j++) {
            k = rand() % (i + 1);
            char temp = words[i][j];
            words[i][j] = words[k][j];
            words[k][j] = temp;
        }
    }
}

void print_poem(char words[POEM_SIZE][WORD_SIZE]) {
    int i;

    for (i = 0; i < POEM_SIZE; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}