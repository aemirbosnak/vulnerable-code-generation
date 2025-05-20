//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACIES 100
#define MAX_WORDS 20
#define MAX_WORDS_LENGTH 10

// Conspiracy theory structure
typedef struct {
    char title[MAX_WORDS * MAX_WORDS_LENGTH];
    char details[MAX_WORDS * MAX_WORDS_LENGTH * 5];
} ConspiracyTheory;

// Function prototypes
void generateRandomWords(char *words[], int numWords, int maxWordLength);
void generateConspiracyTheory(ConspiracyTheory *theory);

int main() {
    srand(time(NULL));

    ConspiracyTheory theory;
    generateConspiracyTheory(&theory);

    printf("Title: %s\n", theory.title);
    printf("Details: %s\n", theory.details);

    return 0;
}

// Generates an array of random words
void generateRandomWords(char *words[], int numWords, int maxWordLength) {
    for (int i = 0; i < numWords; i++) {
        int wordLength = rand() % maxWordLength + 1;
        words[i] = (char *)malloc((wordLength + 1) * sizeof(char));
        for (int j = 0; j < wordLength; j++) {
            words[i][j] = rand() % 26 + 'a';
        }
        words[i][wordLength] = '\0';
    }
}

// Generates a random conspiracy theory
void generateConspiracyTheory(ConspiracyTheory *theory) {
    char words[MAX_WORDS][MAX_WORDS_LENGTH];
    generateRandomWords(words, MAX_WORDS, MAX_WORDS_LENGTH);

    strcpy(theory->title, words[0]);

    int numDetails = rand() % (MAX_WORDS * MAX_WORDS_LENGTH * 5) + 1;
    for (int i = 0; i < numDetails; i++) {
        int wordIndex = rand() % MAX_WORDS;
        strcat(theory->details, words[wordIndex]);
        strcat(theory->details, " ");
    }
}