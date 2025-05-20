//LLAMA2-13B DATASET v1.0 Category: Audio processing ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 1024
#define MAX_WORDS 20

struct Word {
    char *text;
    int frequency;
};

struct Knight {
    char *name;
    int score;
};

void addWord(struct Word *words, int *frequencies, char *word) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].text, word) == 0) {
            words[i].frequency++;
            return;
        }
    }
    if (i == MAX_WORDS) {
        printf("Oops, too many words!\n");
        return;
    }
    words[i].text = word;
    words[i].frequency = 1;
}

void printFrequencies(struct Word *words, int *frequencies) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        printf("%s: %d\n", words[i].text, frequencies[i]);
    }
}

int main() {
    struct Word words[MAX_WORDS];
    int frequencies[MAX_WORDS];
    int i;

    // Add words to the list
    addWord(words, frequencies, "the");
    addWord(words, frequencies, "knight");
    addWord(words, frequencies, "says");
    addWord(words, frequencies, "nay");

    // Print the frequencies
    printFrequencies(words, frequencies);

    return 0;
}