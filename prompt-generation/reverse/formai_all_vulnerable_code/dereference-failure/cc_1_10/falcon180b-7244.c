//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000

typedef struct {
    char *word;
    int count;
} WordCount;

void generate_conspiracy_theory(int num_words) {
    srand(time(NULL));

    WordCount words[MAX_WORDS];
    int num_filled_words = 0;

    // Fill the array with random words
    for (int i = 0; i < MAX_WORDS; i++) {
        char *word = malloc(10 * sizeof(char));
        sprintf(word, "word%d", i);
        words[i].word = word;
        words[i].count = 0;
    }

    // Shuffle the array
    for (int i = 0; i < MAX_WORDS; i++) {
        int j = rand() % MAX_WORDS;
        WordCount temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }

    // Select the first num_words
    for (int i = 0; i < num_words; i++) {
        words[i].count++;
        num_filled_words++;
    }

    // Print the theory
    printf("Conspiracy Theory:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s (%d)\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    int num_words = 10;

    if (argc > 1) {
        num_words = atoi(argv[1]);
    }

    generate_conspiracy_theory(num_words);

    return 0;
}