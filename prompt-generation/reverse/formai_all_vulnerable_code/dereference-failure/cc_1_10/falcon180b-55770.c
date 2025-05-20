//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY_LENGTH 100
#define MAX_CONSPIRACY_WORDS 20

typedef struct {
    char *name;
    char *description;
} ConspiracyTheory;

ConspiracyTheory generateRandomConspiracyTheory() {
    ConspiracyTheory theory;
    theory.name = (char *) malloc(MAX_CONSPIRACY_LENGTH * sizeof(char));
    theory.description = (char *) malloc(MAX_CONSPIRACY_LENGTH * sizeof(char));

    srand(time(NULL));
    int numWords = rand() % MAX_CONSPIRACY_WORDS + 1;

    for (int i = 0; i < numWords; i++) {
        char word[10];
        sprintf(word, "word%d", i);
        strcat(theory.name, word);
        strcat(theory.name, " ");
    }

    strcat(theory.name, "Theory");

    for (int i = 0; i < numWords; i++) {
        char word[10];
        sprintf(word, "word%d", i);
        strcat(theory.description, word);
        strcat(theory.description, " ");
    }

    strcat(theory.description, " is a secret plan by ");
    strcat(theory.description, theory.name);
    strcat(theory.description, " to ");

    return theory;
}

void printConspiracyTheory(ConspiracyTheory theory) {
    printf("Name: %s\n", theory.name);
    printf("Description: %s\n", theory.description);
}

int main() {
    ConspiracyTheory theory = generateRandomConspiracyTheory();
    printConspiracyTheory(theory);

    free(theory.name);
    free(theory.description);

    return 0;
}