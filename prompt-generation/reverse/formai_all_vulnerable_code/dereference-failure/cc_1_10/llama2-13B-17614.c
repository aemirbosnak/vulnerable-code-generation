//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 1024

// Function to generate a random word
char *generate_word(void) {
    char word[20];
    srand(time(NULL));
    int i, j;

    for (i = 0; i < 20; i++) {
        word[i] = 'a' + (rand() % 26);
    }

    return word;
}

// Function to generate a poem
void generate_poem(char *word) {
    int i, j;
    char line[1024];

    // Create a line of the poem
    for (i = 0; i < 10; i++) {
        line[i] = word[i % 20];
    }

    // Add a random punctuation mark at the end of each line
    for (i = 0; i < 10; i++) {
        j = rand() % 3;
        if (j == 0) {
            line[i] = line[i] + ')';
        } else if (j == 1) {
            line[i] = line[i] + '!';
        } else {
            line[i] = line[i] + '?';
        }
    }

    // Print the poem
    printf("%s\n", line);
}

int main(void) {
    char *word = generate_word();
    generate_poem(word);

    return 0;
}