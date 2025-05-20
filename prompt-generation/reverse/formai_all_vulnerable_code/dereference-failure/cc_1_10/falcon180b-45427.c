//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACIES 100
#define MAX_WORDS 100

typedef struct {
    char *name;
    char *description;
} ConspiracyTheory;

ConspiracyTheory conspiracies[MAX_CONSPIRACIES];

void generate_conspiracy_theory(int index) {
    char *nouns[MAX_WORDS];
    char *verbs[MAX_WORDS];
    char *adjectives[MAX_WORDS];
    int num_nouns = 0;
    int num_verbs = 0;
    int num_adjectives = 0;

    // Populate arrays with random words
    for (int i = 0; i < MAX_WORDS; i++) {
        char word[20];
        sprintf(word, "word%d", i);
        if (rand() % 2 == 0) {
            strcpy(nouns[num_nouns++], word);
        } else if (rand() % 3 == 0) {
            strcpy(verbs[num_verbs++], word);
        } else {
            strcpy(adjectives[num_adjectives++], word);
        }
    }

    // Generate conspiracy theory description
    char description[200];
    sprintf(description, "The %s is a %s %s orchestrated by %s.",
            adjectives[rand() % num_adjectives],
            nouns[rand() % num_nouns],
            verbs[rand() % num_verbs],
            nouns[rand() % num_nouns]);

    conspiracies[index].name = strdup(description);
    conspiracies[index].description = strdup(description);
}

int main() {
    srand(time(NULL));

    // Populate array with conspiracy theories
    for (int i = 0; i < MAX_CONSPIRACIES; i++) {
        generate_conspiracy_theory(i);
    }

    // Print random conspiracy theory
    int index = rand() % MAX_CONSPIRACIES;
    printf("Conspiracy Theory: %s\n", conspiracies[index].name);
    printf("Description: %s\n", conspiracies[index].description);

    return 0;
}