//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define MAX_CONSPIRACY_LENGTH 100
#define MAX_CONSPIRACY_WORDS 20

typedef struct {
    char *name;
    char *description;
} ConspiracyTheory;

ConspiracyTheory *generate_conspiracy_theory(void) {
    ConspiracyTheory *conspiracy_theory = malloc(sizeof(ConspiracyTheory));
    conspiracy_theory->name = malloc(MAX_CONSPIRACY_LENGTH * sizeof(char));
    conspiracy_theory->description = malloc(MAX_CONSPIRACY_LENGTH * sizeof(char));

    // Generate a random name
    int name_length = rand() % MAX_CONSPIRACY_LENGTH + 1;
    for (int i = 0; i < name_length; i++) {
        conspiracy_theory->name[i] = rand() % 26 + 'a';
    }
    conspiracy_theory->name[name_length] = '\0';

    // Generate a random description
    int description_length = rand() % MAX_CONSPIRACY_LENGTH + 1;
    for (int i = 0; i < description_length; i++) {
        conspiracy_theory->description[i] = rand() % 26 + 'a';
    }
    conspiracy_theory->description[description_length] = '\0';

    return conspiracy_theory;
}

void print_conspiracy_theory(ConspiracyTheory *conspiracy_theory) {
    printf("Name: %s\n", conspiracy_theory->name);
    printf("Description: %s\n\n", conspiracy_theory->description);
}

int main(void) {
    srand(time(NULL));

    int num_theories = rand() % 10 + 1;
    printf("Generating %d random conspiracy theories:\n", num_theories);

    for (int i = 0; i < num_theories; i++) {
        ConspiracyTheory *conspiracy_theory = generate_conspiracy_theory();
        print_conspiracy_theory(conspiracy_theory);
        free(conspiracy_theory->name);
        free(conspiracy_theory->description);
        free(conspiracy_theory);
    }

    return 0;
}